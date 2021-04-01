#include "createJointSystem.h"

CreateJointSystem::CreateJointSystem(MDagPath& shoulderLocator, MDagPath& controlLocator)
{
	MStatus status;

	MObject shoulderJointObject = dagModifier.createNode("joint", MObject::kNullObj, &status);
	jointObjectArray.append(shoulderJointObject);
	CHECK_MSTATUS(status);

	MObject controlJointObject = dagModifier.createNode("joint", jointObjectArray[0], &status);
	jointObjectArray.append(controlJointObject);
	CHECK_MSTATUS(status);

	dagModifier.doIt();
	setJointTransforms(shoulderLocator, controlLocator);
}

CreateJointSystem::~CreateJointSystem()
{
}

void CreateJointSystem::setJointTransforms(MDagPath& shoulderLocator, MDagPath& controlLocator)
{
	MStatus status;
	MFnIkJoint fnJoint;
	MFnTransform fnLocatorTransform;

	fnJoint.setObject(jointObjectArray[0]);
	fnLocatorTransform.setObject(shoulderLocator);
	MVector shoulderLocatorTranslation = fnLocatorTransform.getTranslation(MSpace::kTransform, &status);
	CHECK_MSTATUS(status);

	status = fnJoint.setTranslation(shoulderLocatorTranslation, MSpace::kTransform);
	CHECK_MSTATUS(status);


	fnJoint.setObject(jointObjectArray[1]);
	fnLocatorTransform.setObject(controlLocator);
	MVector controlLocatorTranslation = fnLocatorTransform.getTranslation(MSpace::kTransform, &status);
	CHECK_MSTATUS(status);
	MVector adjustedOrigin = shoulderLocatorTranslation * -1;
	controlLocatorTranslation += adjustedOrigin;
	status = fnJoint.setTranslation(controlLocatorTranslation, MSpace::kTransform);
	CHECK_MSTATUS(status);
}
