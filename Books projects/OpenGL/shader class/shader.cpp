#include "shader.h"
  

Shader::Shader(const char* vertexPath, const char* fragmentPath){

  // 1. Retrieve the vertex/fragment source code from filePath
  std::string vertexCode;
  std::string fragmentCode;
  std::ifstream vShaderFile;
  std::ifstream fShaderFile;
  //ensures ifstream objects can throw exceptions
  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try{

     //openFiles
     vShaderFile.open(vertexPath);
     fShaderFile.open(fragmentPath);
     std::stringstream vShaderStream, fShaderStream;

     //read file's buffer contents into streams
     vShaderStream << vShaderFile.rdbuf();
     fShaderStream << fShaderFile.rdbuf();

     //©lose file handlers
     vShaderFile.close();
     fShaderFile.close();

     //convert stream into string 
     vertexCode = vShaderStream.str();
     fragmentCode = fShaderStream.str();


  }catch (std::ifstream::failure e){
      std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
  }//try catch 

  const char* vShaderCode = vertexCode.c_str();
  const char* fShaderCode = fragmentCode.c_str();

  std::cout << vShaderCode << std::endl;

  //2. compile shaders 
  unsigned int vertex, fragment;
  int success;
  char infoLog[512];

  //vertex shader 
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, nullptr);
  glCompileShader(vertex);

  //print compile erros if any 
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

  if (!success){

    glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION::FAILED\n" << infoLog << std::endl;

  };
  
  //fragmentShader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, nullptr);
  glCompileShader(fragment);

  //errors if any 
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

  if (!success){
    glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
    std::cout << "ERROR COMPILING FRAGMENT SHADER\n" << infoLog << std::endl;

  }

  //shader program
  ID = glCreateProgram();
  glAttachShader(ID, vertex);
  glAttachShader(ID, fragment);
  glLinkProgram(ID);

  //print linking errors if any 
  glGetProgramiv(ID, GL_LINK_STATUS, &success);

  if (!success){

    glGetProgramInfoLog(ID, 512, nullptr, infoLog);
    std::cout << "ERROR COMPILING SHADER PROGRAM\n" << infoLog << std::endl;
  }

  //delete the shaders as they're linked into our program now and no longer necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);

}//constructor 

void Shader::use(){
  glUseProgram(ID);
}


void Shader::setBool(const std::string &name, bool value) const{
  glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const{

  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);

}

void Shader::setFloat(const std::string &name, float value) const{
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
