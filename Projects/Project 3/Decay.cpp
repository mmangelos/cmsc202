/* 
** Decay.cpp
** from Decay.h
** Mitchell Angelos [CV55655]
** Discussion 23
*/

#include "Decay.h"

Decay::Decay(){
  //initializes m_file
  m_file = "";
}

Decay::~Decay(){
  //empties the list
  EmptyLists();
}

void Decay::EmptyLists(){

  //empties the list
  int vectorSize = int(m_list.size());
  if(vectorSize == 0){
    return; //if the list is empty, don't do anything
  }else{
    for(int i = vectorSize - 1; i >= 0; i--){ //goes through vector
      m_list.at(i)->~DecayList();
      m_list.pop_back();
    }
  }
  
}

void Decay::LoadFile(){

  //cleans the vector before reloading
  EmptyLists();

  cout << "Enter the name of the file you want to load:  ";
  cin >> m_file; //gets file name from the user

  ifstream inputStream;
  inputStream.open(m_file);

  char fileChar = ' ';
  while(inputStream.eof() == false){ //while it's not end of the file

    DecayList* tempList = new DecayList(); //new temporary decay list
    do{
      inputStream >> fileChar; //gets character
      if(fileChar == '1'){
	tempList->InsertEnd(new Node(true)); //assigns new node
      }else if(fileChar == '0'){
	tempList->InsertEnd(new Node(false));
      }
    }while(fileChar != ';');
    if(inputStream.eof() == false){ //if it's not the end of the file
      m_list.push_back(tempList); //pushes back into vector
      tempList->PrintDecayList(); //prints list
    }
  }

  inputStream.close(); //closes the file
}

void Decay::ChooseList(){

  int lSize = int(m_list.size());
  int action = 0;
  if(lSize == 0){ //if there's no file loaded, tell user to load a file
    cout << "Please load a file first!" << endl;
  }else{
    while(action < 1 || action > lSize){
      cout << CHOOSE_DECAY_LIST << endl;
      for(int i = 0; i < lSize; i++){
	cout << i+1
	     << ". "
	     << "List " << i+1 << " ("
	     << m_list.at(i)->GetSize() << " nodes)" << endl;
	//prints lists to choose
      }
      cin >> action; //choose list
    }
    RunSimulation(action - 1); //runs the simulation for that list
    EmptyLists();
  }
}

void Decay::CreateRandomList(){

  EmptyLists();
  
  int lSize = 0;
  while((lSize < RAN_LIST_LOWER) || (lSize > RAN_LIST_UPPER)){
    cout << "Enter a list size (1-10,000): ";
    cin >> lSize; //asks user for size of random list
  }
  
  DecayList* tempDecayList = new DecayList(); //make a new list
  for(int i = 0; i < lSize; i++){ 
    
    for(int j = 0; j < 3; j++){ //creates new nodes in pairs of three for each index
      Node* tempNode = new Node(rand() % 2 == 1 ? true : false);
      tempDecayList->InsertEnd(tempNode);
    }
  }

  m_list.push_back(tempDecayList); //puts that new list into the vector
  tempDecayList->PrintDecayList(); //prints list
}


void Decay::RunSimulation(int index){

  int invertIndex = -1; // the index to invert
  int removedTotal = 0;
  while(m_list.at(index)->CheckEmpty() == false){

    //gets user input for which index to flip, flips it
    m_list.at(index)->PrintDecayList();
    invertIndex = -1;
    while((invertIndex < 1) || (invertIndex > m_list.at(index)->GetSize())){
      cout << "Please input what index you'd like to change: ";
      cin >> invertIndex;
    }
    m_list.at(index)->InvertValue(invertIndex);
    // traverses list
    removedTotal += m_list.at(index)->TraverseList(DEFAULT_TO_BE_REMOVED);
  }
  cout << removedTotal << " nodes removed in all!" << endl;
}



void Decay::Start(){
  cout << "Welcome to Decay!" << endl;

  //the game loop
  int action = 0;
  bool gameLoop = true;
  while(gameLoop){
    cout << "Please choose an action." << endl;
    for(int i = 0; i < MENU_LENGTH; i++){
      cout << i+1
	   << ". "
	   << MENU[i] << endl;
    }
    cin >> action;
    switch(action){
    case 1:
      //case for loading the file
      LoadFile();
      break;
    case 2:
      //case for choosing list to simulate
      ChooseList();
      break;
    case 3:
      //creates a random list
      CreateRandomList();
      break;
    case 4:
      //case for quitting the game
      gameLoop = false;
      EmptyLists();
      break;
    default:
      cout << "Invalid menu choice." << endl;
    }
  }
}
