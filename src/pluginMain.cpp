#include <maya/MFnPlugin.h>

#include "wingSys.h"

MStatus initializePlugin(MObject obj)
{
	MFnPlugin fnPlugin(obj, "thishandp7", "4.5", "Any");

	CHECK_MSTATUS(fnPlugin.registerContextCommand("wingSystem", WingSys::creator));

	MGlobal::executeCommand("wingSystem wingSystem1;");

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
	MFnPlugin fnPlugin(obj);

	CHECK_MSTATUS(fnPlugin.deregisterContextCommand("wingSystem"));

	return MS::kSuccess;
}