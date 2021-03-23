#pragma once

#include <maya/M3dView.h>
#include <maya/MPxContext.h>
#include <maya/MGlobal.h>
#include <maya/MUiMessage.h>
#include <maya/MPoint.h>
#include <maya/MPxLocatorNode.h>


class CreateWingContext : public MPxContext
{
public:
	CreateWingContext();
	virtual ~CreateWingContext();

	virtual void toolOnSetup(MEvent& event);
	virtual void toolOffCleanup();
	virtual void getClassName(MString& name) const;

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

	MStatus getIntersectionPoint(short mouseX, short mouseY);

private:

	M3dView			m_view;
	MCallbackId		m_postRenderId;
	MPoint			m_intersectionPoint;
	MVector			m_cameraNormal;
	MPoint			m_clickPoint;
};