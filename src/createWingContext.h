#pragma once

#include <iostream>
#include <string>

#include <maya/M3dView.h>
#include <maya/MPxContext.h>
#include <maya/MGlobal.h>
#include <maya/MUiMessage.h>
#include <maya/MPoint.h>
#include <maya/MPxLocatorNode.h>
#include <maya/MDagPath.h>

#include "createLocatorToolCommand.h"
#include "createJointSystem.h"


class CreateWingContext : public MPxContext
{
public:
	CreateWingContext();
	virtual ~CreateWingContext();

	virtual void toolOnSetup(MEvent& event);
	virtual void toolOffCleanup();

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

	MStatus getIntersectionPoint(double mouseX, double mouseY);

private:

	M3dView			m_view;
	MCallbackId		m_postRenderId;
	MPoint			m_intersectionPoint;
	MVector			m_cameraNormal;
	MPoint			m_clickPoint;

	MDagPath shoulderLocatorDagPath;
	MDagPath controlLocatorDagPath;
	bool isControllerReady;
	bool isShoulderReady;

	CreateLocatorToolCommand* wCommand;
};