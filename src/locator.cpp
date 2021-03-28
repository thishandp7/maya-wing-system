#include "locator.h"

Locator::Locator(MString name)
{
	MStatus status;
	locatorName = name;
	locatorObject = dagModifier.createNode("locator", MObject::kNullObj, &status);
	CHECK_MSTATUS (status);
}

Locator::~Locator()
{
}

MStatus Locator::create(int x, int y, int z)
{
	MStatus status;
	dagModifier.doIt();

	MFnDagNode fnDag(locatorObject, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	fnDag.setName(locatorName, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnDag.getPath(locatorDagPath);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MFnTransform fnLocatorTransform(locatorDagPath, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MVector locatorTranslation = fnLocatorTransform.getTranslation(MSpace::kWorld, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MVector translationVector((float)x, (float)y, (float)z);

	cout << "translationVector:: " << translationVector << endl;

	CHECK_MSTATUS(fnLocatorTransform.translateBy(translationVector, MSpace::kTransform));

	return MStatus();
}

MDagPath Locator::get()
{
	return locatorDagPath;
}
