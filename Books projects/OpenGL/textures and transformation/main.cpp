#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "imageImplementation.cpp"

const char* vertexSS = R"(

  #version 330 core

  layout (location = 0) in vec3 aPos;
  layout (location = 1) in vec3 aColor;
  layout (location = 2) in vec2 aTexCoord;


  out vec3 ourColor;
  out vec2 TexCoord;

  uniform mat4 transform;

  uniform mat4 model;
  uniform mat4 view;
  uniform mat4 projection;


  void main(){
    //note that we read the multiplication from right to left
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    ourColor = aColor;
    TexCoord = aTexCoord;
  }


)";

const char* fragmentSS = R"(

  #version 330 core 

  out vec4 FragColor;

  in vec3 ourColor;
  in vec2 TexCoord;

  uniform sampler2D ourTexture;
  
  uniform sampler2D texture1;
  uniform sampler2D texture2;

  void main(){
    FragColor = mix(texture(texture1, TexCoord),
                    texture(texture2, TexCoord), 0.2);
  }

)";


int main(){

  glfwInit();

  GLFWwindow* window = glfwCreateWindow(800, 600, "textures and transformations", nullptr, nullptr);

  glfwMakeContextCurrent(window);

  glewInit();

  float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
  };

  unsigned int indices[] = {

      0, 1, 3,
      1, 2, 3

  };

  stbi_set_flip_vertically_on_load(true);

  glTexParameteri(
      GL_TEXTURE_2D, //Texture target  
      GL_TEXTURE_WRAP_S, //what option we want to set and fo which texture axis
      GL_MIRRORED_REPEAT); // texture wrapping mode

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


  int width, height, nrChannels;
  unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);

  unsigned int texture1, texture2;
  
  glGenTextures(1, &texture1);
  glGenTextures(1, &texture2);

  glActiveTexture(GL_TEXTURE0); //activate texture unit first
  glBindTexture(GL_TEXTURE_2D, texture1);


  if (data){
  glTexImage2D(
      GL_TEXTURE_2D, //means this operation will generate a texture on the currently bound texture object at the same target 
      0, //mipmap level; base level 
      GL_RGB, //what kind of format we want to store the texture 
      width,
      height, 
      0, //legacy stuff 
      GL_RGB, //format and data type of the source image...
      GL_UNSIGNED_BYTE, //want to store them as chars
      data); //actual image data 
  glGenerateMipmap(GL_TEXTURE_2D);
  }else{
    std::cout << "Failed to load texture\n";
  }

  stbi_image_free(data); 

        glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, texture2);

  data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);

  if (data){

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

  }else{
    std::cout << "Failed awesomeface\n";
  }

  stbi_image_free(data);


  unsigned int fragShader, vertexShader;
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  vertexShader = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertexShader, 1, &vertexSS, nullptr);
  glShaderSource(fragShader, 1, &fragmentSS, nullptr);

  glCompileShader(fragShader);
  glCompileShader(vertexShader);

  unsigned int shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragShader);

  glLinkProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragShader);


  GLuint VAO, VBO, EBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 *sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);


  glUseProgram(shaderProgram);
  glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 0); //manually
  glUniform1i(glGetUniformLocation(shaderProgram, "texture2"), 1);


  //transformations
  
  /*
  //we first define a vector named vec using GLM build-in vector class 
  glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
  //we define a mat4 and explicitly initialize it to the identity matrix by initializing the 
  //matrix diagonals to 1.0
  glm::mat4 trans = glm::mat4(1.0f);

  trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
  vec = trans * vec;
  */ 
  
  /*
  glm::mat4 trans = glm::mat4(1.0f);
  trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0f));
  trans = glm::scale(trans, glm::vec3(0.5, 0.5f, 0.5f));
  */


  //we first query the location of the uniform variableand then send the matrix data to the shaders 
  //unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
  
  //second tells OpenGL how many matrices we'd like to send, which is 1 
  //third argument ask us if we want to transpose our matrix, that is to swap the columns and rows
  //last parameter is the actual matrix data, but GLM stores their matriccs data in a way that doesnt 
  //always match OpenGL expectations so we first convert the data with GLM built in function value_ptr
  //glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));



  //To start drawing in 3D, we'll first create a model matrix. 
  //The Model matrix consists of translations, scaling and/or rotations we's like to apply to transform
  //all object's vertices to the global world space 



  glm::mat4 model = glm::mat4(1.0f);
  model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
  

  glm::mat4 view = glm::mat4(1.0f);
  //note that we're translating the scene in the reverse direction
  view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

  glm::mat4 projection;
  projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
  

  //Z-Buffer


  glEnable(GL_DEPTH_TEST);

  glm::vec3 cubePositions[] = {

    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 5.0f, -15.0f),
    glm::vec3(-1.5f, 2.2f, -2.5f),
    glm::vec3(-3.8f, 2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f)
  


  };

  while (!glfwWindowShouldClose(window)){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

   
    glUseProgram(shaderProgram);
   

    glBindVertexArray(VAO);

    for(unsigned int i = 0; i < 10; i++){

      glm::mat4 model = glm::mat4(1.0f);
      
      model = glm::translate(model, cubePositions[i]);

      float angle = 20.0f * i;

      model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, &model[0][0]);

      glDrawArrays(GL_TRIANGLES, 0, 36);
      
      

    }





    int modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    int viewLoc = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));


    glfwSwapBuffers(window); 
    glfwPollEvents();
  }

  return 0;
}
