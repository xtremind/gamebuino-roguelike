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
  CharacterType type;
  int attack;
  int health;
  int maxHealth;

  void define(const CharacterType _type);

  int x;
  int y;
  int start_offset_x;
  int start_offset_y;
  int offset_x;
  int offset_y;

  int flip;
  int flash;

  int direction;
  Action action;

  void lookAt();
  void prepareMove();
  void prepareBump();
  
  void doMove(float timer_offset);
  void doBump(float timer_offset);

public:
  Character(const int _x, const int _y, const CharacterType _type);
  const int getX() const;
  const int getY() const;
  const int getOffsetX() const;
  const int getOffsetY() const;
  const CharacterType getType() const;

  const int getFlip() const;

  void wantToGo(int direction);
  const int getNextX();
  const int getNextY();
  void setAction(Action _action);
  void computeNextAction();
  void doAction(float timer_offset);
  bool needToMove();

  const int getPower() const;
  void beHit(const int atk);
  bool isAlive();
  bool isFlashed();
};

#endif
