/*
** BabyDragon.cpp
** from BabyDragon.h
*/

#include "BabyDragon.h"

/*
** The default constructor for BabyDragon
** Takes no parameters.
** The function does nothing but call the
** parent class (Monster) default constructor
*/
BabyDragon::BabyDragon()
  :Monster() {}

/*
** The overloaded constructor for BabyDragon.
** Takes two parameters, a string name, and an
** integer health points. The function does nothing
** but pass those two parameters to its parent class
** (Monster) overloaded constructor.
*/
BabyDragon::BabyDragon(string name, int hp)
  :Monster(name, hp) {}

/*
** The destructor, it does nothing since
** there's no dynamically allocated memory.
*/
Entity::~Entity() {}

/*
** The BabyDragon's special attack. It prints a
** special message when using the attack, and 
** returns its apporpriate attack damage.
*/
int BabyDragon::SpecialAttack()
{
  cout << GetName() << BBDRAGON_ATTACK_MESSAGE << endl;
  return BBDRAGON_ATTACK_DAMAGE;
}
