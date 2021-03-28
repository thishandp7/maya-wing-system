#pragma once

#include <maya/MPxToolCommand.h>
#include <maya/MDagPath.h>
#include <maya/MPoint.h>

#include "wingLocator.h"

class CreateLocatorToolCommand: public MPxToolCommand
{
public:
	CreateLocatorToolCommand();
	virtual ~CreateLocatorToolCommand();
	static void* creator();

	virtual MStatus doIt(const MArgList& args);
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	bool isUndoable() const;
	virtual MStatus finalize();

	void setClickPoint(MPoint& clickPoint);
	MDagPath getLocatorDagPath();

private:
	MPoint locatorPoint;
	WingLocator* locator;
};