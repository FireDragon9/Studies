
#include <iostream>
using namespace std;

class Book {
public:
  string Title;
  string Author;
  float *Rates;
  int RatesCounter;

  Book(string title, string author) {
    Title = title;
    Author = author;

    RatesCounter = 2;
    Rates = new float[RatesCounter];
    Rates[0] = 5;
    Rates[1] = 4;
  }

  // its important to release or realocatte the pointer memory
  // so other applications can reuse it

  ~Book() {
    delete[] Rates;
    Rates = nullptr;
  }

  // custom copy constructor
  // cannot change the property
  Book(const Book &original) {

    Title = original.Title;
    Author = original.Author;
    RatesCounter = original.RatesCounter;

    // Coping rates (ptr)

    Rates = new float[RatesCounter];

    for (int i = 0; i < RatesCounter; i++) {

      Rates[i] = original.Rates[i];

    } // for

  } // copy constructor
};

void PrintBook(Book book) {

  cout << "Title: " << book.Title << endl;
  cout << "Author: " << book.Author << endl;

  float sum = 0;
  for (int i = 0; i < book.RatesCounter; i++) {

    sum += book.Rates[i];
  }

  cout << "Rates: " << sum / book.RatesCounter << endl;
}

int main() {

  // as soon we're working with pointers, we need to provide our own copy
  // constructors

  Book book1("Millionaire Fastlane", "M.J. DeMarco");
  Book book2("C++ Lambda Story", "Bartek F.");

  // Copy constructors are used when you want to create another object
  // with the same parameters as other ones
  Book book3(book1);
  // Book book3 = book1 also invoke a copy constructor

  // book3 = book2 is creating a assignment operator
  //
  PrintBook(book1);

  cin.get();
}
