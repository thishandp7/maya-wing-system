#pragma once

#include <maya/MPxContextCommand.h>

class WingSys: public MPxContextCommand
{
public:
	WingSys();
	virtual ~WingSys();

	MPxContext* makeObj() override;

	static void* creator();
	static MStatus initialize();
};