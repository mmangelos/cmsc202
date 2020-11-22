/*
** Rogue.cpp
** from Rogue.h
*/

#include "Rogue.h"

/*
** The default constructor. Does nothing but call its
** parent (Character) default constructor.
*/
Rogue::Rogue()
  :Character() {}

/*
** The overloaded constructor.
** Passes two parameters, a string name and an
** integer health points.
** Does nothing but pass said parameters to its parent
** (Character) overloaded constructor.
*/
Rogue::Rogue(string name, int hp)
  :Character(name, hp) {}

/*
** The destructor. It does nothing since nothing in the class
** is dynamically allocated.
*/
Rogue::~Rogue() {}

/*
** The special attack. Prints the user's name and special
** attack message. Then returns an attack damage in its
** specified range.
*/
int Rogue::SpecialAttack()
{
  cout << GetName() << ROGUE_SP_MSG << endl;
  return (rand() % (ROGUE_UP + 1 - ROGUE_LOW)) + ROGUE_LOW;
}
