#include "Cache.h"

void (*Cache::_upd)();
void (*Cache::_drw)();

//-------------- COMMON -----------------------

Floor *Cache::flr = new Floor();
Character *Cache::hero = NULL;

//-------------- MESSAGES -----------------------
Message *Cache::message = NULL;

void Cache::addMessage(Message *newMessage){
  if(Cache::message == NULL) {
    Cache::message = newMessage;
    return;
  }

    Message *nextMessage = Cache::message;

  while (nextMessage->next != NULL){
    nextMessage = nextMessage->next;
  }
  nextMessage->next = newMessage;
}

Message* Cache::getCurrentMessage(){
  return Cache::message;
}

void Cache::deleteCurrentMessage(){
  if(Cache::message != NULL) {
    Cache::message = Cache::message->next;
  }
}

//-------------- MOBS -----------------------
Mobs *Cache::mobs = NULL;
int Cache::nbMob = 0;

void Cache::addMob(Character *mob){
  
  Mobs *newMob = new Mobs();
  newMob->mob = mob;

  if(Cache::mobs == NULL) {
    Cache::mobs = newMob;
    Cache::nbMob = 1;
    return;
  }

  Mobs *nextMob = Cache::mobs;

  while (nextMob->next != NULL){
    nextMob = nextMob->next;
  }

  nextMob->next = newMob;
  Cache::nbMob++;
}

Character* Cache::getMob(int pos){
  int i = 0;
  Mobs *buffer = Cache::mobs;
  while (buffer != NULL && i <= pos ){
    if (i == pos){
      return buffer->mob;
    }
    buffer = buffer->next;
    i++;
  }

  return NULL;
}

Character* Cache::getMobByPos(int x, int y){
  Mobs *buffer = Cache::mobs;
  while (buffer != NULL ){
    if (buffer->mob->getX() == x && buffer->mob->getY() == y){
      return buffer->mob;
    }
    buffer = buffer->next;
  }

  return NULL;
}

int Cache::nbMobs(){
  return Cache::nbMob;
}

void Cache::deleteMob(Character *mob){
  Mobs *buffer = Cache::mobs;
  if(buffer->mob == mob){
    Cache::mobs=buffer->next;
    Cache::nbMob--;
  }
  while (buffer != NULL ){
    if(buffer->next->mob == mob){
      buffer->next = buffer->next->next;
      Cache::nbMob--;
      break;
    }
    buffer = buffer->next;
  }

}

void Cache::resetMob(){
  Cache::mobs = NULL;
  Cache::nbMob = 0;
}

//-------------- FLOAT -----------------------
Float *Cache::floats = NULL;
int Cache::nbFloat = 0;

void Cache::addFloat(char* text, int x, int y){
  Float *flt = new Float();
  flt->text = text;
  flt->x = x*WIDTH_BLOCK;
  flt->y = y*HEIGHT_BLOCK;
  flt->offset_y = y*HEIGHT_BLOCK - 10;
  flt->duration = 0;

  if(Cache::floats == NULL) {
    flt->previous = NULL;
    Cache::floats = flt;
    Cache::nbFloat = 1;
    return;
  }

  Float *buffer = Cache::floats;

  while (buffer->next != NULL){
    buffer = buffer->next;
  }

  buffer->next = flt;
  flt->previous = buffer;
  Cache::nbFloat++;
}

Float* Cache::getFloat(int pos){
  int i = 0;
  Float *buffer = Cache::floats;
  while (buffer != NULL && i <= pos ){
    if (i == pos){
      return buffer;
    }
    buffer = buffer->next;
    i++;
  }

  return NULL;
}

void Cache::updateFloats(){
  Float *buffer = Cache::floats;

  while (buffer != NULL ){
    buffer->y += (buffer->offset_y - buffer->y)/10;
    buffer->duration++;
    if(buffer->duration >= 70){
      if(buffer->previous==NULL){
        buffer->next->previous=NULL;
        Cache::floats=buffer->next;
      } else {
        buffer->previous->next = buffer->next;
        buffer->next->previous = buffer->previous;
      }
      Cache::nbFloat--;
    }
    buffer = buffer->next;
  }
}

int Cache::nbFloats(){
  return Cache::nbFloat;
}