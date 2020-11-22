/*
** Monster.cpp
** from Monster.h
*/

#include "Monster.h"

/*
** The default constructor. It does nothing
** but call its parent (Entity) default constructor.
*/
Monster::Monster()
  :Entity() {}

/*
** The overloaded constructor
** Two parameters passed, a string name, and an
** integer health points.
** Does nothing but pass those two parameters to
** its parent (Entity) default constructor.
*/
Monster::Monster(string name, int hp)
  :Entity(name, hp) {}

/*
** Prints user's name and attack damage.
** Returns the attack damage done by the Monster.
*/
int Monster::Attack()
{
  cout << GetName() << MONSTER_ATTACK_MESSAGE << endl;
  return MONSTER_ATTACK_DAMAGE;
}
