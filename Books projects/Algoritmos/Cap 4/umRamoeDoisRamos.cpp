#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {

  int a;
  int b;

  cout << "Digite o numero A: " << endl;
  cin >> a;
  cout << "Digite o numero B: " << endl;
  cin >> b;

  if (a > b) {
    cout << a << " é maior que " << b;
  } else if (b > a) {
    cout << b << " é maior que " << a;
  } else {
    cout << a << " e " << b << " são iguais" << endl;
  }

  return 0;
} // main
