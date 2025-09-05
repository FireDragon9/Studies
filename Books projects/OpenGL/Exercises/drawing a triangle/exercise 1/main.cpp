#include "include.cpp"
#include <GL/gl.h>
#include <iostream>

int main (int argc, char *argv[]) {
  
  glfwInit();

  const int WIDTH = 800;
  const int HEIGTH = 600;

  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGTH, "Exercise 1", nullptr, nullptr); 

  if (!window){
    std::cout << "Failed to create window" << std::endl;
     return -1;
  }

  glfwMakeContextCurrent(window);

  glewInit();

  glViewport(0, 0, WIDTH, HEIGTH);

  //////////////////////////////////////////

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);

  //fragmentShader
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);

  unsigned int shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);


  ///////////////////////////////////////////

  float vertices[] = {

    //first triangle
    -0.45f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 
    -0.8f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    -0.1f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f

  };

  GLuint VBO, VAO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  //bind vertex array object first, then bind and set vertex buffers and then configure vertex attributes

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  //position attributes 
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  //color attribute 
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);


  glUseProgram(shaderProgram);

  ////////////////////////////////////////////


  while (!glfwWindowShouldClose(window)){

    glClear(GL_COLOR_BUFFER_BIT);
   


    glUseProgram(shaderProgram);

    glBindVertexArray(VAO);
    
    glDrawArrays(GL_TRIANGLES, 0, 6);
  

    glfwSwapBuffers(window);
    glfwPollEvents();
  }//while glfwWindowShouldClose

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}//main
