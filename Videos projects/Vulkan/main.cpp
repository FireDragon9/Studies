#include "first_app.hpp"

//std
#include <exception>
#include <cstdlib>
#include <iostream>

int main (int argc, char *argv[]) {
  
  lve::FirstApp app{};

  try{
    app.run();
  }catch (const std::exception &e){
    std::cout << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
