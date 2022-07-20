#include "Character.h"

Character::Character(const int _x, const int _y, const CharacterType _type)
{
  x = _x;
  y = _y;
  offset_x = 0;
  offset_y = 0;

  flip = 1;
  flash = 0;
  action = Action::NONE;
  define(_type);
}

void Character::define(const CharacterType _type){
  type = _type;  
  switch (_type)
  {
  case CharacterType::HERO:
    attack = 1;
    health = 5;
    break;
  case CharacterType::SLIME:
    attack = 1;
    health = 2;
    break;
  }
  maxHealth = health;
}

const int Character::getX() const {return x;}
const int Character::getY() const {return y;}
const int Character::getOffsetX() const {return offset_x;}
const int Character::getOffsetY() const {return offset_y;}
const CharacterType Character::getType() const{return type;}
const int Character::getFlip() const{return flip;}
void Character::wantToGo(int _direction){direction = _direction;}
const int Character::getNextX() {return x + DIRECTION_X[direction];}
const int Character::getNextY() {return y + DIRECTION_Y[direction];}
void Character::setAction(Action _action) {action = _action;}

void Character::computeNextAction()
{
  //gb.display.print(action);
  this->lookAt();
  switch (action)
  {
  case Action::MOVE:
    this->prepareMove();
    break;
  case Action::BUMP:
    this->prepareBump();
    break;
  default:
    break;
  }
}

void Character::lookAt()
{
  if (DIRECTION_X[direction] < 0) {
    flip = -1;
  } else if (DIRECTION_X[direction] > 0) {
    flip = 1;
  }
}

void Character::prepareMove()
{
  //set next position
  x += DIRECTION_X[direction];
  y += DIRECTION_Y[direction];

  //define offset from where to move
  offset_x = -DIRECTION_X[direction] * WIDTH_BLOCK;
  offset_y = -DIRECTION_Y[direction] * HEIGHT_BLOCK;

  start_offset_x = offset_x;
  start_offset_y = offset_y;
}

void Character::prepareBump()
{
  //define offset from where to bump
  offset_x = 0;
  offset_y = 0;

  start_offset_x = DIRECTION_X[direction] * WIDTH_BLOCK;
  start_offset_y = DIRECTION_Y[direction] * HEIGHT_BLOCK;
}

void Character::doAction(float timer_offset)
{
  switch (action)
  {
  case Action::MOVE:
    this->doMove(timer_offset);
    break;
  case Action::BUMP:
    this->doBump(timer_offset);
    break;
  default:
    break;
  }
}

void Character::doMove(float timer_offset)
{
  offset_x = (int)(start_offset_x * (1 - timer_offset));
  offset_y = (int)(start_offset_y * (1 - timer_offset));
}

void Character::doBump(float timer_offset){
  float tmp = timer_offset;

  if(timer_offset > 0.5f){
    tmp = 1 - timer_offset;
  }
  
  offset_x = (int)(start_offset_x * tmp);
  offset_y = (int)(start_offset_y * tmp);
}

bool Character::needToMove() {return action != Action::NONE;}

const int Character::getPower() const{ return attack;}
void Character::beHit(const int atk){
  health -= atk;
  flash = 10;
}
bool Character::isAlive(){return health > 0;}
bool Character::isFlashed(){
  flash = max(flash-1, 0);
  return 0 < flash;
}