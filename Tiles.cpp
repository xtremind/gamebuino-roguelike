#include "Tiles.h"

bool Tiles::isSolid(char Tile)
{
  return Tiles::WALL_TYPE == Tile 
      || Tiles::DOOR_TYPE == Tile 
      || Tiles::JAR_TYPE == Tile 
      || Tiles::CLOSED_CHEST_TYPE == Tile 
      || Tiles::PANEL_TYPE == Tile;
}

bool Tiles::isInteractive(char Tile)
{
  return Tiles::DOOR_TYPE == Tile 
      || Tiles::JAR_TYPE == Tile 
      || Tiles::CLOSED_CHEST_TYPE == Tile
      || Tiles::PANEL_TYPE == Tile
      ;
}