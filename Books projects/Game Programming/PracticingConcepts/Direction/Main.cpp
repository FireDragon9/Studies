#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <cmath>

#include <iostream>

using namespace std;
using namespace sf;

int main(int argc, char *argv[]) {

  // window

  VideoMode vm(720, 640);

  RenderWindow window(vm, "Directions", Style::Default);

  // player

  Texture playerTxt;
  playerTxt.loadFromFile("player.png");

  Sprite playerSpr;
  playerSpr.setTexture(playerTxt);

  playerSpr.setOrigin(24, 24);

  playerSpr.setPosition(720 / 2, 640 / 2);

  float angle = 0;

  while (window.isOpen()) {

    window.clear();

    Vector2i mousePosition = Mouse::getPosition(window);

    window.draw(playerSpr);

    cout << "Mouse X  :   " << mousePosition.x << endl
         << "Mouse Y   :   " << mousePosition.y << endl;

    angle =
        (atan2(mousePosition.y - 640 / 2, mousePosition.x - 720 / 2) * 180) /
        3.141;

    playerSpr.setRotation(angle);

    window.display();

  } // while

  return 0;
}
