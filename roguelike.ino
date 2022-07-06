#include <Gamebuino-Meta.h>

#include "Draw.h"
#include "Update.h"
#include "Cache.h"

void setup()
{
  // initialize Gamebuino
  gb.begin();
  //_drw = &draw_start;
  Cache::_upd = &update_game;
  Cache::_drw = &draw_game;
  // init game

  Character* mob = new Character(9,2,CharacterType::SLIME);
  Cache::addMob(mob);
  mob = new Character(2,6,CharacterType::SLIME);
  Cache::addMob(mob);
  mob = new Character(2,2,CharacterType::SLIME);
  Cache::addMob(mob);

  SerialUSB.begin(9600);
}

void loop()
{
  while (!gb.update())
    ;

  // clear screen
  gb.display.clear();

  //next_upd(_upd());
  Cache::_upd();
  Cache::_drw();
  //SerialUSB.println(Cache::getCurrentMessage()->lines[0]);
  //SerialUSB.println(Cache::getCurrentMessage()->lines[1]);
  //SerialUSB.println(Cache::getCurrentMessage()->length);
}
