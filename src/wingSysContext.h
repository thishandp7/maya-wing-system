#pragma once

#include <maya/M3dView.h>
#include <maya/MPxContext.h>
#include <maya/MGlobal.h>

class WingSysContext : public MPxContext
{
public:
	WingSysContext();
	virtual ~WingSysContext();

	virtual void toolOnSetup(MEvent& event);

	virtual MStatus doPress(
		MEvent& event, 
		MHWRender::MUIDrawManager& drawMgr, 
		const MHWRender::MFrameContext& context
	) override;

	virtual MStatus doRelease(
		MEvent& event, 
		MHWRender::MUIDrawManager& drawMgr, 
		const MHWRender::MFrameContext& context
	) override;

	virtual MStatus doDrag(
		MEvent& event, 
		MHWRender::MUIDrawManager& drawMgr, 
		const MHWRender::MFrameContext& context
	) override;

private:
	short start_x, start_y;
	short last_x, last_y;

	MGlobal::ListAdjustment listAdjustment;
	M3dView view;
};