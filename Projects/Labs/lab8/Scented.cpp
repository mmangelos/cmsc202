#include "Scented.h"
#include <iostream>

Scented::Scented(string name, double burnRate, string flavor)
  :Candle(name,burnRate)
{
 m_flavor = flavor;
}

string Scented::GetFlavor(){
  return m_flavor;
}

void Scented::SetFlavor(string flavor){
  m_flavor = flavor;
}

void Scented::SetLit(bool isLit){
  m_isLit = isLit;
  if(m_isLit == "Yes"){
    cout << "The delicious smell of " << m_flavor << "!" << endl;
  }else{
    cout << "The scented candle is not lit yet." << endl;
  }
}
