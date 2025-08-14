#include <cstddef>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int var1;
  int *pont1 = nullptr;
  var1 = 5;
  // armazena o do var1
  pont1 = &var1;
  std::cout << "Valor da variavel através do nome: " << var1 << endl;

  // endereço do PRIMIERO byte
  // int são 4 bytes
  // ou seja, o pont1 ta mostrando o endereço do primeiro byte
  // do int var1
  // o ponteiro é int, ele pega o primeiro byte
  // ja sabendo que o resto vai ser também int
  std::cout << "Endereco armazenado no ptr: " << pont1 << endl;
  std::cout << "*Valor da variavel atraves do ponteiro: " << *pont1 << endl;

  int var2;
  // var2 = var1
  // var2 = *var1;
  // std::cout << var2 << endl;

  // var1 = 30;
  // *pont1 = 10;
  // std::cout << *pont1 <<endl;
  //

  var2 = 50;

  // pont1 = &var2;

  // std::cout << *pont1 << endl;

  // int* pont2 = nullptr;
  // std::cout << *pont2 << endl;

  // criei um espaço de int que ele vai apontar
  int *pont3 = new int;
  // atribuindo valor no espaço;
  *pont3 = 35;

  // tomar cuidado qdo for mudar
  // porque aquele espaço fica perdido
  // std::cout << *pont3 << endl;

  //*pont3 = *pont1;
  // o endereço do pont3 vai apontar pro endereço do pont1
  // deletando o valor que ficaria perdido (35)
  // pra não ocorrer vazamento de memória
  delete pont3;
  pont3 = pont1;
  std::cout << *pont3 << endl;

  return 0;
} // main
