#ifndef CACHE
#define CACHE

#include "Floor.h"
#include "Character.h"

struct Mobs{
  Character *mob;
  Mobs* next;
};

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
    static Mobs *mobs;
    static int nbMob;
  public:
    static Floor *flr;
    static Character *hero;
    static void (*_upd)();
    static void (*_drw)();
    static void addMessage(Message *newMessage);
    static Message* getCurrentMessage();
    static void deleteCurrentMessage();
    
    static void addMob(Character *mob);
    static Character* getMob(int i);
    static int nbMobs();
    static void resetMob();
};

#endif