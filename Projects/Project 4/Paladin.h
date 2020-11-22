#ifndef _PALADIN_H_
#define _PALADIN_H_

#include "Character.h"

const string PALADIN_ATTACK_MSG = " uses smite evil!";
const int PALADIN_LOWER = 1;
const int PALADIN_UPPER = 8;

class Paladin: public Character {
 public:
  // Name: Paladin() - Default Constructor
  // Description: Creates a new paladin
  // Preconditions: None
  // Postconditions: Can create a paladin
  Paladin();
  // Name: Paladin(string name, int hp)
  // Description: Creates a new paladin
  // Preconditions: None
  // Postconditions: Can create a paladin
  Paladin(string, int);
  // Name: ~Paladin - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Paladin();
  // Name: SpecialAttack
  // Description: Defines the Paladin's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
