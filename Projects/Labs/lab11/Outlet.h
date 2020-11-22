#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
using namespace std;

static const int MAX_NO_OF_ITEM =5;

class Outlet {
 public:
  //Overloaded Constructor
  //**Notice** this constructor has a name and capacity with default values, therefore,
  //a default constructor is not required (and it will cause a ambiguity error)
  Outlet(int capacity = MAX_NO_OF_ITEM, string name = "KFC Outlets");

  //Copy Constructor
  Outlet(const Outlet& source);

  //Overloaded Assignment Operator
  Outlet& operator=(const Outlet& source);

  //Destructor
  ~Outlet();

  //Inserts a food item into a Outlet
  void insert(const string& Outlet);

  //Removes the last food item from the Outlet
  void deleteLast();

  //Sets the name of the Outlet
  void setName(const string& name);

  //Friend Function that is an overloaded << operator
  friend ostream& operator<<(ostream& os, const Outlet& rg); //Overloaded << Operator
 private:
  int m_capacity; //Max capacity of the Outlet
  int m_used; //Current used capacity of Outlet
  string m_OutletName; //String name of the Outlet
  string* m_OutletItems; //Array of names of food items in Outlet
};

#endif // RESTAURANT_H
