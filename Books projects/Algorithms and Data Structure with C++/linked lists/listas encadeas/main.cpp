#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

typedef struct celula celula;
struct celula{
  int   conteudo;
  celula* prox;
};

void imprime(celula *le){

  if (le != NULL){
    printf("%d\n", le->conteudo);
    imprime(le->prox);
  }

}//void imprime 

int main (int argc, char *argv[]) {

  celula c;
  celula *p;

  c.conteudo = 1;

  imprime(&c);

  return 0;
}
