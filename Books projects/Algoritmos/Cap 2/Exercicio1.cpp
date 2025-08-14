#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  int n;

  cout << "Digite um numero: " << endl;

  cin >> n;

  for (int i = 1; i < n + 1; i++) {

    int t = (2 * i) - 1;

    cout << t << endl;

  } // for

  return 0;
} // main
