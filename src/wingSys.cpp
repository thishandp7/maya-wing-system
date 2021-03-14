#include "wingSys.h"
#include "wingSysContext.h"


WingSys::WingSys()
{
}

WingSys::~WingSys()
{
}

MPxContext* WingSys::makeObj()
{
	return new WingSysContext();
}

void* WingSys::creator()
{
	return new WingSys();
}

MStatus WingSys::doEditFlags()
{
	return MStatus();
}

MStatus WingSys::doQueryFlags()
{
	return MStatus();
}

MStatus WingSys::appendSyntax()
{
	return MStatus();
}
