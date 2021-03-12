cmake_minimum_required(VERSION 3.1)

include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)

set(PROJECT_NAME wing-sys)

set(SOURCE_FILES
	src/pluginMain.cpp
	src/wing.h
	src/wing.cpp
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