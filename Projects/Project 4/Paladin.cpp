/*
** Paladin.cpp
** from Paladin.h
*/

#include "Paladin.h"

/*
** The default constructor. Does nothing but
** call the parent (Character) default constructor.
*/
Paladin::Paladin()
  :Character() {}

/*
** The overloaded constructor.
** Two parameters passed, a string name, and an
** integer health points.
** Does nothing but call the parent (Character)
** overloaded constructor, passes those two paramaters.
*/
Paladin::Paladin(string name, int hp)
  :Character(name, hp) {}

/*
** The destructor. Does nothing since nothing in the class
** is dynamically allocated.
*/
Paladin::~Paladin() {}

/*
** The special attack, prints user's name and special
** attack message, then returns a random attack
** damage in its given range.
*/
int Paladin::SpecialAttack()
{
  cout << GetName() << PALADIN_ATTACK_MSG << endl;
  return (rand() % (PALADIN_UPPER + 1 - PALADIN_LOWER)) + PALADIN_LOWER;
}
