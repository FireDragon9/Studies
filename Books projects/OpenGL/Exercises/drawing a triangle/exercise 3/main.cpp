#include <GL/glew.h>
#include <GL/gl.h>
#include <iostream>
#include <GLFW/glfw3.h>

#include "source.cpp"

int main (int argc, char *argv[]) {

  glfwInit();

  GLFWwindow* window = glfwCreateWindow(800, 600, "Exercise 3", nullptr, nullptr);

  glfwMakeContextCurrent(window);

  glewInit();

  float firstTriangle[] = {

    -0.8f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f, 
    -1.0f, -0.5f, 0.0

  };

  float secondTriangle[] = {

    0.5f, 0.5, 0.0f,
    0.0f, -0.5f, 0.0f,
    1.0f, -0.5f, 0.0

  };

  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  //firstFragmentShader
  unsigned int firstFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(firstFragmentShader, 1, &firstFragmentShaderSource, NULL);
  glCompileShader(firstFragmentShader);

  //secondFragmentShader
  unsigned int secondFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(secondFragmentShader, 1, &secondFragmentShaderSource, NULL);
  glCompileShader(secondFragmentShader);

  //firstShaderProgram
  unsigned int firstShaderProgram = glCreateProgram();


  glAttachShader(firstShaderProgram, vertexShader);
  glAttachShader(firstShaderProgram, firstFragmentShader);
  glCompileShader(firstFragmentShader);

  glLinkProgram(firstShaderProgram);

  //secodShaderProgram 
  unsigned int secondShaderProgram = glCreateProgram();

  glAttachShader(secondShaderProgram, vertexShader);
  glAttachShader(secondShaderProgram, secondFragmentShader);
  glCompileShader(secondShaderProgram);

  glLinkProgram(secondShaderProgram);

  //VBO and VAO 

  GLuint VBOs[2], VAOs[2];
  glGenVertexArrays(2, VAOs);
  glGenBuffers(2, VBOs);

  

  //first triangle 
  glBindVertexArray(VAOs[0]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  //second triangle 
  glBindVertexArray(VAOs[1]);
  glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  while(!glfwWindowShouldClose(window)){

    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(firstShaderProgram);
    glBindVertexArray(VAOs[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glUseProgram(secondShaderProgram);
    glBindVertexArray(VAOs[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(2, VAOs);
  glDeleteBuffers(2, VBOs);
  glDeleteProgram(firstShaderProgram);
  glDeleteProgram(secondShaderProgram);
  glfwDestroyWindow(window);
  glfwTerminate();


  return 0;
}
