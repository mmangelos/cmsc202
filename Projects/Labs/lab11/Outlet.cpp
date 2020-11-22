#include "Outlet.h"

//Overloaded constructor
Outlet::Outlet(int cap, string name) {
  cout << "Outlet Constructor: Capacity=" << cap << " Name=" << name << endl;
  m_capacity = cap;
  m_used = 0;
  m_OutletName = name;
  m_OutletItems = new string[cap];
}

//Implement Copy Constructor Here
Outlet::Outlet(const Outlet& source){

  this->m_capacity = source.m_capacity;
  this->m_used = source.m_used;
  this->m_OutletName = source.m_OutletName;
  this->m_OutletItems = new string[m_capacity];
  for(int i = 0; i < m_capacity; i++){
    this->m_OutletItems[i] = source.m_OutletItems[i];
  }
  
}

//Implement Overloaded Assignment Operator Here
Outlet& Outlet::operator=(const Outlet& source){

  this->m_capacity = source.m_capacity;
  this->m_used = source.m_used;
  this->m_OutletName = source.m_OutletName;
  delete[] m_OutletItems;
  this->m_OutletItems = new string[m_capacity];
  for(int i = 0; i < m_capacity; i++){
    this->m_OutletItems[i] = source.m_OutletItems[i];
  }
  return *this;
}

//Implement Destructor Here
Outlet::~Outlet(){

  cout << "Destructor called." << endl;
  delete[] m_OutletItems;
  m_OutletItems = nullptr;
}

void Outlet::insert(const string& itemName) {
  if(m_used == m_capacity) {
    cout<<"The Outlet is full. Cannot add any additional animals."<<endl;
  }
  else  {
    m_OutletItems[m_used] = itemName;
    m_used++;
    cout << "Food Item:" << itemName << " added to the Outlet." << endl;
  }
}

void Outlet::deleteLast(){
  if (m_used == 0){
    cout <<"The Outlet is Empty!" <<endl;
  }
  else{
    m_used--;
    cout <<"Food Item:" <<m_OutletItems[m_used] <<" removed from the Outlet." <<endl;
    m_OutletItems[m_used] = "";
  }
}

void Outlet::setName(const string& name){
  m_OutletName = name;
}

ostream& operator <<(ostream& os, const Outlet& fm) {
  os << "m_capacity: " <<fm.m_capacity <<endl;
  os << "m_used: " <<fm.m_used <<endl;

  os << fm.m_OutletName << " has the following food items:" << endl << " | ";
  for(int i=0;i<fm.m_used; i++) {
    os <<fm.m_OutletItems[i] + " | ";
  }
  return os << endl;
}
