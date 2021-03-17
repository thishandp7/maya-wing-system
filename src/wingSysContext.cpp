#include "wingSysContext.h"

WingSysContext::WingSysContext()
{
	setTitleString("Wing System");
}

WingSysContext::~WingSysContext()
{
}

void WingSysContext::toolOnSetup(MEvent& event)
{
	setHelpString("Click to create locators");

	m_view = M3dView::active3dView();
}

MStatus WingSysContext::doPress(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context)
{
	short mouseX, mouseY;
	CHECK_MSTATUS (event.getPosition(mouseX, mouseY))
	cout << "Button pressed at: " << mouseX << ", " << mouseY << endl;
	CHECK_MSTATUS (getIntersectionPoint(mouseX, mouseY))

	return MS::kSuccess;
}

MStatus WingSysContext::doRelease(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context)
{
	cout << "Button released!" << endl;
	return MS::kSuccess;
}

MStatus WingSysContext::doDrag(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context)
{
	cout << "dragging!" << endl;
	return MS::kSuccess;
}

MStatus WingSysContext::getIntersectionPoint(short mouseX, short mouseY)
{
	MPoint nearClip;
	MPoint farClip;
	m_view.viewToWorld(mouseX, mouseY, nearClip, farClip);

	/*
	Equation of a plane: Ax + By + Cz + D = 0
	Equation of a plane parallel to the x-z plane aka Maya's grid: y + D = 0
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

	float t_value = -(nearClip.y / farClip.y);

	float x_intersection = nearClip.x + (t_value * farClip.x);
	float z_intersection = nearClip.z + (t_value * farClip.z);

	return MS::kSuccess;
}

void WingSysContext::getClassName(MString& name) const
{
	name.set("wingSystemContext");
}

void WingSysContext::toolOffCleanup()
{
	if (m_postRenderId)
	{
		MMessage::removeCallback(m_postRenderId);
		m_postRenderId = 0;
	}
}