//Wizard.cpp

#include "Wizard.h"

//constructors
Wizard::Wizard(){
  /* default constructor
  ** empty name, level 1, 0 wins and losses
  ** a random toughness */
  m_name = "";
  m_toughness = (rand() % (MAX_START_TOUGH + 1 - MIN_START_TOUGH)) + MIN_START_TOUGH;
  m_level = 1;
  m_wins = 0;
  m_losses = 0;
}

Wizard::Wizard(string name){
  /* overloaded constructor
  ** name of user's choice, random toughness
  ** level 1, wins and losses both 0. */
  m_name = name;
  m_toughness = (rand() % (MAX_START_TOUGH + 1 - MIN_START_TOUGH)) + MIN_START_TOUGH; 
  m_level = 1;
  m_wins = 0;
  m_losses = 0;
}

//getters
string Wizard::GetName(){
  return m_name; // returns the wizard's name
}

int Wizard::GetToughness(){
  return m_toughness; // returns the wizard's toughness
}

int Wizard::GetLevel(){
  return m_level; // returns the wizard's level
}

int Wizard::GetWins(){
  return m_wins; // returns the wizard's wins
}

int Wizard::GetLosses(){
  return m_losses; // returns the wizard's losses
}

//setters
void Wizard::SetName(string name){
  m_name = name; // sets wizard's name to a new name specified
}

void Wizard::SetToughness(int toughness){
  m_toughness = toughness; // set wizard's toughness to a new specified toughness
}

//functions
void Wizard::InsertFoundable(Foundable newFoundable){

  /* finds the first empty spot in the array for defeated foundables
  ** places new foundable in that spot */
  for(int i = 0; i < NUM_FOUNDABLE; i++){
    if(m_foundables[i].GetRarity() == EMPTY_FND){
      m_foundables[i] = newFoundable;
      i = NUM_FOUNDABLE;
    }
  }
  
}

bool Wizard::CheckFoundable(Foundable newFoundable){

  //if the last element is a valid foundable, then it's in there. You've won.
  if(m_foundables[NUM_FOUNDABLE - 1].GetRarity() != EMPTY_FND){
    return true;
  }

  for(int i = 0; i < NUM_FOUNDABLE; i++){
    if(newFoundable.GetName() == m_foundables[i].GetName()){
      return true; //if you find that foundable in the defeated list, it's there!
    }else if(m_foundables[i].GetRarity() == EMPTY_FND){
      // if it didnt find any valid foundables equal to that foundable, it's not there
      i = NUM_FOUNDABLE;
    }
  }
  // it's not in there
  return false;
}

bool Wizard::AttackFoundable(Foundable enemy){

  /*
  if(CheckFoundable(enemy) == true){
    return false;
  }*/

  cout << GetName() << " attacks " << enemy.GetName() << "!" << endl;
  // if you beat the foundable
  if(m_toughness > enemy.GetToughness()){
    cout << WIN << endl;
    InsertFoundable(enemy); //add him to defeated lists
    IncreaseLevel(); //increase level and toughness
    m_wins++; //increment wins up by 1
  }else{
    if(m_toughness == enemy.GetToughness()){ //if toughnesses are same
      cout << TIE << endl; // print that it's a tie
    }
    cout << LOSS << endl; //you've lost
    m_losses++; //increment losses up by 1
  }
  
  return true;
}

void Wizard::PrintMyFoundables(){

  // for every foundable possible
  for(int i = 0; i < NUM_FOUNDABLE; i++){
    // if the rarity equates to a foundable that is "empty" or invalid
    if(m_foundables[i].GetRarity() == -1){
      if(i == 0){ //if there are no foundables
	cout << NO_FDBLS << endl; //tell user
      }
      i = NUM_FOUNDABLE; // end loop
    }else{ //otherwise print out the foundable
      cout << i+1 << ". "
	   << m_foundables[i].GetName()
	   << " | " << m_foundables[i].GetType()
	   << " | " << m_foundables[i].GetRarity()
	   << " | " << m_foundables[i].GetToughness()
	   << endl;
    }
  }
}

//private functions
 
void Wizard::IncreaseLevel(){
  //increases toughness and level
  m_toughness += (rand() % LEVEL_TOUGH_INCREASE);
  m_level++;
}
