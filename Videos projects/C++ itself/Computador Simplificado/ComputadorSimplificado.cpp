#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std::chrono;


int main (int argc, char *argv[]) {

  srand((unsigned) time(0));

  int ranNumb = rand() % 2101 - 100;
  int ranNumb2 = rand() % 2101 - 100;
  int myArray[16];
  int cnt = 0;

  myArray[16] = ranNumb;
  myArray[15] = ranNumb2;

  while (myArray[15] != -1) {

    cnt++;

    ranNumb2 = rand() % 2101 - 100;
    
    myArray[15] = ranNumb2;

    if(myArray[15] < myArray[16]){

      myArray[16] = myArray[15];

    }//if

    std::cout << "Just a moment! I'm thinking... the number this time was: " << myArray[15] << std::endl;

  }//while

  std::cout << "Found it! Am I a good puter? :3 I just had to try " << cnt << " times! " << std::endl;
  

  return 0;
}

