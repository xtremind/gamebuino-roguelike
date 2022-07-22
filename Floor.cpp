#include "Floor.h"

Floor::Floor()
{

}

// get type of sprite at coordinate {x, y}
const char Floor::get(const int x, const int y){
    return mapOfGame[y][x];
}


void Floor::set(const int x, const int y, const char tile){
  mapOfGame[y][x] = tile;
}

bool Floor::isOutside(const int x, const int y){
  return x < 0 || y < 0 || x >= Floor::WIDTH_MAP || y >= Floor::HEIGHT_MAP;
}