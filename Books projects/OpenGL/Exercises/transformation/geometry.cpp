#include "geometry.h"


geometry::geometry(Shader& shader){

  float vertices[] = {
    
    //pos                 //colors
     .5f,   1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   
     .5f,  -1.0f, 0.0f,   0.0f, 1.0f, 1.0f,
     1.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f,
     1.0f,  1.0f, 0.0f,   0.0f, 0.0f, 1.0f
  };

  int indices[] = {

    0, 1, 2,
    2, 1, 3

  };

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*(sizeof(float))));
  glEnableVertexAttribArray(1);

}//constructor

GLuint geometry::draw(){
  return VAO;
}
