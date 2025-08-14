#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {

  int numInt;
  int numAlga[4];

  int quartAlga;

  cout << "Digite um numero de três algarismos: " << endl;

  cin >> numInt;

  int algAtual = 2;

  while (numInt) {

    numAlga[algAtual] = numInt % 10;

    cout << algAtual << " : " << numAlga[algAtual] << endl;

    algAtual--;
    numInt /= 10;

  } // while

  quartAlga = (((numAlga[0] + numAlga[1]) * 3) + numAlga[2] * 5) / 7;

  numAlga[3] = quartAlga;

  cout << numAlga[0] << numAlga[1] << numAlga[2] << numAlga[3] << endl;

  return 0;
} // main
