#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <csignal>

#include "source.cpp"

int main (int argc, char *argv[]) {
  
  glfwInit();

  GLFWwindow* window = glfwCreateWindow(800, 600, "Revisions", nullptr, nullptr);

  glfwMakeContextCurrent(window);

  glewInit();

  float vertices[] = {

     0.0f, 1.0f, 0.0f,
    -1.0f, -1.0f, 0.0f,
     1.0f, -1.0f, 0.0f


  };

  //vertex shader 
  
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);

  glCompileShader(vertexShader);

  //fragment shader 

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);


  //shader program 

  unsigned int shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  glCompileShader(shaderProgram);
  glLinkProgram(shaderProgram);


  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  GLuint VBO, VAO;

  //VBO 
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  //VAO 
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);


  while(!glfwWindowShouldClose(window)){

    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    glBindVertexArray(VAO);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindVertexArray(0);

    glfwSwapBuffers(window);
    glfwPollEvents();

  }


  glfwTerminate();

  return 0;
}
