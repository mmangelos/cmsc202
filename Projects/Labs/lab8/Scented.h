#ifndef SCENTED_H
#define SCENTED_H
#include <iostream>
#include "Candle.h"
#include "Birthday.h"
using namespace std;

class Scented: public Candle{

 public:
  Scented(string name, double burnRate, string flavor);
  string GetFlavor();
  void SetFlavor(string flavor);
  void SetLit(bool isLit);
 private:
  string m_flavor;
  //bool m_isLit;
};


#endif
