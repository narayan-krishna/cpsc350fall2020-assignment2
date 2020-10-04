#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Cell.h"
using namespace std;

class Grid{
  private:
    Cell **grid;
    int rows;
    int cols;

  public:
    Grid();
    Grid(int row, int col);
    ~Grid();
    void populateFromFile(string fileName);
    int getRows();
    int getCols();
    void setRows(int row);
    void setCols(int col);
    void animateCell(int i, int j);
    void killCell(int i, int j);
    Cell getCell(int i, int j);
    void print();
};
