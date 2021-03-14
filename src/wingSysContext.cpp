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
}

MStatus WingSysContext::doPress(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context)
{
	cout << "Button pressed!" << endl;
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
