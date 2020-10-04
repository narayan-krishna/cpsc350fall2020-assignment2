#include "Grid.h"

Grid::Grid(){
  grid = 0;
  rows = 0;
  cols = 0;
}

//Constructs a grid to given rows and columns. Grid is full of empty cells
Grid::Grid(int row, int col){
  rows = row;
  cols = col;
  grid = new Cell *[rows];
  for(int i = 0; i < rows; ++i){
    grid[i] = new Cell[cols];
    for(int j = 0; j < cols; ++j){
      grid[i][j] = Cell(0);
    }
  }
}

//destruct grid by first deleting each array within the greater array,
//then delete greater array
Grid::~Grid(){
  for(int i = 0; i < rows; ++i){
    delete [] grid[i];
  }
  delete grid;
}

//gives rows of the grid
int Grid::getRows(){
  return rows;
}

//gives columns of the grid
int Grid::getCols(){
  return cols;
}

//can be used to set rows of grid
void Grid::setRows(int row){
  rows = row;
}

//can be used to set columns of grid
void Grid::setCols(int col){
  cols = col;
}

//can be used to bring a certain cell within the grid to life.
//takes cell coordinates as input.
void Grid::animateCell(int i, int j){
  grid[i][j] = Cell(1);
}

//can be used to kill  a certain cell within the grid.
//takes cell coordinates as input.
void Grid::killCell(int i, int j){
  grid[i][j] = Cell(0);
}

//returns a certain cell from the grid based on imput coordinates
Cell Grid::getCell(int i, int j){
  return grid[i][j];
}

//prints the grid
void Grid::print(){
  for(int i = 1; i < rows-1; ++i){
    for(int j = 1; j < cols-1; ++j){
      cout << grid[i][j].toString();
    }
    cout << endl;
  }
  cout << endl;
}
