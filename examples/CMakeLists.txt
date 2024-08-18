# Executable
add_executable(
  leech
  Example.c
)

# Linking Libraries
target_link_libraries(
  leech
  PRIVATE
  m
  GL
  ${GLEW_LIBRARIES}
  ${GLFW_LIBRARIES}
)
