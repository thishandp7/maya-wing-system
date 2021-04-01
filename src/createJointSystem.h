#pragma once

#include <maya/MDagPath.h>
#include <maya/MDagModifier.h>
#include <maya/MGlobal.h>
#include <maya/MFnTransform.h>
#include <maya/MVector.h>
#include <maya/MFnIkJoint.h>
#include <maya/MObjectArray.h>
#include <maya/MDagPathArray.h>

class CreateJointSystem {
public:
	CreateJointSystem(MDagPath& shoulderLocator, MDagPath& controlLocator);
	virtual ~CreateJointSystem();

private:
	void setJointTransforms(MDagPath& shoulderLocator, MDagPath& controlLocator);

	MObjectArray jointObjectArray;
	MDagModifier dagModifier;
};