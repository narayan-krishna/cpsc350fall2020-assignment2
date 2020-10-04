#include "Game.h"

//modes
//classic - 1
//donut - 2
//mirror - 3

Game::Game(){
  mode = 0;
};

Game::~Game(){
  delete grid;
}

void Game::readInputFile(string inFile){
  int rows = 0;
  int cols = 0;
  ifstream file (inFile);
  string line;
  if (file.is_open()){
    while (getline(file,line)){
      rows += 1;
      cols = line.length()-1;
    }
  }
  file.close();
  writeInputGrid(inFile, rows, cols);
}

void Game::writeInputGrid(string inFile, int rows, int cols){
  ifstream file (inFile);
  string line;
  grid = new Grid(rows, cols);
  int current_row = 0;
  if (file.is_open()){
    while(getline(file,line)){
      for(int j = 0; j < line.length()-1; ++j)
      {
        char current = line.at(j);
        if(current == 'X'){
          grid->animateCell(current_row,j);
        }else{
          grid->killCell(current_row,j);
        }
      }
      current_row += 1;
    }
  }
  file.close();
}


int Game::countNeighbors(int i, int j){
  int neighborCount = 0;
  if(grid->getCell(i-1,j-1).getStatus() == true){
    neighborCount += 1;
  }
  if(grid->getCell(i-1,j).getStatus() == true){
    neighborCount += 1;
  }
  if(grid->getCell(i-1,j+1).getStatus() == true){
    neighborCount += 1;
  }
  if(grid->getCell(i,j-1).getStatus() == true){
    neighborCount += 1;
  }
  if(grid->getCell(i,j+1).getStatus() == true){
    neighborCount += 1;
  }
  if(grid->getCell(i+1,j-1).getStatus() == true){
    neighborCount += 1;
  }
  if(grid->getCell(i+1,j+1).getStatus() == true){
    neighborCount += 1;
  }
  if(grid->getCell(i+1,j).getStatus() == true){
    neighborCount += 1;
  }
  // if(grid->getCell(i,j).getStatus() == true){
  //   cout << i << ", " << j << ": " << neighborCount << endl;
  // }
  return neighborCount;
}


void Game::populateRandom(int row, int col, double density){
  grid = new Grid(row, col);
  for(int i = 0; i < row; ++i){
    for(int j = 0; j < col; ++j){
      double randIndex = rand();
      double randValue = randIndex/RAND_MAX;
      if(randValue<density){
        grid->animateCell(i,j);
      }else{
        grid->killCell(i,j);
      }
    }
  }
}

void Game::propogate(){
  Grid *temp = new Grid(grid->getRows(), grid->getCols());
  for(int i = 0; i < grid->getRows(); ++i){
    for(int j = 0; j < grid->getCols(); ++j){
      if(grid->getCell(i,j).getStatus() == false){
        temp->killCell(i,j);
      }else{
        temp->animateCell(i,j);
      }
    }
  }

  for(int i = 1; i < temp->getRows()-1; ++i){
    for(int j = 1; j < temp->getCols()-1; ++j){
      int neighbors = countNeighbors(i,j);
      if(neighbors < 2){
        temp->killCell(i,j);
      }
      if(neighbors == 2){
        if(grid->getCell(i,j).getStatus() == true){
          temp->animateCell(i,j);
        }else{
          temp->killCell(i,j);
        }
      }
      if(neighbors == 3){
        temp->animateCell(i,j);
      }
      if(neighbors > 3){
        temp->killCell(i,j);
      }
    }
  }

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

void Game::printToConsole(){
  grid->print();
}

void Game::setBoundary(){

}

void Game::updateBoundary(){
  
}
