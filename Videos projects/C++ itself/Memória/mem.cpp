#include <iostream>

int main(int argc, char *argv[]) {

  // Ponteiro faz referencia a uma localização
  // Qdo pega uma informação, é DEREFERENCE

  int x = 2049;

  int *px = &x;

  printf("O tamanho de X: %d bytes\n", sizeof(x));
  printf("O endereço de X: %d\n", px);
  printf("O valor do ponteiro de px: %d\n", *px);
  printf("Soma de px+1: %d\n", *(px + 1));

  char *y = (char *)px;
  printf("O tamanho de Y: %d bytes\n", sizeof(y));

  return 0;
} // main
