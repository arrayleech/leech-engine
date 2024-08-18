#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char*        WINDOW_TITLE  = "Leech Engine";

// Shader Source Codes
const char* vertexShaderSource =
  "#version 330 core\n"
  "layout (location = 0) in vec3 aPos;\n"
  "layout (location = 1) in vec3 aCol;\n"
  "out vec3 vertCol;\n"
  "void main()\n"
  "{\n"
  "  vertCol = aCol;\n"
  "  gl_Position = vec4(aPos, 1.f);\n"
  "}\0";
const char* fragmentShaderSource =
  "#version 330 core\n"
  "in vec3 vertCol;\n"
  "out vec4 FragColor;\n"
  "void main()\n"
  "{\n"
  "  FragColor = vec4(vertCol, 1.f);\n"
  "}\0";

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

  // Vertex and Fragment Shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  // Info Log
  int success = 0;
  char infoLog[256];

  // Validating the Vertex Shader
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 256, NULL, infoLog);
    fprintf(stderr, "Failed to compile the vertex shader!\n");
    fprintf(stderr, "Error:\n%s", infoLog);
  }

  // Validating the Fragment Shader
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 256, NULL, infoLog);
    fprintf(stderr, "Failed to compile the fragment shader!\n");
    fprintf(stderr, "Error:\n%s", infoLog);
  }

  // Shader Program
  GLuint shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  // Validating the Shader Program
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(shaderProgram, 256, NULL, infoLog);
    fprintf(stderr, "Failed to link the shader program!\n");
    fprintf(stderr, "Error:\n%s", infoLog);
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  printf("Leech Engine\n");

  // Main Loop
  while (!glfwWindowShouldClose(glfwWindow))
  {
    glfwPollEvents();
    glUseProgram(shaderProgram);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(glfwWindow);
  }

  glDeleteProgram(shaderProgram);
  glfwDestroyWindow(glfwWindow);
  glfwTerminate();
  return EXIT_SUCCESS;
}
