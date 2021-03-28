#include "createLocatorToolCommand.h"

CreateLocatorToolCommand::CreateLocatorToolCommand()
{
	setCommandString("createWingTool");
}

CreateLocatorToolCommand::~CreateLocatorToolCommand()
{
}

void* CreateLocatorToolCommand::creator()
{
	return new CreateLocatorToolCommand;
}

MStatus CreateLocatorToolCommand::doIt(const MArgList& args)
{
	return MStatus();
}

MStatus CreateLocatorToolCommand::redoIt()
{
	locator = locatorName.length() > 0 ? locator = new Locator(locatorName) : locator = new Locator("shoulder");
	locator->create(locatorPoint.x, locatorPoint.y, locatorPoint.z);
	return MS::kSuccess;
}

MStatus CreateLocatorToolCommand::undoIt()
{
	return MStatus();
}

bool CreateLocatorToolCommand::isUndoable() const
{
	return false;
}

MStatus CreateLocatorToolCommand::finalize()
{
	return MStatus();
}

void CreateLocatorToolCommand::setClickPoint(MPoint& clickPoint)
{
	locatorPoint = clickPoint;
}

MDagPath CreateLocatorToolCommand::getLocatorDagPath()
{
	return locator->get();
}

void CreateLocatorToolCommand::setName(char* name)
{
	locatorName.set(name);
}
