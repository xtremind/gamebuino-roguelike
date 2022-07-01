#ifndef SPRITEMANAGER
#define SPRITEMANAGER

#include <Gamebuino-Meta.h>
#include <cmath>

#include "Sprites.h"


class SpriteManager {
  private:
    //Characters
    static Image hero;
    static Image slime;
    //Tiles    
    static bool doorInitialized;
    static bool wallInitialized;
    static bool floorInitialized;
    static bool startInitialized;
    static bool endInitialized;
    static bool jarInitialized;
    static bool panelInitialized;
    static bool closedChestInitialized;
    static bool openedChestInitialized;
    static Image door;
    static Image wall;
    static Image floor;
    static Image start;
    static Image end;
    static Image jar;
    static Image panel;
    static Image closedChest;
    static Image openedChest;
    
    static Image getAnimatedSprite(const uint8_t* sprites, const int * frames);
    static Image getSingleSprite(const uint8_t* sprites, int frame);
    static int computeCurrentFrame(const int * frames);
  public:
    //Characters
    static Image& getHero();
    static Image& getSlime();
    //Tiles
    static Image& getDoor();
    static Image& getWall();
    static Image& getFloor();
    static Image& getStart();
    static Image& getEnd();
    static Image& getJar();
    static Image& getPanel();
    static Image& getClosedChest();
    static Image& getOpenedChest();
};

#endif
