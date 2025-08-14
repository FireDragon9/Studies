#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <time.h>

int main(int argc, char *argv[]) {

  const int p1 = 0, p2 = 1, p3 = 2, p4 = 3;

  srand((unsigned)time(NULL));

  int number = (rand() % 100);

  std::cout << number << std::endl;

  int result = number % 4;

  switch (result) {

  case p1:

    std::cout << "Player 1 will go first.\n";
    break;

  case p2:
    std::cout << "Player 2 will go first. \n";
    break;

  case p3:
    std::cout << "Player 3 will go first. \n";
    break;
  case p4:
    std::cout << "Player 4 will go first. \n";
    break;
  }
  return 0;
} // main
