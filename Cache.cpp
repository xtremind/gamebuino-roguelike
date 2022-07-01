#include "Cache.h"


int Cache::nbCharacters = 0;;
Floor *Cache::flr = new Floor();
Character *Cache::hero = new Character(CharacterType::HERO);
Message *Cache::message = NULL;

void (*Cache::_upd)();
void (*Cache::_drw)();


void Cache::addMessage(Message *newMessage){
  if(Cache::message == NULL) {
    Cache::message = newMessage;
    return;
  }

    Message *nextMessage = Cache::message->next;

  while (nextMessage != NULL){
    nextMessage = nextMessage->next;
  }
  nextMessage = newMessage;
}

Message* Cache::getCurrentMessage(){
  return Cache::message;
}

void Cache::deleteCurrentMessage(){
  if(Cache::message != NULL) {
    Cache::message = Cache::message->next;
  }
}