#pragma once

#include <maya/MPxContextCommand.h>
#include "wingSysContext.h"

class WingSys: public MPxContextCommand
{
public:
	WingSys();
	virtual ~WingSys();

	static void* creator();

	virtual MStatus doEditFlags();
	virtual MStatus doQueryFlags();
	virtual MStatus appendSyntax();
	virtual MPxContext* makeObj() override;

protected:
	WingSysContext* wingSysContext;
};