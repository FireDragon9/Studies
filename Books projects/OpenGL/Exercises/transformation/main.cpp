#include "app.h"


#include <exception>
#include <iostream>

int main (int argc, char *argv[]) {
  
  app myApp(800, 600, "Transformation Exercises");

  try{
      
      myApp.run();

  }catch(std::exception e){
    std::cout << "ERROR:    " << e.what() << std::endl;
  } 


  return 0;
}
