const char* vertexShaderSource = R"(

    #version 330 core 
    layout (location = 0) in vec3 aPos;

    void main(){
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }

)";

const char* firstFragmentShaderSource = R"(

    #version 330 core 
    out vec4 FragColor;

    void main(){
      FragColor = vec4(1.0f, 0.4f, 0.2f, 1.0f);
    }


)";

const char* secondFragmentShaderSource = R"(

  #version 330 core 
  out vec4 FragColor;

  void main(){
    FragColor = vec4(0.3f, 0.3f, 1.0f, 1.0f);
  }

)";
