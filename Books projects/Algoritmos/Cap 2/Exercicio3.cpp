#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  int n = 0;

  cout << "Digite um numero: " << endl;
  cin >> n;

  int y1 = 1;

  cout << y1 << endl;

  for (int i = 1; i < n; i++) {

    y1 += 2;

    cout << y1 << endl;

  } // for

  return 0;
}
