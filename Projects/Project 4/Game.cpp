/*
** Game.cpp
** from Game.h
*/

#include "Game.h"

/*
** Default constructor for Game.
** Asks the user for a filename to load the map,
** loads said map, creates a character, then
** starts the game.
*/
Game::Game(){

  string file;
  cout << "Please enter a filename to load from: ";
  cin >> file;

  LoadMap(file);
  CharacterCreation();
  StartGame();
}

/*
** Overloaded constructor for Game.
** Takes one parameter, a string filename.
** Loads the passed file, creates a character,
** then starts the game.
*/
Game::Game(string filename){
  
  LoadMap(filename);
  CharacterCreation();
  StartGame();
}

/*
** The Game destructor.
** There are three dynamically allocated variables in Game.
** The monster, character and all the rooms (stored in a vector)
** The destructor deallocates said variables, and sets them to
** nullptrs.
*/
Game::~Game(){

  delete m_curMonster;
  m_curMonster = nullptr;
  //deallocates the current monster
  delete m_myCharacter;
  m_myCharacter = nullptr;
  //deallocates the current character
  for(Room* room : m_myMap){ //iterates through every room in the map vector.
    delete room; //deallocates all the rooms
    room = nullptr;
  }
}

/*
** Loads the map for the game, creates all the rooms and stores it in the vector.
** Takes one parameter, a string filename to load the rooms from.
** It takes the passed file, loads it, and puts all the rooms in the vector.
*/
void Game::LoadMap(string file){

  ifstream inputStream(file);

  while(inputStream.eof() == false){

    //stores all the room attributes in a string array, length 7.
    string roomStr[7];
    for(int i = 0; i < 7; i++){
      getline(inputStream, roomStr[i], '|'); //'|' breaks apart the room attributes.
    }
    if(roomStr[6] != "") //if the last attribute of the room is not empty, create a room.
      m_myMap.push_back(new Room(stoi(roomStr[0]), roomStr[1],
				 roomStr[2], stoi(roomStr[3]),
				 stoi(roomStr[4]), stoi(roomStr[5]),
				 stoi(roomStr[6])));
    /*
    ** The reason this if statement exists is because there might be an empty line at the end of
    ** the file. An empty line is not a valid room, so it prevents it from creating a new invalid
    ** room.
    */
  }
    
  inputStream.close(); //closes the file, as this is always needed
}

void Game::CharacterCreation(){

  //gets the character's name (can have spaces)
  string name = "";
  cout << "Please enter your character's name: ";
  getline(cin, name);

  //prints the classes available, and you choose which class you want
  int classChoice = 0;
  do{
    cout << "1. Rogue" << endl << "2. Wizard" << endl
	 << "3. Paladin" << endl << "4. Character" << endl
	 << "Select a class: ";
    cin >> classChoice;
  }while((classChoice < FIRST_CLASS) || (classChoice > LAST_CLASS));

  //assigning the appropriate class to your character. it is dynamically allocated
  switch(classChoice){
  case 1:
    m_myCharacter = new Rogue(name, ROGUE_HEALTH);
    break;
  case 2:
    m_myCharacter = new Wizard(name, WIZARD_HEALTH);
    break;
  case 3:
    m_myCharacter = new Paladin(name, PALADIN_HEALTH);
    break;
  case 4:
    m_myCharacter = new Character(name, CHARACTER_HEALTH);
    break;
  }

}

/*
** Sets the current room to 0, as it is where the game should start.
** Sets the number of rests to a constant defined in the header file.
** Sets the number of special attacks to a constant in the header file.
** Sets the monster to a nullptr, since the first room always is peaceful.
** Starts the game loop...
*/
void Game::StartGame(){

  m_curRoom = START_ROOM;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_curMonster = nullptr;
  Action();
}

/*
** Holds the game loop.
** You can search the room, move to different rooms, attack a monster,
** rest, check your stats, or quit the game (which ends the program).
*/
void Game::Action(){

  bool gameLoop = true;
  while(gameLoop){
    int choice = 0;
    
    m_myMap.at(m_curRoom)->PrintRoom();
    if(m_curMonster == nullptr) 
      cout << "This room is peaceful." << endl;
    else 
      cout << "A " << m_curMonster->GetName() << " is in the room." << endl;
    
    do{
      cout << "Enter what you'd like to do." << endl;
      cout << "1. Look" << endl;
      cout << "2. Move" << endl;
      cout << "3. Attack Monster" << endl;
      cout << "4. Rest" << endl;
      cout << "5. Check Stats" << endl;
      cout << "6. Quit" << endl;
      cin >> choice;
    }while((choice < 1) || (choice > 6));
    
    switch(choice){
    case 1:
      //prints the room
      m_myMap.at(m_curRoom)->PrintRoom();
      if(m_curMonster == nullptr) //if there's no monster, say the room is peaceful
	cout << "This room is peaceful." << endl;
      else //if there's a monster, say the room is not peaceful, something roams about.
	cout << "A " << m_curMonster->GetName() << " is in the room." << endl;
      break;
    case 2:
      //move to the next room
      Move();
      break;
    case 3:
      //attack the monster in the room (you can still do this without a monster being present).
      Attack();
      if(m_myCharacter->GetHealth() <= 0)
	gameLoop = false; //ends the game since you've died
      break;
    case 4: //THE REST CASE. There was no mention of a "Rest()" function, so I
      //left it here.
      if(m_curMonster == nullptr){ //checks for a monster, you cannot rest with a monster in the room.
	if(m_numRests > 0){ //if you can rest
	  m_numRests--;
	  m_numSpecial = NUM_SPECIAL;
	  m_myCharacter->SetHealth(m_myCharacter->GetHealth() +
				   REST_HEAL);
	}else{ //if you cannot rest
	  cout << "You don't have anymore rests!" << endl;
	}
      }else{ //if there's a monster, you cannot rest.
	cout << "You cannot rest, there's a monster nearby!" << endl;
      }
      break;
    case 5:
      //prints your character's statistics
      Stats();
      break;
    case 6:
      //ends the game loop.
      gameLoop = false;
      break;
    }
  }
}

Entity* Game::RandomMonster(){

  switch(rand() % 4){ //gets a random number for a random monster.
  case 0: //creates a new dynamically allocated monster, of type Baby Dragon.
    return new BabyDragon(BB_DRAGON_NAME, DRAGON_HEALTH);
    break;
  case 1: //same as above but of type Goblin
    return new Goblin(GOBLIN_NAME, GOBLIN_HEALTH);
    break;
  case 2: //same as above but of type Skeleton
    return new Skeleton(SKELETON_NAME, SKELETON_HEALTH);
    break;
  }
  return nullptr;
  //there is no "case 3" since there's a 25% chance of no monster being present.
}

void Game::Move(){

  //You are moving rooms, you need to deallocate the current monster.
  if(m_curMonster != nullptr){
    delete m_curMonster;
    m_curMonster = nullptr;
  }

  //creates a random monster for the room
  m_curMonster = RandomMonster();

  int newRoomID;
  char direction;
  do{
    cout << "Enter the direction you want to go (N, E, S, W): ";
    cin >> direction; //gets a character to represent the direction
    
    newRoomID = m_myMap.at(m_curRoom)->CheckDirection(direction);
    //at the current room, check if the direction you want to go is valid.
  }while(newRoomID == -1);

  //you've left the loop so you have a valid room ID. Now set it to the current room.
  m_curRoom = newRoomID;
  
}

void Game::Attack(){

  //returns back to the game loop if the monster to attack does not exist
  if(m_curMonster == nullptr){
    cout << "There's no monster to attack!" << endl;
    return;
  }

  bool enemyDied = false; //stores life status of monster
  bool youDied = false; //stores life status of player
  do{
    int attack = -1;
    do{
      cout << "1. Regular attack" << endl
	   << "2. Special attack" << endl
	   << "Enter your choice: ";
      cin >> attack; //user input for which type of attack to do
      if(attack == 2){ //if the user chose special attack
	if(m_numSpecial < 0){ //and you have no special attacks left
	  cout << "You have no more special attacks!" << endl;
	  attack = -1; //repromts
	}else{ //and you have special attacks left
	  if(m_myCharacter->SpecialAttack() == -1){ //check if you're a generic character since
	    // generic characters cannot use a special attack, if so it reprompts
	    cout << "A generic Character cannot special attack." << endl;
	    attack = -1;
	  }
	}
      }
    }while((attack < 1) || (attack > 2));

    switch(attack){
    case 1: // case: regular attack
      attack = m_myCharacter->Attack(); //get attack damage
      cout << m_myCharacter->GetName() << " attacks dealing "
	   << attack << " damage." << endl;
      m_curMonster->SetHealth(m_curMonster->GetHealth() - attack); //sets enemy health
      break;
    case 2: //case: special attack
      attack = m_myCharacter->SpecialAttack(); //get special attack damage
      m_curMonster->SetHealth(m_curMonster->GetHealth() - attack); //sets health
      m_numSpecial--; //you have one less special attack to lose now
      break;
    }
    if(m_curMonster->GetHealth() <= 0) //checks if the monster is dead
      enemyDied = true;

    //if the enemy isn't dead
    if(enemyDied == false){
      int enemyAttack = (rand() % 4); //get a random number. there's a 25% chance the enemy
      // uses a special attack. otherwise just a regular attack.
      switch(enemyAttack){
      case 0: //cases 0-2, regular attack
      case 1:	
      case 2:
	enemyAttack = m_curMonster->Attack(); //gets attack damage
	m_myCharacter->SetHealth(m_myCharacter->GetHealth() -
				 enemyAttack); //sets user's health
	break;
      case 3:
	enemyAttack = m_curMonster->SpecialAttack(); //gets special attack damage
	m_myCharacter->SetHealth(m_myCharacter->GetHealth() -
				 enemyAttack); //sets user's health
	break;
      }
      if(m_myCharacter->GetHealth() <= 0)
	youDied = true; //if you've died, sets flag to say you've died
    }
    
  }while(!enemyDied && !youDied); //while both parties are still alive

  if(enemyDied) //if the enemy was killed, print you win
    cout << m_myCharacter->GetName() << " wins!" << endl;
  else if(youDied) //if you died, print you lost
    cout << m_myCharacter->GetName() << " lost. You've died!" << endl;

  //deallocates the current monster, it does this both if you die or you win.
  delete m_curMonster;
  m_curMonster = nullptr;
}

/*
** Prints the character's statistics
** Shows use of the overloaded insertion operator from Entity
** Prints character's name, current health, amount of rests left
** and amount of special attacks left
*/
void Game::Stats(){

  cout << "-------------------------" << endl
       << *m_myCharacter //overloaded insertion operator to print the name and health
       << "Rests left: " << m_numRests << endl
       << "Special attacks left: " << m_numSpecial << endl
       << "-------------------------" << endl;
    
}
