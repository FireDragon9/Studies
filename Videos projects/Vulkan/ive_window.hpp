#pragma once 

#include <string>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
namespace lve{

  class LveWindow{

    public:

      LveWindow(int w, int h, std::string name);
      ~LveWindow();

      LveWindow(const LveWindow &) = delete;
      LveWindow &operator=(const LveWindow &) = delete;

      bool shouldClose(){return glfwWindowShouldClose(window);}

    private:

      void iniWindow();

      const int width;
      const int height;

      std::string windowName;
      GLFWwindow *window;

    public:

  }; //class

}//lve
