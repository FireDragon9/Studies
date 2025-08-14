#ifndef PLAYER_H
#pragma ONCE

#include <SFML/Graphics.hpp>
using namespace sf;

class Player{

  private: 

  const float START_SPEED = 200;
  const float START_HEALTH = 100;

  //Where is the player 
  Vector2f m_Position;

  int m_Health;

  // The sprite 
  Sprite m_Sprite;
  //And a texture 
  //!!WATCH THIS SPACE - CHANGES HERE SOON
  Texture m_Texture;
  //What is the screen resolution
  Vector2f m_Resolution;
  //What size is the current arena
  IntRect m_Arena;
  //How big is each tile of the arena 
  int m_TileSize;
  //Which direction(s) the player in moving in 
  bool m_UpPressed;
  bool m_DownPressed;
  bool m_LeftPressed;
  bool m_RightPressed;
  //how much health has the player got? 
  int m_MaxHealth;
  //When was the player last hit 
  Time m_LastHit;
  //speed in pixels per second
  float m_Speed;

  //ALL our public functions next 

  public:
  //Constructor
  Player();
  void spawn(IntRect arena, Vector2f resolution, int tileSize);

  //call this at the end of every game
  void resetPlayerStats();

  //handle the player getting hit by a zombie
  bool hit(Time timeHit);

  //how long ago was the player last hit 
  Time getLastHitTime();

  //Where is the player
  //horizontal and vertical floating-point coordinates
  //of the rectangle, which contains the player graphic 
  //this is also useful for coliision detection
  FloatRect getPosition();

  //Where is the center of the player 
  Vector2f getCenter();

  //What angle is the player facing
  float getRotation();

  //send a copy of the sprite to the main function
  Sprite getSprite();
  
  //The next four functions move the player 
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

  //stop the player moving in a specific direction 
  void stopLeft();
  void stopRight();
  void stopUp();
  void stopDown();

  //we will call this function once every frame 
  void update(float elapsedTime, Vector2i mousePosition);
  
  //Give the player a speed boost 
  void upgradeSpeed();

  //Give the player some health 
  void upgradeHealth();

  //Increase the max' health the player can have 
  void increaseHealthLevel(int amount);

  //how much health has the player currently got?
  int getHealth();

};

#endif // !PLAYER_H
