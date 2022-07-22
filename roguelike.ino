#include <Gamebuino-Meta.h>

#include "Draw.h"
#include "Update.h"
#include "Cache.h"

void setup()
{
  // initialize Gamebuino
  gb.begin();
  
  // init 
  Cache::_upd = &update_game;
  Cache::_drw = &draw_game;
  
  // init game
  Cache::hero = new Character(1,1,CharacterType::HERO);
  Cache::addMob(Cache::hero);
  
  Character* mob = NULL;
  //Dynamic build mob
  Floor *flr = Cache::flr;
  for (int y = 0; y < flr->HEIGHT_MAP; y++) {
    for (int x = 0; x < flr->WIDTH_MAP; x++) {
      if(flr->get(x, y) == Tiles::SLIME_TYPE) {
        mob = new Character(x,y,CharacterType::SLIME);
        Cache::addMob(mob);
        flr->set(x, y, Tiles::FLOOR_TYPE);
      }
    }
  }

  SerialUSB.begin(9600);
}

void loop()
{
  gb.waitForUpdate();
  gb.display.clear();

  Cache::_upd();
  Cache::_drw();
  Cache::updateFloats();
  //SerialUSB.println(Cache::getCurrentMessage()->lines[0]);
  //SerialUSB.println(Cache::getCurrentMessage()->lines[1]);
  //SerialUSB.println(Cache::getCurrentMessage()->length);
}
