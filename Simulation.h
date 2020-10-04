#include "ClassicGame.cpp"
#include "MirrorGame.cpp"
#include "DonutGame.cpp"

class Simulation{
  private:
    string inFile;
    int row, col;
    float inDensity;
    string inMode;

  public:
    Simulation();
    int run();
    // int output(Game*& game, string inChoice);
};
