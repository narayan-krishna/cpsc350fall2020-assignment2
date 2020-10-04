#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

class Cell{
  private:
    bool status;

  public:
    Cell();
    Cell(int status);
    // void destroy();
    // void animate();
    bool getStatus();
    string toString();
};
