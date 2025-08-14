#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

  int num;

  int graus = 0;

  int segs = 0;

  int mins = 0;

  cout << "Digite um numero: " << endl;

  cin >> num;

  mins = num / 60;

  if (mins < 60) {

    segs = 60 - mins;
  }

  while (mins >= 60) {

    graus++;
    mins -= 60;
  }

  segs = mins * 60;

  cout << "GRAUS : " << graus << endl
       << "MINS : " << mins << endl
       << "SEGS : " << segs << endl;

  return 0;
} // main
