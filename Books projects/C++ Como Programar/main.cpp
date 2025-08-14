#include <iostream>

#include "node.h"

using namespace std;

int main (int argc, char *argv[]) {
  
  /*Aloca os bytes sizeof(Node), 
   * executa o constructor Node e 
   * Atribui o endereço do novo objeto Node a newPtr*/
  //se nenhuma memoria estiver disponivel, new lança um bad_alloc
  Node* newPtr = new Node(10);

  return 0;
}
