#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main (int argc, char *argv[]) {

  //Create a video mode object  
  VideoMode vm(1280, 720);
  //create and open a window for the game
  RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

  //////////////////////////////////////////

  //Create a texture to hold a graphic on the GPU Texture
 
  Texture textureBackground;

  //Load a graphic into the texture textureBackground

  textureBackground.loadFromFile("Assets/graphics/background.png");

  //Create a sprite

  Sprite spriteBackground;
  
  //Attach texture to the sprite
  
  spriteBackground.setTexture(textureBackground);

  //Set the spriteBackground to cover ot the screen

  spriteBackground.setPosition(0, 0);


  ////////

  while(window.isOpen()){
    //Handles the player input

    if (Keyboard::isKeyPressed(Keyboard::Escape)){
      
      window.close();
      std::cout << "Esc pressed, game closed.\n";
    }//close window    

    window.clear();

    //drawwing sprite
    window.draw(spriteBackground);

    window.display();

  }//while

  return 0;


}//main
