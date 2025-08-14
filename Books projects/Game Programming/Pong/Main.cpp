#include "Ball.h"
#include "Bat.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

int main() {

  // Create a video mode object
  VideoMode vm(960, 540);

  // Create and open a window for the game
  RenderWindow window(vm, "Pong", Style::Default);
  int score = 0;
  int lives = 3;

  // Preparing sounds

  // Colisions
  SoundBuffer colBuffer;
  colBuffer.loadFromFile("sound/col.wav");

  Sound col;

  col.setBuffer(colBuffer);

  // Music
  SoundBuffer musicBuffer;
  musicBuffer.loadFromFile("sound/music.wav");

  Sound music;

  music.setBuffer(musicBuffer);

  // Create a bat at the bottom center of the screen
  Bat bat(960 / 2, 540 - 20);

  Bat bat2(960 / 2, 20);

  // Create a ball
  Ball ball(960 / 2, 540 / 2);

  // We will add a ball in the next chapter

  // Create a text object called HUD
  Text hud;

  // A cool retro-style font
  Font font;

  font.loadFromFile("fonts/DS-DIGI.TTF");

  // set the fontto our retro-style
  hud.setFont(font);

  // Make it nice and big

  hud.setCharacterSize(45);

  // Choose a color

  hud.setFillColor(Color::White);
  hud.setPosition(20, 20);

  // Here is our clock for timing everything
  Clock clock;

  music.play();

  int mov = 0;

  while (window.isOpen()) {
    mov += (Keyboard::isKeyPressed(Keyboard::Right) -
            Keyboard::isKeyPressed(Keyboard::Left));
    cout << mov << endl;
    bat.m_Position.x += mov;

    // Handle player's input
    Event event;
    // while is receiving an input
    while (window.pollEvent(event)) {

      if (event.type == Event::Closed) {

        // Quit the game when the window is closed
        window.close();
      }

    } // while pollEvent

    // update bat, ball and HUD

    // update the delta time

    Time dt = clock.restart();
    bat.update(dt);
    ball.update(dt);

    // Update the HUD text
    std::stringstream ss;

    ss << "Score: " << score << " lives: " << lives;

    hud.setString(ss.str());

    // Handle ball hitting the bottom
    if (ball.getPosition().top > window.getSize().y) {

      // Reverse the ball direction
      ball.reboundBottom();

      col.play();

      // Removes a life
      lives--;

      // Check fo zero lives
      if (lives < 1) {

        // Reset the score
        score = 0;

        // reset the lives
        lives = 3;

      } // if lives

    } // ball getPoistion top > window getsize y

    // Handles the ball hitting top
    if (ball.getPosition().top < 0) {

      ball.reboundBatOrTop();
      col.play();
      // add a point to the player's score

      score++;

    } // if ball position < 0

    // Handle ball hitting sides

    if (ball.getPosition().left < 0 ||
        ball.getPosition().left + ball.getPosition().width >
            window.getSize().x) {

      ball.reboundSides();

      col.play();
    } // if ball pos left

    // Has the ball hit the bat?
    if (ball.getPosition().intersects(bat.getPosition())) {

      // Hit detected so reverse the ball and score a point
      ball.reboundBatOrTop();

      col.play();

    } // intersecs

    // draw bat, ball and HUD

    window.clear();
    window.draw(hud);
    window.draw(bat.getShape());
    window.draw(bat2.getShape());
    window.draw(ball.getShape());
    window.display();

  } // while

  return 0;
} // main
