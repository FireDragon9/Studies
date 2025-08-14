#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  int numInt;

  int ordem[3];

  int *al0 = new int();
  int *al2 = new int();

  int al = 2;

  cout << "Me dê um número de três algarismos " << endl;
  cin >> numInt;

  while (numInt) {

    ordem[al] = numInt % 10;

    cout << al << " : " << ordem[al] << endl;

    numInt /= 10;

    al--;
  }

  *al0 = ordem[0];

  *al2 = ordem[2];

  ordem[0] = *al2;

  ordem[2] = *al0;

  delete al0;
  delete al2;

  cout << ordem[0] << ordem[1] << ordem[2] << " - algarismos invertidos. "
       << endl;

  return 0;
}
