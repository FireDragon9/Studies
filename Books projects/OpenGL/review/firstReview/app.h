#ifndef APP_H
#define APP_H
#pragma ONCE
#include "shader.h"
#include <GLFW/glfw3.h>


class app{

  private:
    GLFWwindow* window;

  public:
    app();
    
    void run();

};


#endif
