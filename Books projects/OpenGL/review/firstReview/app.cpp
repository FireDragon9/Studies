#include "include.hpp"

#include "app.h"

#include "geometry.h"
#include <GLFW/glfw3.h>

app::app(){

    glfwInit();
    window = glfwCreateWindow(800, 600, "Reviewing", nullptr, nullptr);

    glfwMakeContextCurrent(window); 

    glewInit();

}

void app::run(){

  Shader shader("vertexSS.txt", "fragSS.txt");

  geometry myGeometry(shader);

std::cout << glGetString(GL_VERSION) << std::endl;

  while(!glfwWindowShouldClose(window)){
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, myGeometry.txt1); 
    

    shader.use();
    glBindVertexArray(myGeometry.drawing());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


    glfwSwapBuffers(window);
    glfwPollEvents();
    

  } //while
 
  glfwTerminate();

}//app run
