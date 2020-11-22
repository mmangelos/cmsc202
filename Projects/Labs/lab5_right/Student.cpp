#include "Student.h" //Uses class declaration from Student.h

//******Implement the Getters here******

bool Student::GetIsBusy(){
  return m_isBusy;
}

int Student::GetAge(){
  return m_age;
}

string Student::GetName(){
  return m_name;
}

//******Implement the Setters here******

void Student::SetName(string newName){
  m_name = newName;
}

void Student::SetAge(int newAge){
  m_age = newAge;
  if(m_age < 1){
    m_age = 1;
  }
}

void Student::SetIsBusy(bool newBusy){
  m_isBusy = newBusy;
}

//******Implement the Study and Age functions here******

void Student::study(){
  if(GetIsBusy()){
    cout << GetName() << " is already studying!" << endl;
  }else{
    cout << GetName() << " is relaxing right now." << endl;
  }
}

void Student::age(){
  SetAge(GetAge() + 1);
}
