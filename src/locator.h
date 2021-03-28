#pragma once

#include <maya/MDagPath.h>
#include <maya/MDagModifier.h>
#include <string>
#include <maya/MGlobal.h>
#include <maya/MFnTransform.h>
#include <maya/MVector.h>



class Locator 
{
public:
	Locator(MString name);
	virtual ~Locator();
	MStatus create(int x, int y, int z);
	MDagPath get();

private:
	MDagPath locatorDagPath;
	MDagModifier dagModifier;
	MObject locatorObject;
	MString locatorName;
};