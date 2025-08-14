#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

//O(N) --> ou seja, linear
bool exemplo1(vector<int> v, int X){

  int tamanho = v.size(); //O(1) pois é constante 

  for(int i=0; i < tamanho; i++){ //O(N) N = tamanho do vetor 

      if (v[i] == X) return true; //O(1) constante 

  }
  return false; //O(1)  constante 
}

//O(N) * O(N) ----> O(N²)

bool exemplo2(vector<int>v){

  int tamanho = v.size();

  for(int i=0; i<tamanho; i++){ //O(N)

    for(int j = 0; j<tamanho; j++){//O(N)

      if(i != j && v[i] == v[j]) return true;

    }

  }

  return false;

}

//O(N) * O(N) + O(N) + O(N)

//O(N²) + 2*O(N)

//O(N²) + O(N)

//O(N²)


int exemplo3(vector<int>v){

  int tamanho = v.size();
  int bla = 0;

  for(int i = 0; i<tamanho; i++){ //O(N)

    for(int j=0; j<tamanho; j++){//O(N)
      if (v[i] == v[j]) bla++;
    }

  }//for 

  //

  int ble = 0;

  for(int i=0; i<tamanho; i++){//O(N)

    if(v[i] == 10){
      ble = 2*ble;
    }

  }
 
  int bli = 0;

  for(int i=0; i<tamanho; i++){ //O(N)

    if(v[i] == 5){
      bli += 5;
    }

  }

  return bla+ble+bli;

}//ex3

//O(N) * O(M)

bool exemplo4(vector<int> v, vector<int> w){

  int tamanho = v.size();
  int tamanho2 = w.size();

  for(int i = 0; i<tamanho; i++){//O(N)

    for(int j=0; j<tamanho2; j++){//O(M)
      if(v[i] == v[j]) return true;
    }

  }

  return false;

}//ex4

//O(N) + O(N)
//2 O(N)
//O(N)

bool exemplo5(vector<int> idades){

  int tamanho = idades.size();
  int menor_idade = 200;
  for(int i=0; i<tamanho; i++){ //O(N)

    if(idades[i] < menor_idade){
      menor_idade = idades[i];
    }

  }

  int cont = 0;
  for(int i=0; i<tamanho; i++){ //O(N)
    if(idades[i] == menor_idade) cont++;
  }

  return cont > 1;

}

//O(NlogN)

bool exemplo6(vector<int> idades){
  sort(idades.begin(), idades.end()); //O(NlogN)
  return idades[0] == idades[1];
}

//O(N)*O(logN)

//O(NLogN)

bool exemplo7(set<int> s, vector<int>v){
  int tamanho = v.size();
  for(int i = 0; i<tamanho; i++){ //O(N)
    if (s.count(v[i])) return true;
          //O(LogN)
  }
  return false;
}

int main (int argc, char *argv[]) {

  /*1 - levar em consideração as repetições do código 
   *2 - Verificar a complexidade das funções/métodos próprios da linguagem 
    3 - ignorar constantes e utilizar o termo de maior grau*/

  

  return 0;
}
