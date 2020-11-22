/*
** Room.cpp
** From Room.h
*/

#include "Room.h"

/*
** Overloaded constructor
** Creates a room with an ID, name, description of room
** and exits in all four directions. (-1 if no exit)
*/
Room::Room(int ID, string name, string desc, int north,
	   int east, int south, int west){
  m_ID = ID;
  m_name = name;
  m_desc = desc;
  //utilizes the "direction" enum
  m_direction[N] = north;
  m_direction[E] = east;
  m_direction[S] = south;
  m_direction[W] = west;
}

/*
** "Getter" for the room's name.
*/
string Room::GetName(){
  return m_name;
}

/*
** "Getter" for the room's ID number.
*/
int Room::GetID(){
  return m_ID;
}

/*
** "Getter" for the room's description.
*/
string Room::GetDesc(){
  return m_desc;
}

/*
** Checks if the direction from this room is a valid exit.
** Returns the id of the next room if it's valid, -1 otherwise.
*/
int Room::CheckDirection(char myDirection){

  direction d;
  if(myDirection == 'N' || myDirection == 'n')
    d = N;
  else if(myDirection == 'E' || myDirection == 'e')
    d = E;
  else if(myDirection == 'S' || myDirection == 's')
    d = S;
  else if(myDirection == 'W' || myDirection == 'w')
    d = W;
  if(m_direction[d] != NOT_EXIT)
    return m_direction[d];
  return NOT_EXIT;
  
}

/*
** Prints the room description.
** Shows the name of the room, its description
** and possible exits from the room.
*/
void Room::PrintRoom(){
  
  cout << " - " << m_name << " - " << endl
       << m_desc << endl
       << "Possible exits: ";

  if(CheckDirection('N') != NOT_EXIT)
    cout << "N ";
  if(CheckDirection('E') != NOT_EXIT)
    cout << "E ";
  if(CheckDirection('S') != NOT_EXIT)
    cout << "S ";
  if(CheckDirection('W') != NOT_EXIT)
    cout << "W ";
  cout << endl;
}
