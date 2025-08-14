#include <iostream>

using namespace std;

struct sales_data {

  int sales;
};

int main(int argc, char *argv[]) {

  sales_data myBook;
  myBook.sales = 23000;

  cout << myBook.sales << endl;

  return 0;
}
