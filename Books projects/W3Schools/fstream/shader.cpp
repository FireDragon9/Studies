#include "shader.h"


Shader::Shader(const char* vPath, const char* fPath){

  ifstream vFile, fFile;
  stringstream vShaderCode, fShaderCode;
  string vCode; 
  string fCode;


  vFile.open(vPath);
  fFile.open(fPath);

  vShaderCode << vFile.rdbuf();
  fShaderCode << fFile.rdbuf();
  
  vFile.close();
  fFile.close();

  vCode = vShaderCode.str();
  fCode = fShaderCode.str();

  const char* vertex = vCode.c_str();
  const char* frag = fCode.c_str();
  


  unsigned int v = glCreateShader(GL_VERTEX_SHADER), f = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(v, 1, &vertex, nullptr);
  glCompileShader(v);

  glShaderSource(f, 1, &frag, nullptr);
  glCompileShader(f);

  ID = glCreateProgram();
  
  glAttachShader(ID, v);
  glAttachShader(ID, f);

  glLinkProgram(ID);

  glDeleteShader(v);
  glDeleteShader(f);


}

void Shader::use(){
  glUseProgram(ID);
}
