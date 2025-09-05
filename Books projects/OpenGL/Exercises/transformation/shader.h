#ifndef SHADER_H
#define SHADER_H
#pragma ONCE

#include "include.hpp"

class Shader{

    
    public:
      
      unsigned int id;

      Shader(const char* vPath, const char* fPath);

      void run();


};

#endif
