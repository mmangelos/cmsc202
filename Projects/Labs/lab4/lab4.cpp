#include <iostream>

using namespace std;

//Declare constants here
const int MAX_MINE = 10;
const int GET_PER_MINE = 60;
const int GEM_COST = 100;
//Add Prototypes for mineGold and buyGems here
void mineGold(int &numGold);
void buyGems(int* numGold, int* numGems);

int main(){
    int numGold = 0;
    int numGems = 0;

    cout << "Welcome to the Gold Mining Game!" << endl;
    mineGold(numGold);

    cout << "You've mined " << numGold << " gold!" << endl; 
    cout << "Trade your gold for gems!" << endl;
    buyGems(&numGold, &numGems);

    cout << "You have " << numGold << " gold and " << numGems << " gems!" << endl;
}


//Define your functions here
void mineGold(int &numGold){

  int tempMine = 11;
  bool keepGoing = true;
  while(keepGoing == true){
    keepGoing = false;
    cout << "How many times would you like to mine for gold?" << endl;
    cin >> tempMine;
    if(tempMine > MAX_MINE){
      cout << "You're too tired to mine that much!" << endl;
      keepGoing = true;
    }
  }
  numGold = tempMine * GET_PER_MINE;
  
}

void buyGems(int* numGold, int* numGems){

  int goldAmount = *numGold;
  int gemsAmount = *numGems;
  int buying = 10000;
  bool keepGoing = true;
  while(keepGoing == true){
    keepGoing = false;
    cout << "How many gems would you like to buy?" << endl;
    cin >> buying;
    if(buying < 0){
      cout << "You cannot buy negative gems!" << endl;
      keepGoing = true;
    }
    if((buying * GEM_COST) > goldAmount){
      cout << "You cannot buy that much!" << endl;
      keepGoing = true;
    }
  }
  *numGold = goldAmount - (buying * GEM_COST);
  *numGems = buying;
}
