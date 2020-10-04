#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "Grid.h"
using namespace std;

class Game{
 protected:
    Grid *grid;
    int mode;

  public:
    Game();
    // game(int density, string mode);
    // game(string fileName, string mode);
    void readInputFile(string inFile);
    void writeInputGrid(string inFile, int rows, int cols);
    virtual ~Game();
    // void setBoundary();
    int countNeighbors(int i, int j);
    void populateRandom(int row, int col, double density);
    void propogate();
    // void outputToFile(int generations);
    void printToConsole();
    void setBoundary();
    void updateBoundary();
    void printToFile(string fileName, int generations);
    // void pausePrint();
};

#endif /* GAME_H */
