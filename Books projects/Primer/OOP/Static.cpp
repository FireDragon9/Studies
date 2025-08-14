#include <iostream>
using namespace std;

class Account {

public:
  void calculate() { amount += amount * interestRate; }
  static double rate() { return interestRate; }
  static void rate(double);

private:
  string owner;
  double amount;
  static double interestRate;
  static double initRate();
};

int main(int argc, char *argv[]) { return 0; }
