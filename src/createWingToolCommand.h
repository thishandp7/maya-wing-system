#pragma once

#include <maya/MPxToolCommand.h>

class CreateWingToolCommand : public MPxToolCommand
{
public:
	CreateWingToolCommand();
	virtual ~CreateWingToolCommand();
	static void* creator();

	virtual MStatus doIt(const MArgList& args);
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	bool isUndoable() const;
	virtual MStatus finalize();

	void setClickPoint(MPoint& clickPoint);

private:
	MPoint locatorPoint;
};