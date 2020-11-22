/*
** Goblin.cpp
** from Goblin.h
*/

#include "Goblin.h"

/*
** The default constructor.
** Does nothing but call the parent class
** (Monster) constructor.
*/
Goblin::Goblin()
  :Monster() {}

/*
** The overloaded constructor.
** Two parameters passed, a string name,
** and an integer health points.
** Does nothing but pass those two parameters
** to the parent (Monster) overloaded constructor
*/
Goblin::Goblin(string name, int hp)
  :Monster(name, hp) {}

/*
** Prints a special attack message and
** returns a damage given as a constant.
*/
int Goblin::SpecialAttack()
{
  cout << GetName() << GOBLIN_ATTACK_MESSAGE << endl;
  return GOBLIN_ATTACK_DAMAGE;
}
