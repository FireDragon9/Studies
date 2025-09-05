#include "include.hpp"
#include "shader.h"
class geometry{

  public:
    GLuint VAO, VBO, EBO;

    geometry(Shader& shader);

    GLuint draw();

}; //class 
