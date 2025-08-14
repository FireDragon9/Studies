#include <iostream>
#include <string>

using namespace std;

struct aluno{

  int matricula;
  string nome;
  int nota;
  aluno* proximo;

};

int main (int argc, char *argv[]) {
  
  aluno* i, *a, *p;

  a = new aluno;
  i = a;
  a->matricula = 100;
  a->nome = "Joao";
  a->nota = 85;
  a->proximo = nullptr;
  p = a;
  
  a = new aluno;
  p->proximo = a;
  a->matricula = 101;
  a->nome = "Jose";
  a->nota = 75;
  a->proximo = nullptr;
  p=a;

  a = new aluno;
  p->proximo = a;
  a->matricula = 102;
  a->nome = "Maria";
  a->nota = 90;
  a->proximo = nullptr;
  p=a;

  p = i;
  while(p != nullptr){
  
    cout << p->matricula << " / "
         << p->nome << endl; 
  
    p = p->proximo;
  
  }

  return 0;
}
