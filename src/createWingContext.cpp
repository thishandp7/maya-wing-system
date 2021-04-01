#include "createWingContext.h"

CreateWingContext::CreateWingContext()
{
	setTitleString("Create Wing");
	isControllerReady = false;
	isShoulderReady = false;
	cout << "CreateWingContext Created!" << endl;
}

CreateWingContext::~CreateWingContext()
{
}

void CreateWingContext::toolOnSetup(MEvent& event)
{
	setHelpString("Click to create locators");
	m_view = M3dView::active3dView();
}

MStatus CreateWingContext::doPress(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context)
{
	short mouseX, mouseY;
	CHECK_MSTATUS (event.getPosition(mouseX, mouseY))
	cout << "Button pressed at: " << mouseX << ", " << mouseY << endl;
	CHECK_MSTATUS (getIntersectionPoint(mouseX, mouseY))

	return MS::kSuccess;
}

MStatus CreateWingContext::doRelease(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context)
{
	//Create Locators
	if (isControllerReady) {
		return MS::kSuccess;
	}
	else if (isShoulderReady) {
		wCommand = (CreateLocatorToolCommand*)newToolCommand();
		wCommand->setClickPoint(m_clickPoint);
		wCommand->setName("controller");
		wCommand->redoIt();
		wCommand->finalize();
		controlLocatorDagPath = wCommand->getLocatorDagPath();
		isControllerReady = true;
		//create joint system
		CreateJointSystem createJointSystem(shoulderLocatorDagPath, controlLocatorDagPath);
	} else {
		wCommand = (CreateLocatorToolCommand*)newToolCommand();
		wCommand->setClickPoint(m_clickPoint);
		wCommand->setName("shoulder");
		wCommand->redoIt();
		wCommand->finalize();
		shoulderLocatorDagPath = wCommand->getLocatorDagPath();
		isShoulderReady = true;
	}

	//Force refresh viewport
	m_view.refresh(false, true);

	cout << "Button released!" << endl;

	return MS::kSuccess;
}

MStatus CreateWingContext::getIntersectionPoint(double mouseX, double mouseY)
{
	MPoint nearClip;
	MPoint farClip;
	m_view.viewToWorld(mouseX, mouseY, nearClip, farClip);

	/*
	Equation of a plane: Ax + By + Cz + D = 0
	Equation of a plane parallel to the x-z plane AKA Maya's grid: y + D = 0
	D = distance to the origin. the distance to the grid is 0
	Therefore we end up at y = 0

	Equation of a 3D line in parametric form:
	x = x1 + tx2
	y = y1 + ty2
	z = z1 + tz2

	We substitute y1 + ty2 for y and we have: y1 + ty2 = 0

	Solve for t: t = -(y1 / y2)

	substitute t and solve for x and z values in the 3D line equation  
	*/

	double t_value = -((double)nearClip.y / (double)farClip.y);

	double x_intersection = nearClip.x + (t_value * farClip.x);
	double z_intersection = nearClip.z + (t_value * farClip.z);

	m_clickPoint = MPoint(x_intersection, 0, z_intersection);

	return MS::kSuccess;
}

void CreateWingContext::toolOffCleanup()
{
	if (m_postRenderId)
	{
		MMessage::removeCallback(m_postRenderId);
		m_postRenderId = 0;
	}
	isControllerReady = false;
	isShoulderReady = false;
	cout << "Wing Context deactivated!" << endl;
}