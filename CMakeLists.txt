cmake_minimum_required(VERSION 2.8.12)

project(LearnOpenGL C CXX)

set(VERSION_MAJOR "1")
set(VERSION_MINOR "1")

set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")
set(VERSION_FULL "${VERSION}.${VERSION_PATCH}")
set(LIB_SUFFIX "" CACHE STRING "Takes an empty string or 64. Directory where lib will be installed: lib or lib64")

SET(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/tools/cmake ${CMAKE_MODULE_PATH})

MARK_AS_ADVANCED(EXECUTABLE_OUTPUT_PATH)
MARK_AS_ADVANCED(LIBRARY_OUTPUT_PATH)
MARK_AS_ADVANCED(CLEAR CMAKE_CXX_COMPILER)

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

#--------------------------------------------------------------------
# Compiler
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

# MESSAGE(STATUS "root: ${LearnOpenGL_INC}")