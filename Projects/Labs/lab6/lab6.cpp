/**********************
// lab6.cpp
**********************/
#include "Item.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Function Prototypes
// addItems - Fills shopping list with items
void addItems(vector<Item>& myList);

// printList - prints items in order
void printList(vector<Item>& list);

// printListReversed - prints items in reverse order
//void printListReversed(vector<Item> list);

int main(){
  // Creates a vector of shopping items named myShoppingList
  vector<Item> myShoppingList;

  // populate the shoppinglist
  addItems(myShoppingList);

  // prints the list in forward order
  printList(myShoppingList);
  
  // prints the list in reversed order

  
  return 0;
}

// Function Definitions
// Implement addItems here:
void addItems(vector<Item>& myList){

  int itemAmount = 0;
  cout << "Enter how many items are in your shopping cart: ";
  cin >> itemAmount;

  //vector<Item> tempList = &myList;
  for(int i = 0; i < itemAmount; i++){
  //for(vector<Item>::iterator it = list.begin();
  //it < list.end(); ++it){
    
    string name  = "";
    int quantity = 0;
    string store = "";
    cout << "Item " << i+1 << " name: ";
    cin >> name;
    cout << "Item " << i+1 << " quantity: ";
    cin >> quantity;
    cout << "Item " << i+1 << " store: ";
    cin >> store;
    myList.push_back(Item(name, quantity, store));
  }
}


// Implement printList here:
void printList(vector<Item>& list){

  int itemNum = 1;
  for(vector<Item>::iterator it = list.begin();
      it != list.end(); ++it){
    cout << itemNum << ". "
	 << (*it).getQuantity() << " "
	 << (*it).getName() << " - "
	 << (*it).getStore() << endl;
    itemNum++;
  }
}



// Implement printListReversed here:
