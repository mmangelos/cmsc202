/* 
 lab10a

 Use this file to implement the templated isDiffOf2Squares function.
 This function takes three args:
   first:  variable of type T (where T is a templated datatype)
   second: variable of type T (where T is also a templated datatype)
   third:  variable of type T (where T is also a templated datatype)

 The function returns an int (either 1, 0, or -1):
   Returns  1 if the difference of the squares of first & second is greater than third
   Returns  0 if the difference of the squares of first & second is equivalent to third
   Returns -1 if the difference of the squares of first & second is less than third.
*/

#include <iostream>
using namespace std;

// Implement the templated isDiffOf2Squares function here: 
template <class T>
int isDiffOf2Squares(T one, T two, T three){

  T oneSq = one * one;
  T twoSq = two * two;
  T diff = oneSq - twoSq;
  if(diff > three){
    return 1;
  }
  if(diff == three){
    return 0;
  }else{
    return -1;
  }
}


//------------templated function definition ends here--------------------

// Do NOT modify main function...use it as reference to help implement
// the isDiffOf2Squares function.

int main() {
  
  unsigned int uVal1 = 10, uVal2 = 5, uVal3 = 10;
  cout << "(Item 1: " << uVal1 << ", Item 2: " << uVal2 << ") compare to item 3: "
       << uVal3 << endl;
  cout << isDiffOf2Squares(uVal1, uVal2, uVal3) << "\t\t\t\t\t expected:  1" << endl
       << endl;

  float fVal1 = 15.0, fVal2 = 14.0, fVal3 = 29;
  cout << "(Item 1: " << fVal1 << ", Item 2: " << fVal2 << ") compare to item 3: "
       << fVal3 << endl;
  cout << isDiffOf2Squares(fVal1, fVal2, fVal3) << "\t\t\t\t\t expected:  0"
       << endl << endl;

  double dVal1 = 15.0, dVal2 = 5.0, dVal3 = 540;
  cout << "(Item 1: " << dVal1 << ", Item 2: " << dVal2 << ") compare to item 3: "
       << dVal3 << endl;
  cout << isDiffOf2Squares(dVal1, dVal2, dVal3) << "\t\t\t\t\t expected: -1"
       << endl << endl;

  int iVal1 = 16, iVal2 = -4, iVal3 = 10;
  cout << "(Item 1: " << iVal1 << ", Item 2: " << iVal2 << ") compare to item 3: "
       << iVal3 << endl;
  cout << isDiffOf2Squares(iVal1, iVal2, iVal3) << "\t\t\t\t\t expected:  1"
       << endl << endl;

  float aVal1 = -45.0, aVal2 = -12.0, aVal3 = 1881;
  cout << "(Item 1: " << aVal1 << ", Item 2: " << aVal2 << ") compare to item 3: "
       << aVal3 << endl;
  cout << isDiffOf2Squares(aVal1, aVal2, aVal3) << "\t\t\t\t\t expected:  0"
       << endl << endl;

  int bVal1 = 7, bVal2 = 10, bVal3 = 3;
  cout << "(Item 1: " << bVal1 << ", Item 2: " << bVal2 << ") compare to item 3: "
       << bVal3 << endl;
  cout << isDiffOf2Squares(bVal1, bVal2, bVal3) << "\t\t\t\t\t expected: -1"
       << endl << endl;

  return 0;

}