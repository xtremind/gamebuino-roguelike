#ifndef CACHE
#define CACHE

#include "Floor.h"
#include "Character.h"

struct Message{
  char** lines;
  int length;
  int height;
  int duration = NULL;
  bool button = false;
  Message* next;
};

class Cache {
  private:
    static Message *message;
  public:
    static Floor *flr;
    static int nbCharacters;
    static Character *hero;
    static void (*_upd)();
    static void (*_drw)();
    static void addMessage(Message *newMessage);
    static Message* getCurrentMessage();
    static void deleteCurrentMessage();
};

#endif