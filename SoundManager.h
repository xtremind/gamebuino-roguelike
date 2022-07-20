#ifndef SOUNDMANAGER
#define SOUNDMANAGER

#include <Gamebuino-Meta.h>

class SoundManager
{
private:
public:
  static void breakDoor();
  static void breakJar();
  static void openChest();
  static void walk();
  static void attack();
  static void hit();
};

#endif