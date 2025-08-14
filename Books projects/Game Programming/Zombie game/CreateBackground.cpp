#include "ZombieArena.h"
#include <SFML/System/Vector2.hpp>
#include <cstdlib>

int createBackground(VertexArray &rVA, IntRect arena){

  //Anything we do to rVA we are really doing to background (in the main function)
  
  //how big is each tile/texture
 
  //refers to the size of pixels of each tile within the sprite sheet
  //size in pixels of each tile i.e the grass tile is 50px,  
  const int TILE_SIZE = 50;
  //refers to the number of different tiles within the sprite sheet
  //so, there are three different tiles available
  const int TILE_TYPES = 3;
  //refers to the fact that there are four vertices in every squad
  //vertices are the point where two or more curves or lines face each other
  const int VERTS_IN_QUAD = 4;

  //they refer to the width and height of the world in the number of tiles, NOT PIXELS
  
  int worldWidth = arena.width / TILE_SIZE;
  int worldHeight = arena.height / TILE_SIZE;

  //what type of primiitve are we using 

  rVA.setPrimitiveType(Quads);

  //set the size of the vertex array 
  rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

  //Start at the beginning of the vertex array 
  int currentVertex = 0;

  for (int w = 0; w < worldWidth; w++){

      for(int h = 0; h < worldHeight; h++){

        //position each vertex in the current squad 
        rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);

        rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, 
                                                   h * TILE_SIZE);
        
        rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE,
                                                  (h * TILE_SIZE) + TILE_SIZE);

        rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), 
                                                   (h * TILE_SIZE) + TILE_SIZE);


         // define the position in the texture for current quad,
         //either grass, stone, bush or wall 
         //this condition checks whether the current quad is either one of the very first
         //or the very last quads in the arena 
         //if it is, then this means it is part of the boundary
         if (h == 0 || h == worldHeight-1 ||
             w == 0 || w == worldWidth-1){


          //this attributes defines which pixel of the texture is mapped to the vertex
          //use wall texture 

          rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);

          rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 
                                                      0 + TILE_TYPES * TILE_SIZE);

          rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE,
                                                      TILE_TYPES * TILE_SIZE);

          rVA[currentVertex + 3].texCoords = Vector2f(0,
                                                      TILE_SIZE + TILE_TYPES * TILE_SIZE);

         }else{

          /* this code starts by seeding the random number generator with a formula
           * that will be different in each pass through the loop
           * then, the mOrG variable is initialized with a number 0 and TILE_TYPES
          */

          //use a random floor texture 
          srand((int)time(0) + h * w - h);
          
        //mOrG stands for mud of grass 

          int mOrG = (rand() % TILE_TYPES);
          
          //vertical reference point within the sprte sheet to thee starting height 
          //of the randomly chosen texture for the current quad 
          int verticalOffset = mOrG * TILE_SIZE;

          /* now we use a simple formula involving TILE_SIZE and verticalOffset
           * to assign the precise coordinates of each corner of the texture 
           * to the appropriate vertex 
          */

          rVA[currentVertex + 0].texCoords = Vector2f(0, 0+ TILE_SIZE);

          rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);

          rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, 
                                                      TILE_SIZE + verticalOffset);

          rVA[currentVertex + 3].texCoords = Vector2f(0,
                                                      TILE_SIZE + verticalOffset);

         }//else   



        //Position ready for the next four vertices 
        currentVertex += VERTS_IN_QUAD;

      }//for h  

  }//for w 

  return TILE_SIZE;

}//createBackground
