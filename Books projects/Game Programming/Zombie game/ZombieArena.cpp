#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdio>
#include <iostream>
#include "player.h"

using namespace sf;

int main(){

  // The game will always be in one of four states
  enum class State {PAUSED, LEVELING_UP,
                    GAME_OVER, PLAYING};

  // Start with the GAME_OVER STATE 
  State state = State::GAME_OVER;

  // get the screen resolution and create an SFML window

  Vector2f resolution;

  resolution.x = VideoMode::getDesktopMode().width;

  resolution.y = VideoMode::getDesktopMode().height;

  RenderWindow window(VideoMode(resolution.x, resolution.y),
                      "Zombie Arena", Style::Fullscreen);

  //Create an SFML view for the main action
  View mainView(sf::FloatRect(0,0,resolution.x, resolution.y));

  //here is our clock for timing everything
  Clock clock;

  //how long has the PLAYING state been active
  Time gameTimeTotal;

  // whe is the mouse in relation to world coordinates
  Vector2f mouseWorldPosition;

  //where the mouse is in relation to the screen coordinates 
  Vector2i mouseScreenPosition;

  //create an instance of the player class 
  Player player;

  // the boundaries of the arena 
  IntRect arena;

  // main game loop
  
  while (window.isOpen()){

    /*
    **************
    Handle input
    ***************
    */
    
    //handle events by polling
    Event event;

    while(window.pollEvent(event)){

      if (event.type == Event::KeyPressed){

        //pause a game while playing 
        
        if (event.key.code == Keyboard::Return && state == State::PLAYING){

          state = State::PAUSED;

        }else if(event.key.code == Keyboard::Return && state == State::PAUSED){
          state = State::PLAYING;
          //Reset the clock so there isnt a frame jump
          
          //If we didnt restart the clock, all our objects would update their locations
          //as if the frame had just taken a very long time 
          clock.restart();

        }else if(event.key.code == Keyboard::Return && state == State::GAME_OVER){

          state = State::LEVELING_UP; 
  
        }//keyboard::return 


        if (state == State::PLAYING){

          

        }//state PLAYING
    

      }//Event::KeyPressed

    }//while window poll event
    
    //handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape)){
      window.close();
    }

    //Handle WASD while playing 
    if (state == State::PLAYING){
      //Handle the pressing and releasing of WASD keys 
      if (Keyboard::isKeyPressed(Keyboard::W)){

        player.moveUp();

      }else{

        player.stopUp();

      }

      if (Keyboard::isKeyPressed(Keyboard::S)){

        player.moveDown();

      }else{

        player.stopDown();

      }

      if (Keyboard::isKeyPressed(Keyboard::A)){

        player.moveLeft();

      }else{

        player.stopLeft();

      }

     if(Keyboard::isKeyPressed(Keyboard::D)){

        player.moveRight();

      }else{

        player.stopRight();

      }

    }//state PLAYING
    
    //Handle the LEVILING UP state 

    if (state == State::LEVELING_UP){

      //handle the player LEVELING UP up
      
      if (event.key.code == Keyboard::Num1){

        state = State::PLAYING;

      }
      
      if (event.key.code == Keyboard::Num2){

        state = State::PLAYING;

      }
      
      if (event.key.code == Keyboard::Num3){

        state = State::PLAYING;

      }
      
      if (event.key.code == Keyboard::Num4){

        state = State::PLAYING;

      }
      
      if (event.key.code == Keyboard::Num5){

        state = State::PLAYING;

      }
      
      if (event.key.code == Keyboard::Num6){

        state = State::PLAYING;

      }

      if (state == State::PLAYING){

        //prepare the level 
        //We will modify the next two lines later 
        arena.width = 500;
        arena.height = 500;

        arena.left = 0;
        arena.top = 0;

        //we will modify this line of code later 
        int tileSize = 50;

        //spawn the player in middle of the arena 
        player.spawn(arena, resolution, tileSize);


        //reset clock so there isnt a frame jump 
        clock.restart();

      }// if state == playing 

      }//state LEVELING_UP



  /*
    UPDATE THE FRAME  
  */

    if (state == State::PLAYING){

      //update the delta time 
      Time dt = clock.restart();

      //update the total game time 

      gameTimeTotal += dt; 

      //make a fraction of 1 from the delta time 
      float dtAsSeconds = dt.asSeconds();

      //where is the mouse pointer

      mouseScreenPosition = Mouse::getPosition();

      //convert mouse poisiton to world 
      //based coordinates of mainView 
      mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

      //update the player 
      player.update(dtAsSeconds, Mouse::getPosition());

      //make a note of the players new position 
      
      Vector2f playerPosition(player.getCenter());

      // make the view center the raround player 
      mainView.setCenter(player.getCenter());

    }//end updating the scene

 
  /*
    draw the scene   
  */

    if (state == State::PLAYING){

      window.clear();

      //set the mainView to be displayed in the window 
      //and draw everything related to it 

      window.setView(mainView);
      // Draw the player 
      window.draw(player.getSprite());

    }// state PLAYING 

    if (state == State::LEVELING_UP){

    }//STATE LEVELING_UP

    if (state == State::PAUSED){

    }//STATE LEVELING_UP
   
    if (state == State::GAME_OVER){

    }//STATE LEVELING_UP

    window.display();

  }// while window is Open

  return 0;
}
