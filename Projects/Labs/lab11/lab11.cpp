#include "Outlet.h"

int main() {
  Outlet KFC; //Constructor Called (overloaded constructor with default values)

  KFC.insert("Chicken"); //Adds Chicken to KFC
  KFC.insert("Fries"); //Adds Fries to KFC
  KFC.insert("Milkshake"); //Adds Milkshake to KFC

  cout <<"KFC: " << KFC << endl; //Calls the overloaded << operator to output the Outlet List

  cout << "ChickFilA created using overloaded constructor" << endl;
  Outlet ChickFilA(4, "ChickFilA"); //Constructor called (uses overloaded constructor)

  ChickFilA.insert("Sandwich"); 
  ChickFilA.insert("Salad");
  cout << "ChickFilA: " << ChickFilA << endl;//Calls overloaded << operator outputs Outlet List

  //Overloaded assignment invoked
  cout <<"Copy Constructor called to create InNOut (copying ChickFilA)"<<endl;
  Outlet InNOut(ChickFilA);

  //Deletes entries from InNOut
  InNOut.setName("InNOut");
  InNOut.deleteLast();
  cout << "InNOut: " << InNOut << endl;

  cout << "Overloaded assignment invoked on ChickFilA (copying KFC)" << endl;
  ChickFilA = KFC; 

  cout << "Changing name of KFC to ChickFilA " << endl;
  ChickFilA.setName("ChickFilA"); 
  cout << "ChickFilA: " << ChickFilA << endl;

  cout<<"=========================================="<<endl;
  cout<<"Final Lists:" <<endl;
  cout <<"KFC: " << KFC << endl;
  cout << "ChickFilA: " << ChickFilA << endl;
  cout << "InNOut: " << InNOut << endl;

}
