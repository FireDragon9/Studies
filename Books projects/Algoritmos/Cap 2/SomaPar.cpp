#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {

  int s = 0;
  int n;
  cout << "Digite um numero " << endl;
  cin >> n;

  for (int i = 1; i < n + 1; i++) {

    int t = 2 * i;

    s += t;
  }

  cout << s << endl;

  return 0;
}
