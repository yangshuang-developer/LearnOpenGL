cmake_minimum_required(VERSION 3.6.0)

project(LearnOpenGL CXX)

set(VERSION_MAJOR "1")
set(VERSION_MINOR "1")

set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/tools/cmake ${CMAKE_MODULE_PATH})

MARK_AS_ADVANCED(EXECUTABLE_OUTPUT_PATH)
MARK_AS_ADVANCED(LIBRARY_OUTPUT_PATH)
MARK_AS_ADVANCED(CLEAR CMAKE_CXX_COMPILER)

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

#--------------------------------------------------------------------
# Compiler configuration
#--------------------------------------------------------------------
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release")

#--------------------------------------------------------------------
# Output paths
#--------------------------------------------------------------------
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")

# hearder file
#--------------------------------------------------------------------
# Directories to compile
#--------------------------------------------------------------------
ADD_SUBDIRECTORY(core)
ADD_SUBDIRECTORY(libs)
ADD_SUBDIRECTORY(tutorials)
