#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>

#include <GLFW/glfw3.h>


const float W_WIDTH = 720.0f, W_HEIGHT = 640.0f;

int main (int argc, char *argv[]) {
 
  glfwInit();

  GLFWwindow* window = glfwCreateWindow(W_WIDTH, W_HEIGHT, "Text rendering", nullptr, nullptr); 

  glfwMakeContextCurrent(window);

  glewInit();

  FT_Library ft;
  FT_Face face;

  if (FT_Init_FreeType(&ft)){
    std::cout << "ERROR::FREETYPE::Could not init FreeType library\n";
    return -1;
  } 

  if(FT_New_Face(ft, "./arial.ttf", 0, &face)){
    std::cout << "ERROR FAILED TO LOAD FONT\n";
    return -1;
  }

  while(!glfwWindowShouldClose(window)){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.7f, 1.0f);

    glfwSwapBuffers(window);
    glfwPollEvents();
  };
  


  return 0;
}
