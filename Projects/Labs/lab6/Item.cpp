
/**********************
// Item.cpp
**********************/
#include "Item.h"
using namespace std;

Item::Item(){
  m_name = "Apples";
  m_quantity = 4;
  m_store = "Giant";
}

Item::Item(string name, int quantity, string store){
  m_name = name;
  m_quantity = quantity;
  m_store = store;
}

string Item::getName(){
  return m_name;
}

int Item::getQuantity(){
  return m_quantity;
}

string Item::getStore(){
  return m_store;
}

void Item::setName(string name){
  m_name = name;
}

void Item::setQuantity(int quantity){
  m_quantity = quantity;
}

void Item::setStore(string store){
  m_store = store;
}

