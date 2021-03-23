#include "createWingToolCommand.h"

CreateWingToolCommand::CreateWingToolCommand()
{
	setCommandString("createWingTool");
	locatorPoint = NULL;
}

CreateWingToolCommand::~CreateWingToolCommand()
{
}

void* CreateWingToolCommand::creator()
{
	return new CreateWingToolCommand;
}

MStatus CreateWingToolCommand::doIt(const MArgList& args)
{
	return MStatus();
}

MStatus CreateWingToolCommand::redoIt()
{
	//Create Locators
	//Create mesh
	//Create etc.
	return MStatus();
}

MStatus CreateWingToolCommand::undoIt()
{
	return MStatus();
}

bool CreateWingToolCommand::isUndoable() const
{
	return false;
}

MStatus CreateWingToolCommand::finalize()
{
	return MStatus();
}

void CreateWingToolCommand::setClickPoint(MPoint& clickPoint)
{
	locatorPoint = clickPoint;
}
