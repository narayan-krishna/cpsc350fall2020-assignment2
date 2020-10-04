#include "Simulation.h"

Simulation::Simulation(){
  inFile = "";
  row = 0;
  col = 0;
  inDensity = 0;
  inChoice = "";
  inMode = "";
}

//runs a simulation of game of life, first asking for the type of input,
//then the type of game, and then the type of output
int Simulation::run(){
  cout << "to enter a map file, enter 1" << endl;
  cout << "to generate a random assignment, enter 2" << endl;
  cin >> inChoice;
  if(inChoice == "1"){
    cout << "enter the file name" << endl;
    cin >> inFile;
    // game->readInputFile(inFile);
  }else if(inChoice == "2"){
    cout << "enter number of rows" << endl;
    cin >> row;
    cout << "enter number of columns" << endl;
    cin >> col;
    cout << "enter density of population to be generated" << endl;
    cin >> inDensity;
    // game->populateRandom(row, col, inDensity);
  }else{
    cout << "invalid" << endl;
    return 0;
  }

  cout << "enter the number of the game mode you'd like to choose:" << endl;
  cout << "classic mode - 1" << endl;
  cout << "donut mode - 2" << endl;
  cout << "mirror mode - 3" << endl;
  cin >> inMode;

  //CLASSIC GAME
  if(inMode == "1"){
    runClassic();

  //DONUT GAME
  }else if(inMode == "2"){
    runDonut();

  //MIRROR GAME
  }else if(inMode == "3"){
    runMirror();
  }
  return 0;
}

int Simulation::runClassic(){
  ClassicGame *game = new ClassicGame();
  if(inChoice == "1"){
    game->readInputFile(inFile);
  }else if(inChoice == "2"){
    game->populateRandom(row, col, inDensity);
  }
  game->setBoundary();
  string outChoice;
  cout << "enter the number corresponding to your choice of output: " << endl;
  cout << "continuous printing with brief pauses - 1" << endl;
  cout << "press enter key to display next generation - 2" << endl;
  cout << "output to a file - 3" << endl;
  cin >> outChoice;
  if(outChoice == "1"){
    game->pausePrint();
    return 0;
  }else if(outChoice == "2"){
    bool run = true;
    while(run == true){
      cout << "press enter to display generation, or e to exit" << endl;
      cout << endl;
      if(cin.get() == '\n'){
        game->printToConsole();
        game->propogate();
        game->updateBoundary();
      }else{
        run == false;
        return 0;
      }
    }
  }else if(outChoice == "3"){
    string outFile;
    cout << "enter the name of the file you'd like to print to" << endl;
    cin >> outFile;
    int generations;
    cout << "enter the number of generations you'd like to print" << endl;
    cin >> generations;
    game->printToFile(outFile, generations);
  }
  delete game;
}

int Simulation::runDonut(){
  DonutGame *game = new DonutGame();
  if(inChoice == "1"){
    game->readInputFile(inFile);
  }else if(inChoice == "2"){
    game->populateRandom(row, col, inDensity);
  }
  game->setBoundary();
  game->updateBoundary();
  string outChoice;
  cout << "enter the number corresponding to your choice of output: " << endl;
  cout << "continuous printing with brief pauses - 1" << endl;
  cout << "press enter key to display next generation - 2" << endl;
  cout << "output to a file - 3" << endl;
  cin >> outChoice;
  if(outChoice == "1"){
    game->pausePrint();
    return 0;
  }else if(outChoice == "2"){
    bool run = true;
    while(run == true){
      cout << "press enter to display generation, or e to exit" << endl;
      cout << endl;
      if(cin.get() == '\n'){
        game->printToConsole();
        game->propogate();
        game->updateBoundary();
      }else{
        run == false;
        return 0;
      }
    }
  }else if(outChoice == "3"){
    string outFile;
    cout << "enter the name of the file you'd like to print to" << endl;
    cin >> outFile;
    int generations;
    cout << "enter the number of generations you'd like to print" << endl;
    cin >> generations;
    game->printToFile(outFile, generations);
  }
  delete game;
}

int Simulation::runMirror(){
  MirrorGame *game = new MirrorGame();
  if(inChoice == "1"){
    game->readInputFile(inFile);
  }else if(inChoice == "2"){
    game->populateRandom(row, col, inDensity);
  }
  game->setBoundary();
  game->updateBoundary();
  string outChoice;
  cout << endl;
  cout << "enter the number corresponding to your choice of output: " << endl;
  cout << "continuous printing with brief pauses - 1" << endl;
  cout << "press enter key to display next generation - 2" << endl;
  cout << "output to a file - 3" << endl;
  cin >> outChoice;
  if(outChoice == "1"){
    game->pausePrint();
    return 0;
  }else if(outChoice == "2"){
    bool run = true;
    while(run == true){
      cout << "press enter to display generation, or e to exit" << endl;
      cout << endl;
      if(cin.get() == '\n'){
        game->printToConsole();
        game->propogate();
        game->updateBoundary();
      }else{
        run == false;
        return 0;
      }
    }
  }else if(outChoice == "3"){
    string outFile;
    cout << "enter the name of the file you'd like to print to" << endl;
    cin >> outFile;
    int generations;
    cout << "enter the number of generations you'd like to print" << endl;
    cin >> generations;
    game->printToFile(outFile, generations);
  }
  delete game;
}
