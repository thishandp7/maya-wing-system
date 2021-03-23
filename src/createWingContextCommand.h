#pragma once

#include <maya/MPxContextCommand.h>
#include "createWingContext.h"

class CreateWingContextCommand: public MPxContextCommand
{
public:
	CreateWingContextCommand();
	virtual ~CreateWingContextCommand();

	static void* creator();

	virtual MStatus doEditFlags();
	virtual MStatus doQueryFlags();
	virtual MStatus appendSyntax();
	virtual MPxContext* makeObj() override;

protected:
	CreateWingContext* createWingContext;
};