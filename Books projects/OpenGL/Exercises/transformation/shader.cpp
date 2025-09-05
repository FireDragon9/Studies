#include "shader.h"
#include "include.hpp"

#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Shader::Shader(const char* vPath, const char* fPath){

  
  string vCode, fCode;
  fstream vFile, fFile;
  const char* vSS;
  const char* fSS; 

  
  try{

    vFile.open(vPath);
    fFile.open(fPath);

    stringstream vStream, fStream;

    vStream << vFile.rdbuf();
    fStream << fFile.rdbuf();

    vFile.close();
    fFile.close();

    vCode = vStream.str();
    fCode = fStream.str();

    vSS = vCode.c_str();
    fSS = fCode.c_str();

  }catch(ifstream::failure e){
    cout << "Failed to read file.";
    return;
  }

  unsigned int vertex, frag;
  int success;
  char infoLog[512];

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vSS, nullptr);
  glCompileShader(vertex);

  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

  if(!success){

    glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
    cout << "VERTEX COMPILATION FAILED::    " << infoLog << endl;

  }

  frag =  glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(frag, 1, &fSS, nullptr);
  glCompileShader(frag);

  glGetShaderiv(frag, GL_COMPILE_STATUS, &success);

  if (!success){
    glGetShaderInfoLog(frag, 512, nullptr, infoLog);
    cout << "FRAG COMPILATION FAILED::    " << infoLog << endl;
  }


  id = glCreateProgram();

  glAttachShader(id, vertex);
  glAttachShader(id, frag);

  glLinkProgram(id);

  glGetProgramiv(id, GL_LINK_STATUS, &success);

  if (!success){
    glGetProgramInfoLog(id, 512, nullptr, infoLog);
    cout << "ERROR LINKING PROGRAM::    " << infoLog << endl;;
  }

  glDeleteShader(vertex);
  glDeleteShader(frag);

}//constructor 


void Shader::run(){
  glUseProgram(id);
}
