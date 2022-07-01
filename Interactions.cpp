#include "Interactions.h"

char* text[] = { "Welcome to ", "the game"};

void interact(Character *hero, Floor *flr)
{
  char tile = flr->get(hero->getNextX(), hero->getNextY());
  //gb.display.print(tile);
  // compute event depending on tile
  if(Tiles::isSolid(tile) || flr->isOutside(hero->getNextX(), hero->getNextY())){
    hero->setAction(Action::BUMP);
    if(Tiles::isInteractive(tile)){
      switch (tile)
      {
      case Tiles::DOOR_TYPE:
        flr->set(hero->getNextX(), hero->getNextY(), Tiles::FLOOR_TYPE);
        SoundManager::breakDoor();
        break;
      case Tiles::JAR_TYPE:
        flr->set(hero->getNextX(), hero->getNextY(), Tiles::FLOOR_TYPE);
        SoundManager::breakJar();
        break;
      case Tiles::CLOSED_CHEST_TYPE:
        flr->set(hero->getNextX(), hero->getNextY(), Tiles::OPENED_CHEST_TYPE);
        SoundManager::openChest();
        break;
      case Tiles::PANEL_TYPE:
        //SerialUSB.println("Panel");
        Message *message = new Message();
        message->lines = text;
        message->length = 50; //nb car*4+6
        message->height = 18;  //nb line*6+6
        //message->duration = 20;
        message->button = true;

        Cache::addMessage(message);
        break;
      }
    }
  } else {
    hero->setAction(Action::MOVE);
        SoundManager::walk();
  }
}