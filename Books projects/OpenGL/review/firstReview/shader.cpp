#include "shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath){
  
  //retrieve the vextex/fragment source code from filepath
  string vertexCode;
  string fragmentCode;
  ifstream vShaderFile;
  ifstream fShaderFile;

  const char* vShaderCode;
  const char *fShaderCode;

  //ensuring ifstream objects can throw excepts
  vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
  fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

  try{

    //open files 
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);

    stringstream vShaderStream, fShaderStream;
    cout << "Files opened" << endl;
    //read file buffers content into stream

    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();

    vShaderFile.close();
    fShaderFile.close();
    
    cout << "read and closes\n";

    //convert stream into string 
    vertexCode = vShaderStream.str();
    fragmentCode = fShaderStream.str();

    //convertion

    
    vShaderCode = vertexCode.c_str();
    fShaderCode = fragmentCode.c_str();




  }catch(ifstream::failure e){

    cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << endl;
    
    return;
  }//try catch 
  //Compile shaders
  unsigned int vertex, fragment;
  int success;
  char infoLog[512];

  //vertex shader 
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, nullptr);
  glCompileShader(vertex);


  //printing errors if any
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);

  if (!success){

    glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
    cout << "VERTEX COMPILATION FAILED:\n" << infoLog << endl;

  }

  //fragment shader 
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, nullptr);
  glCompileShader(fragment);

  //printing errors if any 
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

  if (!success){

    glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
    cout << "FRAGMENT COMPILATION FAILED:\n" << infoLog << endl;

  }


  //shader program 
  id = glCreateProgram();
  glAttachShader(id, vertex);
  glAttachShader(id, fragment);

  glLinkProgram(id);

  //printing linking erros if any 
  glGetProgramiv(id, GL_LINK_STATUS, &success);

  if (!success){

    glGetProgramInfoLog(id, 512, nullptr, infoLog);
    cout << "ERROR COMPILING SHADER PROGRAM:\n" << infoLog << endl;

  }

  //delete shaders after theyre linked to the program
  glDeleteShader(vertex);
  glDeleteShader(fragment);


}//constructor

void Shader::use(){
  glUseProgram(id);
}


void Shader::setBool(const std::string &name, bool value) const{
  glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const{

  glUniform1i(glGetUniformLocation(id, name.c_str()), value);

}

void Shader::setFloat(const std::string &name, float value) const{
  glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}
