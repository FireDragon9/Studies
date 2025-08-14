#include <iostream>

#include <fstream>
#include <sstream>

#include <GL/glew.h>
#include <GL/gl.h>

using namespace std;
class Shader{

  public:
    Shader(const char* vPath, const char* fPath);
    unsigned int ID;

    void use();

};
