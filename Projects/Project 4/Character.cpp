/*
** Character.cpp
** from Character.h
*/

#include "Character.h"

/*
** The Character default constructor. It does nothing
** but call its parent (Entity) default constructor
*/
Character::Character()
  :Entity() {}

/*
** The Character overloaded constructor. It does nothing
** but call its parent (Entity) overloaded constructor.
*/
Character::Character(string name, int hp)
  :Entity(name, hp) {}

/*
** The destructor for Character. It does nothing since
** there is nothing dynamically allocated in the Character
** class.
*/
Character::~Character() {}

/*
** Returns a random damage to opponent in a range of 1
** to ATTACK_DAMAGE. (for this project, that's 6)
*/
int Character::Attack()
{
  return (rand() % ATTACK_DAMAGE) + 1;
}

/*
** A virtual function defined for Character, in this project
** a generic Character cannot have a special attack.
*/
int Character::SpecialAttack(){
  return -1;
}

