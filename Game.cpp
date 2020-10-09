#include "Game.h"

//modes
//classic - 1
//donut - 2
//mirror - 3

//Constructs a standard game class
Game::Game(){
  mode = 0;
  stabilized = 0;
  generation = 0;
};

//delete the game class
Game::~Game(){
  delete grid;
}


//reads in the number of rows and columns, and writes the input grid to the
//class
void Game::readInputFile(string inFile){
  int rows = 0;
  int cols = 0;
  ifstream file (inFile);
  string line;
  //this code can be used so that the user does not have to
  //put the rows and columns in their file.
  // if (file.is_open()){
  //   while (getline(file,line)){
  //     rows += 1;
  //     cols = line.length()-1;
  //   }
  // }
  // file.close();
  if(file.is_open()){
    getline(file,line);
    rows = stoi(line);
    getline(file,line);
    cols = stoi(line);
    grid = new Grid(rows, cols);
    int current_row = 0;
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
  // cout << "rows and cols" << endl;
  // cout << rows << endl;
  // cout << cols << endl;
  // writeInputGrid(inFile, rows, cols);
}

//this is if you want to write the grid without asking for rows and columns
// void Game::writeInputGrid(string inFile, int rows, int cols){
//   ifstream file (inFile);
//   string line;
//   grid = new Grid(rows, cols);
//   int current_row = 0;
//   if (file.is_open()){
//     while(getline(file,line)){
//       for(int j = 0; j < line.length()-1; ++j)
//       {
//         char current = line.at(j);
//         if(current == 'X'){
//           grid->animateCell(current_row,j);
//         }else{
//           grid->killCell(current_row,j);
//         }
//       }
//       current_row += 1;
//     }
//   }
//   file.close();
// }

//count the number of neighbors at a given location within the grid
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

//propogate the grid based on the current cells
void Game::propogate(){
  generation += 1;
  int area = grid->getRows()*grid->getCols();
  //create a new temporary grid, copy current grid onto it.
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
  //change the status of cells based on game conditions within temporary grid
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

  //copy temporary grid back onto the original grid
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

  //keep track of if the grid doesn't change, so we can alert the user
  //that the program has potentially stabilized
  if(same_cell == area){
    stabilized += 1;
  }
  delete temp;
}

//print the grid to console whenever needed (along with the current generation)
void Game::printToConsole(){
  cout << "gen " << generation << endl;
  // cout << "stabilized = " << stabilized << endl;
  grid->print();
}
