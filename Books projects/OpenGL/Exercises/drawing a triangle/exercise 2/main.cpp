
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

#include "source.cpp"

int main (int argc, char *argv[]) {
 
  glfwInit();

  GLFWwindow* window = glfwCreateWindow(800, 600, "exercise 2", nullptr, nullptr);

  glfwMakeContextCurrent(window);

  glViewport(0, 0, 800, 600);

  glewInit();

  ////////////////////////////////////////////
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);

  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER); 
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);
  
  unsigned int shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);

  glLinkProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  
  float firstTriangle[] = {

    -0.45f, 0.5f, 1.0f,  1.0f, 0.0f, 0.0f,
    1.0f, -1.0f, 0.5f,  0.0f, 1.0f, 0.0,
    -0.45f, -0.5f, 1.0f,  0.0f, 0.0f, 1.0f,
    1.0f, 0.5f, 0.25f,   .5f, .5f, .5f

  };

  unsigned int indices[] = {

    //first triangle 
    0, 1, 2,
    0, 2, 3

  };



  GLuint VAO, VBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  //first triangle setup 
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);

  GLuint EBO;
  glGenBuffers(1, &EBO);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);





  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);
  



  while(!glfwWindowShouldClose(window)){

    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

   
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);

  glDeleteBuffers(1, &VBO);

  glDeleteProgram(shaderProgram);

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
