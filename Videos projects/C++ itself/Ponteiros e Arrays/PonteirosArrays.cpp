#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {

  int numeros[5];
  //  int *p;

  // pega o endereço do primeiro valor do array (numeros[0])
  //  p = numeros;
  int *p = numeros;

  *p = 10;

  // vai para a pŕoxima casa
  p++;

  *p = 50;

  p--;

  *p = 265;

  p += 2;

  *p = 11;

  p = &numeros[4];
  *p = 134;

  p = numeros + 3;
  *p = 40;

  p = numeros;

  *(p + 2) = 99231;

  std::cout << p << std::endl;

  for (int i = 0; i < 5; i++) {

    std::cout << "N[" << i << "]: " << numeros[i] << "\n"
              << "Endereco: " << &numeros << std::endl;
  }

  return 0;
}
