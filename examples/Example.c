#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char*        WINDOW_TITLE  = "Leech Engine";

int main()
{
  // Initializing GLFW
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Creating the Window
  GLFWwindow* glfwWindow = glfwCreateWindow(
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE,
    NULL,
    NULL
  );
  if (glfwWindow == NULL)
  {
    fprintf(stderr, "Failed to initialize a GLFW window!\n");
    glfwTerminate();
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(glfwWindow);

  // Initializing GLEW
  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    fprintf(stderr, "Failed to initialize GLEW!\n");
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
    return EXIT_FAILURE;
  }

  // Clear Color
  GLclampf red   = 0.0f;
  GLclampf green = 0.3f;
  GLclampf blue  = 0.3f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  printf("Leech Engine\n");

  // Main Loop
  while (!glfwWindowShouldClose(glfwWindow))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(glfwWindow);
  }

  glfwDestroyWindow(glfwWindow);
  glfwTerminate();
  return EXIT_SUCCESS;
}
