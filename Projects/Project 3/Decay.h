#ifndef DECAY_H
#define DECAY_H
#include "Node.h"
#include "DecayList.h"
#include <iostream>
#include <fstream>
#include <vector>

const int RAN_LIST_LOWER = 1;
const int RAN_LIST_UPPER = 10000;

const string CHOOSE_DECAY_LIST = "Choose a Decay scenario";

const string MENU[] = {"Load File", "Simulate Loaded File",
		       "Simulate Random List", "Quit"};
const int MENU_LENGTH = 4;

const bool DEFAULT_TO_BE_REMOVED = true;

class Decay{
 public:
  // Constructor
  // Preconditions: None
  // Postconditions: None
  Decay();

  // Destructor - Deletes all lists in m_list
  // Preconditions: m_list is populated
  // Postconditions: All lists are deleted and there are no memory leaks
  ~Decay();

  // EmptyLists() - Empties all lists in m_list
  // Preconditions: m_list is populated
  // Postconditions: All lists are deleated and there are no memory leaks
  void EmptyLists();
  
  // LoadFile - Requests a file and loads all linked lists in a file (separated by ;)
  // Preconditions: Valid input file exists (preferably with three lines of data)
  // Postconditions: m_list is initialized
  void LoadFile();

  // ChooseList - After a file is loaded, allows user to choose a list to simulate
  // Preconditions: User has chosen to start simulation
  // Postconditions: Simulation is started on list chosen by user
  void ChooseList();

  // CreateRandomList - Creates list of a specific size (1-10000) times 3 nodes each
  // Preconditions: m_list is empty
  // Postconditions: m_list.at(0) has a list loaded into it
  void CreateRandomList();
  
  // RunSimulation - Simulate one of the loaded lists
  // Preconditions: A DecayList is available
  // Postconditions: Simulation is run
  void RunSimulation(int index);

  // Start - Starts sim. Can load file, choose list, or create random list
  // Preconditions: A DecayList is available
  // Postconditions: Empties all lists after one is simulated.
  void Start();
  
 private:
  vector<DecayList*> m_list; //vector of DecayLists to simulate
  string m_file; //name of the file to load
};

#endif
