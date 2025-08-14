#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

  char gabarito[3] = {'B', 'A', 'C'};
  char respostas[3];
  string perguntas[3] = {"Quanto é 2 + 2\nA - 2\nB - 4\nC - 3\n",
                         "Quanto é 5*5\nA - 25\nB - 12\nC - 11\n",
                         "Quanto é 9+3?\nA - 1\nB - 23\nC - 12\n"};

  int acertos = 0;

  for (int i = 0; i < 3; i++) {

    system("clear");

    cout << perguntas[i];
    cin >> respostas[i];
  }

  for (int i = 0; i < 4; i++) {

    if (respostas[i] == gabarito[i]) {
      acertos++;
    }
  }

  if (acertos >= 2) {
    cout << "Passou!\n";
  } else {
    cout << "ELIMINADO!\n";
  }

  return 0;
}
