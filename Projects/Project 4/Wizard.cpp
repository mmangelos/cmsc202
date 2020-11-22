/*
** Wizard.cpp
** from Wizard.h
*/

#include "Wizard.h"

/*
** The default constructor. Does nothing but call its
** parent (Character) default constructor.
*/
Wizard::Wizard()
  :Character() {}

/*
** The overloaded constructor.
** Two parameters passed, a string name and an
** integer health points.
** Takes those two parameters and passes them to
** the overloaded parent constructor (Character)
*/
Wizard::Wizard(string name, int hp)
  :Character(name, hp) {}

/*
** The destructor. Does nothing since nothing in the class
** is dynamically allocated.
*/
Wizard::~Wizard() {}

/*
** The special attack. Prints name and message,
** then returns an attack damage in a range.
*/
int Wizard::SpecialAttack()
{
  cout << GetName() << WIZ_SP_MSG << endl;
  return (rand() % (WIZ_UP + 1 - WIZ_LOW)) + WIZ_LOW;
}
