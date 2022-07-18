#include "Update.h"
#include "Cache.h"

int button_buffer = -1;
float timer_offset = 0;

void update_start()
{
  //DEBUG gb.display.print("start ");
  Cache::_upd = &update_start;
}

int detectButton(){
  for (size_t i = 0; i < 8; i++)
  {
    if (gb.buttons.pressed(static_cast<Button>(i))){
      return i;
    }
  }
  return -1;
}

void doButton()
{
  Character *hero = Cache::hero;
  hero->wantToGo(button_buffer);
  interact(hero);
  hero->computeNextAction();
  if(hero->needToMove()){
    timer_offset = 0.0f;
  }
  button_buffer = -1;
}

void update_game()
{
  //DEBUG gb.display.print("game ");
  Message *message = Cache::getCurrentMessage();
  if(message != NULL && message->duration == NULL){
    if(detectButton() == 4){
      //gb.display.print("4");
      message->duration=1;
    }
    //gb.display.print( message->duration);
    return;
  }

  if(button_buffer == -1){
    button_buffer = detectButton();
  }

  if(button_buffer > -1 && button_buffer < 4){
      doButton();
      Cache::_upd = &update_hturn;
  }

  button_buffer = -1;
}

void update_hturn()
{
  timer_offset = min(timer_offset + SPEED, 1.0f);
  Character *hero = Cache::hero;
  if(button_buffer == -1){
    button_buffer = detectButton();
  }
  hero->doAction(timer_offset);

  if(timer_offset == 1.0f){
    hero->setAction(Action::NONE);
      Cache::_upd = &update_game;
  }
}

void update_gameover()
{
  //DEBUG gb.display.print("gameover ");
  Cache::_upd = &update_gameover;
}
