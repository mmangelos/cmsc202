#include <string>
#include <iostream>

using namespace std;

//Convert from Celsius to Fahrenheit
double* CelsiusToFahrenheit(double* CelTemps, int size) {
  double* tempArr = new double[size];
  for(int i = 0; i < size; i++) {
    tempArr[i] = CelTemps[i] * (double(9) / 5) + 32;
  }
  return tempArr;
}

//Conert from Fahrenheit to Celsius
double*  FahrenheitToCelsius(double* FahTemps, int size) {
  double* tempArr = new double[size];
  for(int i = 0; i < size; i++) {
    tempArr[i] = (FahTemps[i] - 32) * (double(5) / 9);
  }
  return tempArr;
}


int main() {

  int size = 5;
  double *tempArr = new double[5];
  for(int i = 0; i < size; i++) {
    tempArr[i] = i;
  }

  for(int i = 0; i < size; i++) {
    cout << tempArr[i] << " ";
  }
  cout << endl;
  
  tempArr = CelsiusToFahrenheit(tempArr,size);  
  
  for(int i = 0; i < size; i++) {
    cout << tempArr[i] << " ";
  }
  cout << endl;

  tempArr = FahrenheitToCelsius(tempArr,size);
  
  for(int i = 0; i < size; i++) {
    cout << tempArr[i] << " ";
  }
  cout << endl;

  delete tempArr;
  tempArr = nullptr;

  return 0;
}
