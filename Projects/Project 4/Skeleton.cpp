/*
** Skeleton.cpp
** from Skeleton.h
*/

#include "Skeleton.h"

/*
** The default constructor.
** Does nothing but call its parent (Monster)
** default constructor.
*/
Skeleton::Skeleton()
  :Monster() {}

/*
** The overloaded constructor.
** Passes two paramaters, a string name, and
** an integer health points.
** Does nothing but pass said parameters to the
** parents (Monster) overloaded constructor.
*/
Skeleton::Skeleton(string name, int hp)
  :Monster(name, hp) {}

/*
** The special attack. Prints a special attack message
** and returns a special attack damage.
*/
int Skeleton::SpecialAttack()
{
  cout << GetName() << SKELETON_ATTACK_MESSAGE << endl;
  return SKELETON_ATTACK_DAMAGE;
}
