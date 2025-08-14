#ifndef APP_H
#define APP_H

#include "include.hpp"
#include "shader.h"

class app{

  private:

    GLFWwindow* window;


  public: 

    app(unsigned int w, unsigned int h, const char* appName);
    void run();

};

#endif
