#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <algorithm>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

int main (int argc, char *argv[]) {
  
  
  RenderWindow window(VideoMode(1920, 1080), "Awesome Game");

  Texture texture;

  if (!texture.loadFromFile("nah id vim.jpg")){
    std::cout << "Error loading texture"<< std::endl;
  }
  
  Sprite sprite(texture);
  
  //a 300x200 rectangle CENTERED on the point 350, 300
  /*the first parameter is WHERE in the window my view will be positioned
   * the second parameter is the SIZE of my view
   */

  float aa = 250;
  float bb = 250;
    

  View view (Vector2f(aa, bb), Vector2f(640, 720));


  while(window.isOpen()){


    Event event;

    while(window.pollEvent(event)){

      switch(event.type){

        case Event::Closed:{
          window.close();

          break;
        }

        case Event::KeyReleased:{

          //view.reset(FloatRect(200, 200, 800, 900));


          //view.setCenter(Vector2f(380, 670));

          //view.setSize(1920, 1080);


          if (Keyboard::Key::Up == event.key.code){

            view.move(sf::Vector2f(0, -30));

          }else if (Keyboard::Key::Down == event.key.code){
            view.move(Vector2f(0,30));
          }else if (Keyboard::Key::Left == event.key.code){
            view.setRotation(25);
          }else if (Keyboard::Key::Right == event.key.code){
            view.setRotation(-25);
          }

          break;
        }

      }//switch event type 
      

      //Update the game 

      window.setView(view);
      


      window.clear();

           

      window.draw(sprite);

      window.display();


    }//while window pollEvent


  }//while window is open

  return 0;
}
