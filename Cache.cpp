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

void Cache::resetMob(){
  Cache::mobs = NULL;
  Cache::nbMob = 0;
}