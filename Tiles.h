#ifndef TILES
#define TILES

class Tiles {
  private:
  public:
    static const char DOOR_TYPE = '.';
    static const char WALL_TYPE = '#';
    static const char FLOOR_TYPE = ' ';
    static const char START_TYPE = '>';
    static const char DESTINATION_TYPE = '@';

    static const char JAR_TYPE = 'J';
    static const char PANEL_TYPE = 'P';
    static const char CLOSED_CHEST_TYPE = 'C';
    static const char OPENED_CHEST_TYPE = 'O';

    static bool isSolid(char Tile);
    static bool isInteractive(char Tile);
};

#endif