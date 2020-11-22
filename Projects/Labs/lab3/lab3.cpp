//Title: Lab 3
//Author: Mitchell Angelos
//Lab section: 23
//Description: This is a lab practicing arrays, functions, and logic

#include <iostream>
using namespace std;

void displayNumbers(int arr[], int maxTo);
int makePositive(int array[], int numValues);

int main () {

  const char ogArrayMessage[] = {"Original array: "};
  const char modifiedArray[] = {"Modified array: "};
  const char enterNumber[] = {"Enter a number (0 when done): "};
  const int ENDING_NUMBER = 0; //ends the loop for getting numbers from the user
  const int MAX_SIZE = 100;
  int theArray[MAX_SIZE] = {};
  int currentSize = 0;

  int temp = -1;
  // while the user doesnt enter 0
  while(temp != ENDING_NUMBER){
    // enter a number
    cout << enterNumber;
    cin >> temp;
    if(temp != 0){
      // if the number isn't 0, it adds it to the array, and increments the array location
      theArray[currentSize] = temp;
      currentSize++;
    }
  }

  //ending sequence messages
  cout << ogArrayMessage;
  displayNumbers(theArray, currentSize);
  cout << "The array contains " << makePositive(theArray, currentSize)
       << " negative numbers." << endl;
  cout << modifiedArray;
  displayNumbers(theArray, currentSize);
  
  return 0;
}

void displayNumbers(int arr[], int maxTo){
  //prints all the values in the array
  for(int i = 0; i < maxTo; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int makePositive(int array[], int numValues){
  // the amount of negative numbers
  int negativeCount = 0;
  for(int i = 0; i < numValues; i++){
    // if the value in the array is negative
    if(array[i] < 0){
      // increment the count up by 1
      negativeCount++;
      // make it positive
      array[i] *= -1;
    }
  }
  // return the amount of negatives
  return negativeCount;
}
