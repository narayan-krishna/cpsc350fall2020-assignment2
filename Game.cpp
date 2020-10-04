#include "Game.h"

//modes
//classic - 1
//donut - 2
//mirror - 3

Game::Game(){
  mode = 0;
  stabilized = 0;
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
  int area = grid->getRows()*grid->getCols();

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

  int same_cell = 0;
  for(int i = 0; i < temp->getRows(); ++i){
    for(int j = 0; j < temp->getCols(); ++j){
      if(temp->getCell(i,j).getStatus() == grid->getCell(i,j).getStatus()){
        same_cell += 1;
      }
      if(temp->getCell(i,j).getStatus() == false){
        grid->killCell(i,j);
      }else{
        grid->animateCell(i,j);
      }
    }
  }

  if(same_cell == area){
    stabilized += 1;
  }
  delete temp;
}

void Game::printToConsole(){
  cout << "stabilized = " << stabilized << endl;
  grid->print();
}

void Game::printToFile(string fileName, int generations){
  ofstream outFile;
  outFile.open(fileName);
  for(int i = 0; i < generations; ++i){
    outFile << "gen " << i << "\n\n";
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

void Game::pausePrint(){
  while(stabilized < 3){
    printToConsole();
    propogate();
    updateBoundary();
    this_thread::sleep_for(chrono::milliseconds(2000));
  }
  string exit;
  cout << "your simulation has been completely stable for 3 generations. enter e to exit: " << endl;
  cin >> exit;
  cout << "done" << endl;
}

void Game::setBoundary(){

}

void Game::updateBoundary(){

}
