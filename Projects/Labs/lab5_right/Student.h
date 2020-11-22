#ifndef STUDENT_H //Header Guards or Include Guards
#define STUDENT_H //Protects against multiple inclusion
#include <iostream>
#include <string>

using namespace std;

//Implement Student here:

class Student {
public:
  //functions
  void age();
  void study();
  //setters
  void SetName(string newName);
  void SetAge(int newAge);
  void SetIsBusy(bool newBusy);
  //getters
  string GetName();
  int GetAge();
  bool GetIsBusy();
private:
  string m_name = "";
  int m_age = 0;
  bool m_isBusy = false;
};


#endif
