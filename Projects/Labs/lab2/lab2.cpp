//This is the starting file for CMSC 202 Lab 2
// Add code here

#include <iostream>
using namespace std;

int multiplyByThree(int times);
void divisibleByNine(int check);

int main () {

  int timesThree = multiplyByThree(3);
  cout << timesThree << endl;
  divisibleByNine(timesThree);
  return 0;
}

int multiplyByThree(int times){
  int total = 0;
  int temp = 0;
  for (int i = 0; i < times; i++){
    temp = 0;
    cout << "Please enter an integer: ";
    cin >> temp;
    total += temp;
  }
  return total * 3;
}

void divisibleByNine(int check){
  if(check % 9 == 0){
    cout << "The final value is divisible by nine." << endl;
  }else{
    cout << "The final value is not divisible by nine." << endl;
  }
}
