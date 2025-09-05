#ifndef SHADER_H
#define SHADER_H


#include "include.hpp"

#include <string>
#include <fstream>
#include <sstream>

#include <iostream>


using namespace std;
class Shader{

  public:
    //program id 
    unsigned int id;

    //constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);    

    //use active shader
    void use();

    //uniform functions
    
    void setBool(const string& name, bool value) const;
    void setInt(const string& name, int value) const;
    void setFloat(const string& name, float value) const;

}; //class shader 



#endif // !SHADER
