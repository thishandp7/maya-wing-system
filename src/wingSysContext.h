#pragma once

#include <maya/MPxContext.h>

class WingSysContext : public MPxContext
{
public:
	WingSysContext();
	~WingSysContext();

	MStatus doPress(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
	MStatus doRelease(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
	MStatus doDrag(MEvent& event, MHWRender::MUIDrawManager& drawMgr, const MHWRender::MFrameContext& context) override;
};