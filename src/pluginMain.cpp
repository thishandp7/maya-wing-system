#include <maya/MFnPlugin.h>

#include "createWingContextCommand.h"
#include "createLocatorToolCommand.h"

MStatus initializePlugin(MObject obj)
{
	MFnPlugin fnPlugin(obj, "thishandp7", "4.5", "Any");

	CHECK_MSTATUS(fnPlugin.registerContextCommand("createWingContextCommand", 
		CreateWingContextCommand::creator,
		"createWingTool",
		CreateLocatorToolCommand::creator
	));

	MGlobal::executeCommand("createWingContextCommand createWingContextCommand;");

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
	MFnPlugin fnPlugin(obj);

	CHECK_MSTATUS(fnPlugin.deregisterContextCommand("createWingContextCommand"));

	return MS::kSuccess;
}