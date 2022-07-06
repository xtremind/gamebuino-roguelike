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

void draw_hero();
void draw_mobs();
void draw_mob(Character* mob);

void draw_floor();
void draw_textboxes();
void draw_textbox(Message* message );
void paintSprite(const int x, const int y, const char typeOfSprites);
void paintBlock(const int x, const int y, const Color color);

#endif
