#include "Draw.h"

void draw_start()
{
}

void draw_game()
{
  draw_floor();
  draw_hero();
  draw_mobs();
  draw_textboxes();
  //draw ui
}

void draw_hero()
{
  //DEBUG 
  Character *hero = Cache::hero;
  //gb.display.drawImage(hero->getX() * WIDTH_BLOCK , hero->getY() * HEIGHT_BLOCK , SpriteManager::getHero());
  gb.display.drawImage(hero->getX() * WIDTH_BLOCK + hero->getOffsetX(), hero->getY() * HEIGHT_BLOCK + hero->getOffsetY(), SpriteManager::getHero(), hero->getFlip()*WIDTH_BLOCK, HEIGHT_BLOCK);
  //DEBUG
  //gb.display.print(hero->getOffsetX());
}


void draw_mobs()
{
  gb.display.drawImage(1 * WIDTH_BLOCK, 7 * HEIGHT_BLOCK , SpriteManager::getSlime(), 1*WIDTH_BLOCK, HEIGHT_BLOCK);
}

void draw_floor()
{
  Floor *flr = Cache::flr;
  for (int y = 0; y < flr->HEIGHT_MAP; y++)
  {
    for (int x = 0; x < flr->WIDTH_MAP; x++)
    {
      // draw the map from model
      paintSprite(x, y, flr->get(x, y));
    }
  }
}

void paintSprite(const int x, const int y, const char typeOfSprites)
{
  switch (typeOfSprites)
  {
  case Tiles::FLOOR_TYPE: // background
    // paintBlock(x, y, GREEN);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getFloor());
    break;
  case Tiles::START_TYPE: // starting point
    //paintBlock(x, y, RED);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getStart());
    break;
  case Tiles::DESTINATION_TYPE: // end point
    //paintBlock(x, y, PINK);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getEnd());
    break;
  case Tiles::DOOR_TYPE: // door
    //paintBlock(x, y, YELLOW);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getDoor());
    break;
  case Tiles::WALL_TYPE: // wall
    //paintBlock(x, y, BLUE);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getWall());
    break;
  case Tiles::JAR_TYPE: // wall
    //paintBlock(x, y, BLUE);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getJar());
    break;
  case Tiles::PANEL_TYPE: // wall
    //paintBlock(x, y, BLUE);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getPanel());
    break;
  case Tiles::CLOSED_CHEST_TYPE: // wall
    //paintBlock(x, y, BLUE);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getClosedChest());
    break;
  case Tiles::OPENED_CHEST_TYPE: // wall
    //paintBlock(x, y, BLUE);
    gb.display.drawImage(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, SpriteManager::getOpenedChest());
    break;
  }
}

void draw_gameover()
{
}

void paintBlock(const int x, const int y, const Color color)
{
  gb.display.setColor(color);
  gb.display.fillRect(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, WIDTH_BLOCK, HEIGHT_BLOCK);
  gb.display.setColor(BLACK);
  gb.display.drawLine(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, x * WIDTH_BLOCK + WIDTH_BLOCK, y * HEIGHT_BLOCK);
  gb.display.drawLine(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, x * WIDTH_BLOCK, y * HEIGHT_BLOCK + HEIGHT_BLOCK);
  // gb.display.drawRect(x * WIDTH_BLOCK, y * HEIGHT_BLOCK, WIDTH_BLOCK, HEIGHT_BLOCK);
}


void  draw_textboxes(){
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
