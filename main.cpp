#include "Simulation.h"

int main(int argc, char **argv){
  Simulation *s = new Simulation();
  s->run();
  // DonutGame *game = new DonutGame();
  string inFile;
  int row, col;
  float inDensity;
  string inMode;

  // cout << "to enter a map file, enter 1" << endl;
  // cout << "to generate a random assignment, enter 2" << endl;
  // string inChoice;
  // cin >> inChoice;
  // if(inChoice == "1"){
  //   cout << "enter the file name" << endl;
  //   cin >> inFile;
  //   // game->readInputFile(inFile);
  // }else if(inChoice == "2"){
  //   cout << "enter number of rows" << endl;
  //   cin >> row;
  //   cout << "enter number of columns" << endl;
  //   cin >> col;
  //   cout << "enter density of population to be generated" << endl;
  //   cin >> inDensity;
  //   // game->populateRandom(row, col, inDensity);
  // }else{
  //   cout << "invalid" << endl;
  //   return 0;
  // }
  //
  // // cout << "grid created: " << endl;
  // // game->printToConsole();
  // // cout << "grid with boundary: " << endl;
  // // game->setBoundary();
  // // game->printToConsole();
  // // cout << "boundary updated: " << endl;
  // // game->updateBoundary();
  // // game->printToConsole();
  // // cout << "grid propogated: " << endl;
  // // game->propogate();
  // // game->printToConsole();
  // // cout << "boundary updated: " << endl;
  // // game->updateBoundary();
  // // game->printToConsole();
  // // delete game;
  //
  // cout << "enter the number of the game mode you'd like to choose:" << endl;
  // cout << "classic mode - 1" << endl;
  // cout << "donut mode - 2" << endl;
  // cout << "mirror mode - 3" << endl;
  // cin >> inMode;
  // if(inMode == "1"){
  //   ClassicGame *game = new ClassicGame();
  //   if(inChoice == "1"){
  //     game->readInputFile(inFile);
  //   }else if(inChoice == "2"){
  //     game->populateRandom(row, col, inDensity);
  //   }
  //   game->setBoundary();
  //   string outChoice;
  //   cout << "enter the number corresponding to your choice of output: " << endl;
  //   cout << "continuous printing with brief pauses - 1" << endl;
  //   cout << "press enter key to display next generation - 2" << endl;
  //   cout << "output to a file - 3" << endl;
  //   cin >> outChoice;
  //   if(outChoice == "1"){
  //     // game->pausePrint();
  //     return 0;
  //   }else if(outChoice == "2"){
  //     bool run = true;
  //     while(run == true){
  //       cout << "press enter to display generation, or e to exit" << endl;
  //       cout << endl;
  //       if(cin.get() == '\n'){
  //         game->printToConsole();
  //         game->propogate();
  //         game->updateBoundary();
  //       }else{
  //         run == false;
  //         return 0;
  //       }
  //     }
  //   }else if(outChoice == "3"){
  //     string outFile;
  //     cout << "enter the name of the file you'd like to print to" << endl;
  //     cin >> outFile;
  //     int generations;
  //     cout << "enter the number of generations you'd like to print" << endl;
  //     cin >> generations;
  //   }
  // }else if(inMode == "2"){
  //   // DonutGame *game = new DonutGame();
  // }else if(inMode == "3"){
  //   // MirrorGame *game = new MirrorGame();
  // }


  return 0;
}
