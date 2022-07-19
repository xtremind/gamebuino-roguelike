#ifndef INTERACTIONS
#define INTERACTIONS

#include "Character.h"
#include "Floor.h"
#include "Tiles.h"

#include "Actions.h"
#include "Cache.h"

#include "SoundManager.h"

void interact(Character *hero);
bool hasInteractedWithFloor(Character *hero);
bool hasInteractedWithMob(Character *hero);
void interactWithNothing(Character *hero);

#endif