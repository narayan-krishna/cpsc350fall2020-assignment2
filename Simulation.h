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
    string outChoice;

  public:
    Simulation();
    int run();
    int runClassic();
    int runDonut();
    int runMirror();
    bool checkForInt(string input);
    // int output(Game*& game, string inChoice);
};
