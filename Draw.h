#ifndef DRAW
#define DRAW

#include <Gamebuino-Meta.h>

#include "SpriteManager.h"
#include "Tiles.h"

#include "Constants.h"
#include "Cache.h"

void draw_start();
void draw_game();
void draw_gameover();

void draw_floor();

void draw_mobs();
void draw_mob(Character* mob);
Image& getSprite(Character* mob);
void paintSprite(const int x, const int y, const char typeOfSprites);

void draw_textboxes();
void draw_textbox(Message* message );

void draw_floats();
void draw_float(Float* flt);

#endif
