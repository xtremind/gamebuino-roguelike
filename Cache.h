#ifndef CACHE
#define CACHE

#include "Floor.h"
#include "Character.h"
#include "Constants.h"

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

struct Float{
  char* text;
  int x;
  float y;
  int offset_y;
  int duration;
  Float* previous;
  Float* next;
};

class Cache {
  private:
    static Message *message;
    static Float *floats;
    static int nbFloat;
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
    static Character* getMobByPos(int x, int y);
    static void deleteMob(Character *mob);
    static void resetMob();
    static int nbMobs();

    static void addFloat(char* text, int x, int y);
    static Float* getFloat(int pos);
    static void updateFloats();
    static int nbFloats();

};

#endif