#include "Draw.h"

void draw_start()
{
}

void draw_game()
{
  draw_floor();
  draw_mobs();
  draw_textboxes();
  draw_floats();
  //draw ui
}

void draw_gameover()
{
}

void draw_mobs()
{
  int nb = Cache::nbMobs();
  //gb.display.print(nb);
  for(int i = 0; i < nb; i++){
    draw_mob(Cache::getMob(i));
  }
}

void draw_mob(Character* mob){
  gb.display.drawImage(mob->getX() * WIDTH_BLOCK + mob->getOffsetX(), mob->getY() * HEIGHT_BLOCK + mob->getOffsetY(), getSprite(mob), mob->getFlip()*WIDTH_BLOCK, HEIGHT_BLOCK);
}

Image& getSprite(Character* mob){
  switch (mob->getType())
  {
  case CharacterType::HERO:
    return SpriteManager::getHero();
  case CharacterType::SLIME:
    return SpriteManager::getSlime(mob->isFlashed());
  }
}

void draw_floor()
{
  Floor *flr = Cache::flr;
  for (int y = 0; y < flr->HEIGHT_MAP; y++) {
    for (int x = 0; x < flr->WIDTH_MAP; x++) {
      paintSprite(x, y, flr->get(x, y));
    }
  }
}

void paintSprite(const int x, const int y, const char typeOfSprites)
{
  switch (typeOfSprites)
  {
  case Tiles::FLOOR_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getFloor());
    break;
  case Tiles::START_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getStart());
    break;
  case Tiles::DESTINATION_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getEnd());
    break;
  case Tiles::DOOR_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getDoor());
    break;
  case Tiles::WALL_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getWall());
    break;
  case Tiles::JAR_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getJar());
    break;
  case Tiles::PANEL_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getPanel());
    break;
  case Tiles::CLOSED_CHEST_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getClosedChest());
    break;
  case Tiles::OPENED_CHEST_TYPE:
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getOpenedChest());
    break;
  }
}


void draw_textboxes(){
  Message *message = Cache::getCurrentMessage();
  //SerialUSB.println(message);
  if (message != NULL){
    draw_textbox(message);
  }
}

void draw_textbox(Message* message)
{
    //gb.gui.popup("text", 50);
    gb.display.setColor(BLACK);
    gb.display.fillRect((gb.display.width()- message->length)/2, (gb.display.height()-message->height)/2 , message->length, message->height);

    gb.display.setColor(WHITE);
    gb.display.drawRect((gb.display.width()- message->length)/2+1, (gb.display.height()-message->height)/2 + 1 , message->length-2, message->height - 2);

    gb.display.setColor(WHITE);

    for (int i = 0; i < (message->height-6)/6; i++){
      gb.display.setCursor((gb.display.width()- message->length)/2 + 3, (gb.display.height()-message->height)/2 + 3 + i*6);
      gb.display.println(message->lines[i]);
    }

  if (message->duration != NULL){
    message->duration -= 1;
    if (message->duration <= 0){
      //reduce size of element -> not possible in gamebuino 
      //if size is minimum -> not possible in gamebuino
      Cache::deleteCurrentMessage();
    }
  } else if (message->button){
      gb.display.setColor(BLACK);
      gb.display.fillRect((gb.display.width()+ message->length)/2 - 8, (gb.display.height()+message->height)/2 -5, 5, 7);

      gb.display.setColor(WHITE);
      gb.display.setCursor((gb.display.width() + message->length)/2 - 7, (gb.display.height() + message->height)/2 - 4);
      gb.display.println("A");
  }
}

void draw_floats()
{
  int nb = Cache::nbFloats();
  //gb.display.print(nb);
  for(int i = 0; i < nb; i++){
    
    draw_float(Cache::getFloat(i));
  }
}

void draw_float(Float* flt){
  //gb.display.setCursor(0, 0);
  //gb.display.print(flt->y);
  gb.display.setColor(ORANGE);
  gb.display.setCursor(flt->x, flt->y);
  gb.display.println(flt->text);
  gb.display.setColor(WHITE);
}