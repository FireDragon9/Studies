#include <iostream>

class Demo {

public:
  Demo(){};
  Demo(const Demo &D) { std::cout << "COPY CONSTRUCTOR!\n"; }
};

void passByValue(Demo D) {}

void passByReference(Demo &d) {}

int main(int argc, char *argv[]) {

  Demo dog;
  Demo cat = dog; // first example

  Demo spam(cat); // second exemple

  passByValue(dog); // third example
  return 0;
}
