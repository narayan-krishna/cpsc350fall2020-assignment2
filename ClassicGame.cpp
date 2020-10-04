#ifndef CLASSICGAME_CPP
#define CLASSICGAME_CPP

#include "Game.h"

//a derived classs from the game class which creates a boundary to the
//classic specifications
class ClassicGame:public Game{
  public:
    //sets up a new dead cell boundary around the input grid.
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

    void updateBoundary(){

    }
};

#endif /* CLASSICGAME_CPP */
