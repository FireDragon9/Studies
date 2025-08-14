#include "app.h"

#include <iostream>
#include <exception>
int main (int argc, char *argv[]) {
   
  
  app myApp;

  try{
    myApp.run();
  }catch (const std::exception e){

    std::cout << "Error: " << e.what() << std::endl;

  } 


  return 0;
}
