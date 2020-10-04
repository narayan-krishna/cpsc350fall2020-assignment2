#include "ClassicGame.cpp"
#include "MirrorGame.cpp"
#include "DonutGame.cpp"

class Simulation{
  private:
    string inFile;
    int row, col;
    float inDensity;
    string inChoice;
    string inMode;

  public:
    Simulation();
    int run();
    int runClassic();
    int runDonut();
    int runMirror();
    // int output(Game*& game, string inChoice);
};
