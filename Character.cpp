#include "Character.h"

Character::Character(const int _x, const int _y, const CharacterType _type)
{
  x = _x;
  y = _y;
  offset_x = 0;
  offset_y = 0;

  flip = 1;
  action = Action::NONE;
  type = _type;
}

const int Character::getX() const
{
  return x;
}

const int Character::getY() const
{
  return y;
}

const int Character::getOffsetX() const
{
  return offset_x;
}

const int Character::getOffsetY() const
{
  return offset_y;
}

const CharacterType Character::getType() const
{
  return type;
}

const int Character::getFlip() const
{
  return flip;
}

void Character::wantToGo(int _direction)
{
  direction = _direction;
}

const int Character::getNextX()
{
  return x + DIRECTION_X[direction];
}

const int Character::getNextY()
{
  return y + DIRECTION_Y[direction];
}

void Character::setAction(Action _action)
{
  action = _action;
}

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
  if (DIRECTION_X[direction] < 0)
  {
    flip = -1;
  }
  else if (DIRECTION_X[direction] > 0)
  {
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

  timer_offset = 0;
}

void Character::prepareBump()
{
  //define offset from where to bump
  offset_x = 0;
  offset_y = 0;

  start_offset_x = DIRECTION_X[direction] * WIDTH_BLOCK;
  start_offset_y = DIRECTION_Y[direction] * HEIGHT_BLOCK;
  
  timer_offset = 0;
}

void Character::doAction()
{
  timer_offset = min(timer_offset + SPEED, 1.0f);
  switch (action)
  {
  case Action::MOVE:
    this->doMove();
    break;
  case Action::BUMP:
    this->doBump();
    break;
  default:
    break;
  }
}


void Character::doMove()
{
  offset_x = (int)(start_offset_x * (1 - timer_offset));
  offset_y = (int)(start_offset_y * (1 - timer_offset));
}

void Character::doBump(){
  float tmp = timer_offset;

  if(timer_offset > 0.5f){
    tmp = 1 - timer_offset;
  }
  
  offset_x = (int)(start_offset_x * tmp);
  offset_y = (int)(start_offset_y * tmp);
}

bool Character::needToMove()
{
  return timer_offset != 1.0f;
}
