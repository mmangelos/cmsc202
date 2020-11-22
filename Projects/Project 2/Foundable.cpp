//Foundable.cpp

#include "Foundable.h"

//constructors
Foundable::Foundable() {
  /* new foundable using default constructor
  ** new name and type with empty string
  ** new rarity and toughness, -1 and 0 respectively
  */
  m_name = "";
  m_type = "";
  m_rarity = -1;
  m_toughness = 0;
}

Foundable::Foundable(string name, string type, int rarity, int toughness){
  /* OVERLOADED CONSTRUCTOR - a specified name, type, rarity and toughness
  ** passed to it. */
  m_name = name;
  m_type = type;
  m_rarity = rarity;
  m_toughness = toughness;
}

//getters
string Foundable::GetName(){
  return m_name; // gets foundable's name
}

string Foundable::GetType(){
  return m_type; // returns foundable's type
}

int Foundable::GetRarity(){
  return m_rarity; // returns foundable's rarity
}

int Foundable::GetToughness(){
  return m_toughness; // returns foundable's toughness
}

//setters
void Foundable::SetName(string newName){
  m_name = newName; // sets foundable's name to a new name
}

void Foundable::SetType(string newType){
  m_type = newType; // sets foundable's type to a new type
}

void Foundable::SetRarity(int newRarity){ // sets rarity
  // if newRarity is in bounds (1-5), it'll set it to newRarity
  if(newRarity >= MIN_RARITY && newRarity <= MAX_RARITY){
    m_rarity = newRarity; 
  }else{ //otherwise get a random toughness
    m_rarity = (rand() % (MAX_RARITY + 1 - MIN_RARITY)) - MIN_RARITY;
  }
}

void Foundable::SetToughness(int newToughness) {
  m_toughness = newToughness; // sets toughness to new toughness
}
