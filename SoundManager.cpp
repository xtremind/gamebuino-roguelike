#include "SoundManager.h"


void SoundManager::breakDoor(){
  #ifndef NOSOUND
  gb.sound.playTick();
  #endif 
}
void SoundManager::breakJar(){
  #ifndef NOSOUND
  gb.sound.playTick();
  #endif 
}
void SoundManager::openChest(){
  #ifndef NOSOUND
  gb.sound.playTick();
  #endif 
}
void SoundManager::walk(){
  #ifndef NOSOUND
  gb.sound.playTick();
  #endif 
}
void SoundManager::attack(){
  #ifndef NOSOUND
  gb.sound.playTick();
  #endif 
}
void SoundManager::hit(){
  #ifndef NOSOUND
  gb.sound.playTick();
  #endif 
}