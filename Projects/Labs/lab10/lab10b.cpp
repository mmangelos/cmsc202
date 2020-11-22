// lab10b
#include <iostream>
using namespace std;

// Use this file to VIEW the completed templated class Calc.  
// Calc is a class that performs mathematical caculations using its member variables.
// The constructor takes no parameters and sets all member variables to 0.
// SetFirst() and SetSecond() are setters for the Calc member variables.
// Sum() will add up the two member variables AND return their result.
// Product() will multiply the two member variables AND return their result.

template <class T> 
class Calc {
public:
  Calc();
  void ShowResults();
  void SetFirst(T first);
  void SetSecond(T second);
  T Sum();
  T Product();

private:
  T m_first;
  T m_second;
};

// template for the constructor...initialize all member variables to 0.
template <class T> 
Calc<T>::Calc() {
  m_first = 0;
  m_second = 0;
}

template <class T> 
void Calc<T>::ShowResults() {
  cout << "Values are: " << m_first << " and " << m_second << " : " << endl;
  cout << "Their Sum: "     << Sum()     << endl;
  cout << "Their Product: " << Product() << endl;
}
//***********Implement the rest of Calc Here*******************
//Include: SetFirst, SetSecond, Sum, and Product
template <class T>
T Calc<T>::Sum(){
  return m_first + m_second;
}

template <class T>
T Calc<T>::Product(){
  return m_first * m_second;
}

template <class T>
void Calc<T>::SetFirst(T first){
  m_first = first;
}

template <class T>
void Calc<T>::SetSecond(T second){
  m_second = second;
}



//************Do Not Edit Below Here**************************

int main(){
  Calc<int> intCalc;            
  Calc<float> floatCalc;
  
  intCalc.SetFirst(10);
  intCalc.SetSecond(37);

  cout << "Int result: \t\t\t\t (Sum: 47 expected, Product: 370 expected) " << endl;
  intCalc.ShowResults();

  cout << endl;

  floatCalc.SetFirst(33.6);
  floatCalc.SetSecond(42.9);
  
  cout << "Float result: \t\t\t\t (Sum: 76.5 expected, Product: 1441.44 expected) "
       << endl;
  floatCalc.ShowResults();

  return 0;
}
