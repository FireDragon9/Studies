#include "app.h"
#include "geometry.h"

app::app(unsigned int w, unsigned int h, const char* appName){

    glfwInit();
    
    window = glfwCreateWindow(w, h, appName, nullptr, nullptr);
    
    if (!window){
      cout << "ERROR CREATING WINDOW\n";
      return;
    }


    glfwMakeContextCurrent(window);

    glewInit();

}

void app::run(){

  Shader shader("vertexSS", "fragSS");
  
  geometry myGeo(shader);


  while(!glfwWindowShouldClose(window)){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glUseProgram(shader.id);
    glBindVertexArray(myGeo.draw());
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    

    glfwSwapBuffers(window);
    glfwPollEvents();

  }

  glfwTerminate();

}
