//lab5.cpp
#include <iostream>
#include "Student.h"
#include <string>
using namespace std;

int main(){

  Student student1;
  Student student2;
  student1.SetName("mitch");
  student1.SetAge(19);
  student1.SetIsBusy(false);
  student2.SetName("nonso");
  student2.SetAge(21);
  student2.SetIsBusy(true);
  
  cout << student1.GetName() << " " << student1.GetAge()
       << " is busy: " << boolalpha << student1.GetIsBusy()
       << endl;
  cout << endl;
  cout << student2.GetName() << " " << student2.GetAge()
       << " is busy: " << student2.GetIsBusy() << endl;
  cout << endl;
  student1.study();
  student2.study();
  student1.age();
  student2.age();
  cout << student1.GetName() << " new age: " << student1.GetAge()
       << endl;
  cout << endl;
  cout << student2.GetName() << " new age: " << student2.GetAge()
       << endl;
  return 0;
}