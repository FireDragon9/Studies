#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <ostream>

using namespace sf;
using namespace std;

int opSel = 0;

int opChoose() {} // opCHoose

void controls(RenderWindow &window) {

  // Events that happens BEFORE drawing in scene
  // use this for specific things such as menu

  // keyboard keys

  static bool isApressed = false;
  static bool isDpressed = false;

  static bool isEnterPressed = false;

  Event event;

  while (window.pollEvent(event)) {

    switch (event.type) {

    case Event::Closed: {
      window.close();
      break;
    } // closed

    case Event::KeyPressed: {

      if (event.key.code == Keyboard::A && !isApressed) {

        cout << "A pressed\n";

        if (opSel >= 1) {
          opSel--;
        }

        isApressed = true;

      } // A

      if (event.key.code == Keyboard::D && !isDpressed) {

        cout << "D pressed\n";
        if (opSel < 1) {
          opSel++;
        }
        isDpressed = true;

      } // D

      if (event.key.code == Keyboard::Enter && !isEnterPressed) {

        cout << "Enter pressed\n";
        isEnterPressed = true;
      }

      break;
    } // KeyPressed

    case Event::KeyReleased: {

      if (event.key.code == Keyboard::A && isApressed) {

        cout << "A released\n";
        isApressed = false;

      } // A

      if (event.key.code == Keyboard::D && isDpressed) {

        cout << "D released\n";
        isDpressed = false;

      } // D

      if (event.key.code == Keyboard::Enter && isEnterPressed) {

        cout << "Enter released\n";
        isEnterPressed = false;

      } // Enter

      break;
    } // keyReleased

    } // switch event.type statement

  } // while
}

int main(int argc, char *argv[]) {

  // size of the window
  VideoMode vm(720, 640);

  RenderWindow window(vm, "EVENT", Style::Default);

  // Options

  string options[2] = {"Attack", "Defense"};

  string *ptr;

  ptr = options;

  Text optionsText[2];
  optionsText[0].setString(options[0]);
  optionsText[1].setString(options[1]);

  Font font;
  font.loadFromFile("GameFont.ttf");

  // while window is open
  while (window.isOpen()) {

    controls(window);

    ////DRAWING

    window.clear();

    for (int i = 0; i < 2; i++) {

      if (optionsText[i].getString() == *(ptr + opSel)) {

        optionsText[i].setFillColor(Color::Green);

      } else {

        optionsText[i].setFillColor(Color::White);
      }

      optionsText[i].setFont(font);

      optionsText[i].setCharacterSize(70);

      optionsText[i].setPosition(220 * i, 290);

      window.draw(optionsText[i]);
    } // for

    window.display();
  }

  return 0;
} // main
