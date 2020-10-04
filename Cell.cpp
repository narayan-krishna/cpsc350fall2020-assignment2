#include "Cell.h"

Cell::Cell(){
  status = false;
}

Cell::Cell(int inStatus){
  if(inStatus==0){
    status = false;
  }else{
    status = true;
  }
}

// void Cell::destroy(){
//   status == false;
// }
//
// void Cell::animate(){
//   status == true;
// }

bool Cell::getStatus(){
  return status;
}

string Cell::toString(){
  if(status == false){
    return "-";
  }else{
    return "X";
  }
}
