# CMake Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "leech")

# Project Name
project(${PROJECT_NAME})

# Library Paths
find_path(GLEW_INCLUDE_DIR NAMES GL/glew.h HINTS ${CMAKE_SOURCE_DIR}/include)
find_path(GLFW_INCLUDE_DIR NAMES GLFW/glfw3.h HINTS ${CMAKE_SOURCE_DIR}/include)

# Libraries
find_library(GLEW_LIBRARY NAMES GLEW PATHS ${CMAKE_SOURCE_DIR}/lib NO_DEFAULT_PATH)
find_library(GLFW_LIBRARY NAMES glfw3 PATHS ${CMAKE_SOURCE_DIR}/lib NO_DEFAULT_PATH)

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

# Validating GLFW
if(GLFW_INCLUDE_DIR AND GLFW_LIBRARY)
  message("✓ GLFW found")
  message("  |_ ${GLFW_INCLUDE_DIR}")
  message("  |_ ${GLFW_LIBRARY}")
  set(GLFW_INCLUDE_DIRS ${GLFW_INCLUDE_DIR})
  set(GLFW_LIBRARIES ${GLFW_LIBRARY})
else()
  message(FATAL_ERROR "𐄂 GLFW not found")
endif()

# Subdirectories
add_subdirectory(examples)
