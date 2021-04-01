cmake_minimum_required(VERSION 3.1)

include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)

set(PROJECT_NAME wing-sys)

set(SOURCE_FILES
	src/createJointSystem.cpp
	src/createJointSystem.h
	src/createLocatorToolCommand.cpp
	src/createLocatorToolCommand.h
	src/createWingContext.cpp
	src/createWingContext.h
	src/createWingContextCommand.cpp
	src/createWingContextCommand.h
	src/locator.cpp
	src/locator.h
	src/pluginMain.cpp
)


set(LIBRARIES 
	OpenMaya 
	Foundation
	OpenMayaAnim
	OpenMayaUI
	OpenMayaRender
)

find_opengl()
build_plugin()