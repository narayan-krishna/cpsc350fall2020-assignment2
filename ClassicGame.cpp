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

    //pause print method which incorporates the classic grid boundary function
    //waits 1 second before printing another generation
    void pausePrint(){
      while(stabilized < 3){
        printToConsole();
        propogate();
        updateBoundary();
        this_thread::sleep_for(chrono::milliseconds(1000));
      }
      string exit;
      cout << "your simulation has been completely stable for 3 generations. enter e to exit: " << endl;
      cin >> exit;
      cout << "done" << endl;
    }

    //repeatedly prints propogations to a file with the neccesary mode
    //specific boundary updates
    void printToFile(string fileName, int generations){
      ofstream outFile;
      outFile.open(fileName);
      for(int i = 0; i < generations; ++i){
        outFile << "gen " << i+1 << "\n\n";
        for(int i = 1; i < grid->getRows()-1; ++i){
          for(int j = 1; j < grid->getCols()-1; ++j){
            outFile << grid->getCell(i,j).toString();
          }
          outFile << "\n";
        }
        outFile << "\n";
        propogate();
        updateBoundary();
      }
    }
};

#endif /* CLASSICGAME_CPP */
