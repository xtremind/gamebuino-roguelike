#include "SpriteManager.h"

//Characters
Image SpriteManager::hero;
Image SpriteManager::slime;

//Tiles
bool SpriteManager::doorInitialized = false;
bool SpriteManager::wallInitialized = false;
bool SpriteManager::floorInitialized = false;
bool SpriteManager::startInitialized = false;
bool SpriteManager::endInitialized = false;
bool SpriteManager::jarInitialized = false;
bool SpriteManager::panelInitialized = false;
bool SpriteManager::closedChestInitialized = false;
bool SpriteManager::openedChestInitialized = false;

Image SpriteManager::door;
Image SpriteManager::wall;
Image SpriteManager::floor;
Image SpriteManager::start;
Image SpriteManager::end;
Image SpriteManager::jar;
Image SpriteManager::panel;
Image SpriteManager::closedChest;
Image SpriteManager::openedChest;

// characters : animated
Image& SpriteManager::getHero() {
  SpriteManager::hero = SpriteManager::getAnimatedSprite(CHARACTERS_SPRITES, HERO_SPRITES);
  return SpriteManager::hero;
}

Image& SpriteManager::getSlime() {
  SpriteManager::slime = SpriteManager::getAnimatedSprite(CHARACTERS_SPRITES, SLIME_SPRITES);
  return SpriteManager::slime;
}

// tiles : non animated
Image& SpriteManager::getDoor() {
  if(! SpriteManager::doorInitialized) {
    SpriteManager::door = SpriteManager::getSingleSprite(TILES_SPRITES, DOOR_SPRITES[0]);
    SpriteManager::doorInitialized = true;
  }
  return SpriteManager::door;
}

Image& SpriteManager::getWall() {
  if(! SpriteManager::wallInitialized) {
    SpriteManager::wall = SpriteManager::getSingleSprite(TILES_SPRITES, WALL_SPRITES[0]);
    SpriteManager::wallInitialized = true;
  }
  return SpriteManager::wall;
}

Image& SpriteManager::getFloor() {
  if(! SpriteManager::floorInitialized) {
    SpriteManager::floor = SpriteManager::getSingleSprite(TILES_SPRITES, FLOOR_SPRITES[0]);
    SpriteManager::floorInitialized = true;
  }
  return SpriteManager::floor;
}

Image& SpriteManager::getStart() {
  if(! SpriteManager::startInitialized) {
    SpriteManager::start = SpriteManager::getSingleSprite(TILES_SPRITES, START_SPRITES[0]);
    SpriteManager::startInitialized = true;
  }
  return SpriteManager::start;
}

Image& SpriteManager::getEnd() {
  if(! SpriteManager::endInitialized) {
    SpriteManager::end = SpriteManager::getSingleSprite(TILES_SPRITES, END_SPRITES[0]);
    SpriteManager::endInitialized = true;
  }
  return SpriteManager::end;
}

Image& SpriteManager::getJar() {
  if(! SpriteManager::jarInitialized) {
    SpriteManager::jar = SpriteManager::getSingleSprite(TILES_SPRITES, JAR_SPRITES[0]);
    SpriteManager::jarInitialized = true;
  }
  return SpriteManager::jar;
}

Image& SpriteManager::getPanel() {
  if(! SpriteManager::panelInitialized) {
    SpriteManager::panel = SpriteManager::getSingleSprite(TILES_SPRITES, PANEL_SPRITES[0]);
    SpriteManager::panelInitialized = true;
  }
  return SpriteManager::panel;
}

Image& SpriteManager::getClosedChest() {
  if(! SpriteManager::closedChestInitialized) {
    SpriteManager::closedChest = SpriteManager::getSingleSprite(TILES_SPRITES, CLOSED_CHEST_SPRITES[0]);
    SpriteManager::closedChestInitialized = true;
  }
  return SpriteManager::closedChest;
}

Image& SpriteManager::getOpenedChest() {
  if(! SpriteManager::openedChestInitialized) {
    SpriteManager::openedChest = SpriteManager::getSingleSprite(TILES_SPRITES, OPENED_CHEST_SPRITES[0]);
    SpriteManager::openedChestInitialized = true;
  }
  return SpriteManager::openedChest;
}

//manage non-animated sprites
Image SpriteManager::getSingleSprite(const uint8_t* sprites, int frame) {
  Image sprite(sprites);
  sprite.setFrame(frame);
  return sprite;
}

//manage animated sprites
Image SpriteManager::getAnimatedSprite(const uint8_t* sprites, const int * frames) {
  Image sprite(sprites);
  sprite.setFrame(SpriteManager::computeCurrentFrame(frames));
  return sprite;
}

int SpriteManager::computeCurrentFrame(const int * frames){
  if (sizeof(frames) == 1){
    return frames[0];
  }
  return frames[((int)std::floor(gb.frameCount / 8)) % sizeof(frames)];
}