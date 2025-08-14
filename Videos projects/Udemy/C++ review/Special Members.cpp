#include <iostream>
#include <iterator>

using namespace std;


int main (int argc, char *argv[]) {

  cout << "Allocating memory for array \n" << endl;

  int *pa = new int[20];

  cout << "Populating array\n";

  for (int i = 0; i < 20; i++){
    pa[i] = i;
  }

  cout << "Array elements:\n";

  for (int i = 0; i < 20; i++){
    cout << pa[i] << ", ";
  }

  cout << endl;

  cout << "Releasing array's memory\n";

  delete[] pa;
  
  return 0;
}
