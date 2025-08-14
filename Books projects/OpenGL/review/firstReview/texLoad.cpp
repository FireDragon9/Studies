#include "texLoad.h"

#include "image_implementation.hpp"

texLoad::texLoad(Shader& shader, const char* imgPath, unsigned int& geoTxt){

  stbi_set_flip_vertically_on_load(true);

  glGenTextures(1, &geoTxt);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, geoTxt);

  //parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  //loading texture
  int width, height, nrChannels;
  unsigned char* data = stbi_load(imgPath, &width, &height, &nrChannels, 0);

  if(data){

    GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);

  }else{
    cout << "Texture load error.\n"; 
  }

  stbi_image_free(data);

  shader.use();
  shader.setInt("ourTex", 0);


}//constructor
