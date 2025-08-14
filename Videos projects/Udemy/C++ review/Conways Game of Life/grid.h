#ifndef GRID_H_
#define GRID_H_ 

#include <string> 
#include <vector> 
#include <cstdlib>

#include "cell.h" 

class grid{

  //the cells on screen
  //we have a border consisting of inactive cells.
  //These are used in the calculation for the next generation of cells,
  //but are not displayed on the screen
  cell cells[rowmax+2][colmax+2];

  public:

  //create a cell at (row, column)
  void create(int row, int column);

  //ðraw all the cells 
  
  void draw();

  //populate the grid with cells, at random 
  void randomize();
  
  //will the cell at (row, column) survive to the next generation 
  bool will_survive(int row, int column);

  //will a cell be born at (row, column) in the next generation 
  bool will_create(int row, int column);

  //update to the next generation 
  void update(const grid& next);


};

//non-member function
//calculates wich cells survive to the next generation and which are born 

void calculate(grid& old_generation, grid& new_generation);

#endif
