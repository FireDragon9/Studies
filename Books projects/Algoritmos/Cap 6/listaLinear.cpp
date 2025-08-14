#include <cstdlib>
#include <iostream>
#include <iterator>
using namespace std;

int main(int argc, char *argv[]) {

  int lista[5] = {6, 2, 1, 5, 3};
  int size = sizeof(lista) / sizeof(lista[0]);

  int *currNumb = new int;
  int *nextNumb = new int;

  for (int i = 0; i < size; i++) {

    int n = 1;

    cout << lista[i] << endl;

    while (lista[i] > lista[i + n]) {

      currNumb = &lista[i];
      nextNumb = &lista[i + n];

      cout << "Here\n";

      lista[i + n] = *currNumb;
      lista[i] = *nextNumb;

    } // while

  } // for

  for (int i = 0; i < 5; i++) {

    cout << lista[i] << " ";
  }

  cout << endl;

  free(currNumb);
  free(nextNumb);
  delete currNumb;
  delete nextNumb;

  currNumb = nullptr;
  nextNumb = nullptr;

  return 0;
}
