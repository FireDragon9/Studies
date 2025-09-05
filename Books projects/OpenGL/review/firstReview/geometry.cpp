#include "geometry.h"
#include "texLoad.h"
geometry::geometry(Shader& shader){

  float vertices[] = {

      //positions         //Color
       .5f,  .5f, 0.0f,   1.0f, 0.0f, 0.0f, 1.0f, 1.0f,    
       .5f, -.5f, 0.0f,   0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
      -.5f, -.5f, 0.0f,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
      -.5f,  .5f, 0.0f,   1.0f, 0.0f, 1.0f, 0.0f, 1.0f
    }; //vertices
   
    unsigned int indices[] = {
      0, 1, 3,
      1, 2, 3
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);


    /////TEXTURES 
        
    texLoad myTxt(shader, "./louis.png", txt1);

    //TRANSFORMATIONS
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
}//constructor

GLuint geometry::drawing(){
    
    return VAO;

}

void geometry::transform(Shader& shader, glm::vec4& vec){

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.5f, 1.0f, 0.0f)); 
    

    unsigned int transformLoc = glGetUniformLocation(shader.id, "transform");

    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

}


