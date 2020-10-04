#ifndef DONUTGAME_CPP
#define DONUTGAME_CPP

#include "Game.h"

//a class dervied from the game class which creates a boundary around the
//original grid to donut specifications
class DonutGame:public Game{
  public:
    //sets up an empty boundary filled with dead cells
    void setBoundary(){
      Grid *temp = new Grid(grid->getRows()+2, grid->getCols()+2);
      for(int i = 0; i < grid->getRows(); ++i){
        for(int j = 0; j < grid->getCols(); ++j){
          if(grid->getCell(i,j).getStatus() == false){
            temp->killCell(i+1,j+1);
          }else{
            temp->animateCell(i+1,j+1);
          }
        }
      }

      delete grid;
      grid = new Grid(temp->getRows(), temp->getCols());
      for(int i = 0; i < temp->getRows(); ++i){
        for(int j = 0; j < temp->getCols(); ++j){
          if(temp->getCell(i,j).getStatus() == false){
            grid->killCell(i,j);
          }else{
            grid->animateCell(i,j);
          }
        }
      }
      delete temp;
    }

    //updates the boundary to match the donut  specificationss
    //goes through boundary and updates cell status -- first by corners,
    //then by top and bottom row, then by left and right column
    void updateBoundary(){
      int rows = grid->getRows();
      int cols = grid->getCols();

      //corners
      if(grid->getCell(1,1).getStatus() == true){
        grid->animateCell(0,0);
      }else{
        grid->killCell(0,0);
      }

      if(grid->getCell(rows - 2,1).getStatus() == true){
        grid->animateCell(rows - 1 ,0);
      }else{
        grid->killCell(rows - 1,0);
      }

      if(grid->getCell(rows - 2, cols - 2).getStatus() == true){
        grid->animateCell(rows - 1 , cols - 1);
      }else{
        grid->killCell(rows - 1, cols - 1);
      }

      if(grid->getCell(1, cols - 2).getStatus() == true){
        grid->animateCell(0 , cols - 1);
      }else{
        grid->killCell(0, cols - 1);
      }

      //top row and bottom row
      for(int i = 1; i < cols - 1; ++i)
      {
        if(grid->getCell(1, i).getStatus() == true){
          grid->animateCell(rows-1, i);
        }else{
          grid->killCell(rows-1, i);
        }
      }

      //bottom row
      for(int i = 1; i < cols - 1; ++i)
      {
        if(grid->getCell(rows - 2, i).getStatus() == true){
          grid->animateCell(0, i);
        }else{
          grid->killCell(0, i);
        }
      }

      //right column
      for(int i = 1; i < rows - 1; ++i)
      {
        if(grid->getCell(i, 1).getStatus() == true){
          grid->animateCell(i, cols-1);
        }else{
          grid->killCell(i, cols-1);
        }
      }

      //left column
      for(int i = 1; i < rows - 1; ++i)
      {
        if(grid->getCell(i, cols-2).getStatus() == true){
          grid->animateCell(i, 0);
        }else{
          grid->killCell(i, 0);
        }
      }
    }
};

#endif /* DONUTGAME_CPP */
