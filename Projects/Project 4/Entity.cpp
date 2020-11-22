/*
** Entity.cpp
** from Entity.h
*/

#include "Entity.h"

/*
** The default constructor.
** Sets m_name to an "empty" string
** Sets the Entity's health to 0.
*/
Entity::Entity(){
  m_name = "";
  m_health = 0;
}


/*
** The overloaded constructor.
** Two parameters passed, a string name
** and an integer health point.
** Sets the Entity's name to the passed name
** Sets the Entity's health to the passed health
*/
Entity::Entity(string name, int health){
  m_name = name;
  m_health = health;
}

/*
** A "getter" for the Entity's name.
** Returns a string with the Entity's name.
*/ 
string Entity::GetName(){
  return m_name;
}

/*
** A "getter" for the Entity's health.
** Returns an integer of the Entity's health.
*/
int Entity::GetHealth(){
  return m_health;
}

/*
** A "setter" for the Entity's name
** One parameter passed, a string with the new
** name of the Entity.
** Sets the Entity's name to the new name.
*/
void Entity::SetName(string newName){
  m_name = newName;
}

/*
** A "setter" for the Entity's health
** One parameter passed, an integer with
** the new health for the Entity.
** Sets the Entity's health to the new health.
*/
void Entity::SetHealth(int newHealth){
  /* 
  ** checks if the new health is less than 0
  ** and sets it to the appropriate health.
  */
  if(newHealth < 0){
    m_health = 0;
  }else{
    m_health = newHealth;
  }
}

/*
** Overriding the "<<" operator to print the health and
** name of the Entity.
** Usage is "cout << *entityPtr"
*/
ostream& operator<<(ostream& output, Entity& entity){

  output << "Name: " << entity.m_name << endl
	 << "Health: " << entity.m_health << endl;
  return output;
}
