#include <GL/glew.h>
#include <GL/gl.h>

#include <GLFW/glfw3.h>


//vertexShaderSource

const char* vertexShaderSource = R"(

  #version 330 core 
  layout (location = 0) in vec3 aPos;
  layout (location = 1) in vec3 aColor;
  
  out vec3 ourColor;

  void main(){
    gl_Position = vec4(aPos.x, aPox.y,aPos.z, 1.0f);

    ourColor = aColor;
  }

)";


//fragment shader source 

const char* fragmentShaderSource = R"(

  #version 330 
  out vec4 FragColor;
  in vec3 ourColor;


  void main(){
    FragColor = vec4(ourColor, 1.0f);
  }

)";
