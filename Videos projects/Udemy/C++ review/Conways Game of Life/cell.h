#ifndef CELL_H_
#define CELL_H_ 

#include <iostream> 

#include "live.h"

class cell{

  //cell status 
  bool alive; 

  public:

    //Constructor
    //Cells are empty by default
    cell() : alive(false) {}

    //draw the cell on the grid 
    void draw(int row, int col) const;

    //bring cell to life
    void create(){
      alive = true;
    }

  //end cell's life 
  void erase(){
    alive = false;
  }

  bool is_alive() const {return alive;}

};

#endif
