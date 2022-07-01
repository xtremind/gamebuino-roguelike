#ifndef CHARACTER
#define CHARACTER

#include <Gamebuino-Meta.h>

#include "Constants.h"
#include "Actions.h"

enum CharacterType
{
  HERO,
  SLIME,
};

class Character
{
private:
  int x;
  int y;
  int offset_x;
  int offset_y;

  int flip;

  int start_offset_x;
  int start_offset_y;

  float timer_offset;

  int direction;
  Action action;
  CharacterType type;

  void lookAt();
  void prepareMove();
  void prepareBump();
  
  void doMove();
  void doBump();

public:
  Character(CharacterType _type);
  const int getX() const;
  const int getY() const;
  const int getOffsetX() const;
  const int getOffsetY() const;

  const int getFlip() const;

  void wantToGo(int direction);
  const int getNextX();
  const int getNextY();
  void setAction(Action _action);
  void computeNextAction();
  void doAction();
  bool needToMove();
};

#endif
