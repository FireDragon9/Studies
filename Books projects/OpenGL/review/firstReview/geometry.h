#include "include.hpp"

#include "shader.h"

class geometry{

  public:
    
    unsigned int txt1;
    GLuint VAO, VBO, EBO;
    geometry(Shader& shader);
    GLuint drawing();
    void transform(Shader& shader, glm::vec4& vec);

}; //class geometry
