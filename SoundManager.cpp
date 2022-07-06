#include "SoundManager.h"


void SoundManager::breakDoor(){

}
void SoundManager::breakJar(){

}
void SoundManager::openChest(){

}
void SoundManager::walk(){
  #ifndef NOSOUND
  gb.sound.playTick();
  #endif 
}