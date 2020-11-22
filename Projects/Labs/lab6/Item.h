/**********************
// Item.h
**********************/
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item{
 public:
  // Default Constructor
  Item();
  // Overloaded Constructor
  Item(string name, int quantity, string store);

  string getName();
  int getQuantity();
  string getStore();

  void setName(string name);
  void setQuantity(int quantity);
  void setStore(string store);
  
 private:
  string m_name;
  int m_quantity;
  string m_store;
};

#endif
