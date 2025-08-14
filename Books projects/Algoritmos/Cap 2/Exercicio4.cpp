#include <cmath>
#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {

  int X = 1;

  for (int A = 2; A < 10; A++) {
    X = 1;

    for (int i = 1; i < 6; i++) {

      X = (X + A / X) / 2;
    }
    cout << A << " " << X << endl;
  }

  return 0;
}
