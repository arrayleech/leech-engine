# CMake Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "leech")

# Project Name
project(${PROJECT_NAME})

# Subdirectories
add_subdirectory(examples)

# Library Paths
find_path(GLEW_INCLUDE_DIR NAMES GL/glew.h HINTS ${CMAKE_SOURCE_DIR}/include)

# Libraries
message(${CMAKE_SOURCE_DIR})
find_library(GLEW_LIBRARY NAMES GLEW PATHS ${CMAKE_SOURCE_DIR}/lib NO_DEFAULT_PATH)

# Validating GLEW
if(GLEW_INCLUDE_DIR AND GLEW_LIBRARY)
  message("✓ GLEW found")
  message("  |_ ${GLEW_INCLUDE_DIR}")
  message("  |_ ${GLEW_LIBRARY}")
  set(GLEW_INCLUDE_DIRS ${GLEW_INCLUDE_DIR})
  set(GLEW_LIBRARIES ${GLEW_LIBRARY})
else()
  message(FATAL_ERROR "𐄂 GLEW not found")
endif()
