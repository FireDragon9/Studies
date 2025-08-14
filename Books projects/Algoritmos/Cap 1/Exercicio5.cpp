#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {

  int num;

  int numAlga[5];

  int algAtual = 4;

  bool run;

  int decimal;

  cout << "digite um numero binario de 5 digitos: " << endl;

  cin >> num;

  while (algAtual >= 0) {

    numAlga[algAtual] = num % 2;

    cout << algAtual << " : " << numAlga[algAtual] << endl;

    algAtual--;

    num /= 2;

  } // algAtual

  for (int i = 0; i < 5; i++) {

    decimal += numAlga[i] * (10 ^ i);
  }

  cout << "The decimal is: " << decimal << endl;

  return 0;
}
