/* Game.cpp
** Mitchell Angelos
** Discussion Section 23
** a242@umbc.edu [Campus ID: CV55655]
*/

#include "Game.h"

//constructors
Game::Game(){

  //the game welcomes you, loads the foundables
  //gets wizard's name, plays the entire game.
  cout << WELCOME_MSG << endl;
  LoadFoundables();
  GetWizardName();
  MainMenu();
}

//getters
void Game::GetWizardName(){
  
  string name = "";
  cout << GET_NAME_MSG; 
  getline(cin, name); //gets the name of the wizard, which can have spaces
  m_wizard.SetName(name); //sets the wizard's name
}

//functions
void Game::MainMenu(){

  bool validChoice = false;
  bool gameLoop = true;
  //the loop for the game
  while(gameLoop){
    validChoice = false;
    while(validChoice == false){
      validChoice = true;
      int choice = 0;
      cout << endl <<  GET_ACTION << endl;
      for(int i = 0; i < MENU_LENG; i++){
	cout << i+1 << ". " << MENU[i] << endl; //prints the menu
      }
      cin >> choice; //gets the user's choice
      switch(choice){
      case 1: //wizard info
	WizardStat(); //displays wizard's stats
	break;
      case 2: //list my founds
	PrintMyFoundables(); //prints foundables beaten
	break;
      case 3: //list all founds
	PrintFoundables(); //prints all possible foundables
	break;
      case 4: //attack
	AttackFoundable(); //attacks
	/* if the wizard's level is max (192), you've won
	** you found all foundables */
	if(m_wizard.GetLevel() == NUM_FOUNDABLE){
	  cout << "You've won!" << endl;
	  gameLoop = false; //ends game loop
	}
	break;
      case 5: //quits game
	gameLoop = false;
	break;
      default: //when the user enters something invalid
	validChoice = false;
	cout << INVAL_MENU_CHOICE << endl;
      }
    }
  }

}

int Game::LoadFoundables(){
  
  ifstream inputStream; //inputstream declared
  inputStream.open(FILE_NAME); //opens file to get all foundables from

  //four temp variables for wizard
  string name = "";
  string type = "";
  string rarityStr = "";
  string toughStr = "";
  for(int i = 0; i < NUM_FOUNDABLE; i++){
    name = "";
    type = "";
    rarityStr = "";
    toughStr = "";
    /* gets all 4 wizard stats needed in that one line */
    getline(inputStream, name, SEPERATOR);
    getline(inputStream, type, SEPERATOR);
    getline(inputStream, rarityStr, SEPERATOR);
    getline(inputStream, toughStr);
    //inserts a new foundable
    //also converts strings to ints using stoi()
    m_allFoundables[i] = Foundable(name, type, stoi(rarityStr), stoi(toughStr));
  }
  
  inputStream.close(); //closes the file since this is always needed
  cout << NUM_FOUNDABLE << " foundables loaded." << endl;
  return 0;
}

void Game::PrintFoundables(){

  //iterates through all possible foundables and prints them
  for(int i = 0; i < NUM_FOUNDABLE; i++){
    Foundable temp = m_allFoundables[i]; //temporary holder for specific foundable
    cout << i+1 << ". " << temp.GetName() << " | " << temp.GetType() << " | "
	 << temp.GetRarity() << " | " << temp.GetToughness() << endl;
  }
  
}

void Game::WizardStat(){
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2); //these three lines makes it so doubles are "x.xx"

  cout << "*******************************" << endl;
  cout << WIZ_STAT_MSG << m_wizard.GetName() << endl; //prints the name
  cout << "Level: " << m_wizard.GetLevel() << endl; // prints level
  cout << "Toughness: " << m_wizard.GetToughness() << endl; // prints toughness
  cout << "Foundables found: " << m_wizard.GetWins() <<endl;  // prints how many foundables beaten
  cout << "Wins: " << m_wizard.GetWins() // prints wins
       << " Losses: " << m_wizard.GetLosses() << endl; //prints losses (in same line)
  if(m_wizard.GetLosses() + m_wizard.GetWins() == 0){
    cout << "Win rate: 0.00%" << endl; //prints if no attacks have been done
  }else{ // prints proper win rate with two decimal places
    cout << "Win rate: " << (double(m_wizard.GetWins())
			     / double(m_wizard.GetLosses()
				      + m_wizard.GetWins())) * 100 << "%" << endl;
  }
  cout << "*******************************" << endl;
}

void Game::PrintMyFoundables(){

  cout << "Defeated foundables" << endl;
  m_wizard.PrintMyFoundables(); // prints all foundables the  wizard has defeated
}

void Game::AttackFoundable(){

  bool valid = false;
  int randFndbl = 0;
  int rarity = -1;
  int totalRarity = 0;
  int defeatedRarity = 0;
  int myRarity = 0;
  while(valid == false){
    valid = true;
    cout << GET_RARITY;
    cin >> rarity; // gets rarity user wants to fight
    
    if(rarity > 0 && rarity < 6){ // if valid rarity
      for(int i = 0; i < NUM_FOUNDABLE; i++){
	if(m_allFoundables[i].GetRarity() == rarity){
	  //finds all defeated foundables of that rarity
	  if(m_wizard.CheckFoundable(m_allFoundables[i])){
	    defeatedRarity++;
	  }
	  // all possible foundables of that rarity
	  totalRarity++;
	}
      }
      /* if the amount of defeated foundables of that rarity is
      ** is equal to the amount of possible foundables to fight
      ** of that rarity, prompt user. they will re-enter valid
      ** rarity. */
      if(defeatedRarity == totalRarity){
	cout << RARITY_UNAV << endl;
	valid = false;
      }
    }else{ // if it's not a valid rarity, prompt user to enter it again
      valid = false;
    }
    
  }

  // once a valid rarity is chosen
  valid = false;
  while(valid == false){
    // find random place to look in all possible foundables
    randFndbl = rand() % NUM_FOUNDABLE;
    // if that random foundable has the same rarity as you chose
    if(m_allFoundables[randFndbl].GetRarity() == rarity){
      // fight it!
      valid = m_wizard.AttackFoundable(m_allFoundables[randFndbl]);
    }
  }
}
