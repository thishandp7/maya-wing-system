#include "createWingContextCommand.h"
#include "createWingContext.h"


CreateWingContextCommand::CreateWingContextCommand()
{
	createWingContext = NULL;
}

CreateWingContextCommand::~CreateWingContextCommand()
{
}

MPxContext* CreateWingContextCommand::makeObj()
{
	createWingContext = new CreateWingContext();
	return createWingContext;
}

void* CreateWingContextCommand::creator()
{
	return new CreateWingContextCommand();
}

MStatus CreateWingContextCommand::doEditFlags()
{
	return MStatus();
}

MStatus CreateWingContextCommand::doQueryFlags()
{
	return MStatus();
}

MStatus CreateWingContextCommand::appendSyntax()
{
	return MStatus();
}
