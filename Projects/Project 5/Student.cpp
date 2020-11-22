/*
** Student.cpp
** from Student.h
*/

#include "Student.h"

/*
** Student default constructor
** Initializes an "empty" student object with
** useless values
*/
Student::Student(){
  m_fName = "";
  m_lName = "";
  m_id = 0;
}

/*
** Student overloaded constructor
** Using the three passed parameters
** It initializes a Student object with defind values
** for the first name, last name and ID.
*/
Student::Student(string fName, string lName, int id){
  m_fName = fName;
  m_lName = lName;
  m_id = id;
}

/*
** Getter - GetFName()
** Returns a string of the first name of the student
*/
string Student::GetFName(){
  return m_fName;
}

/*
** Getter - GetLName()
** Returns a string og the last name of the student
*/
string Student::GetLName(){
  return m_lName;
}

/*
** Getter - GetID()
** Returns an integer of the ID of the student
*/
int Student::GetID(){
  return m_id;
}

/*
** Setter - SetFName()
** Using the passed string of the new first name, it updates the 
** first name of the student
*/
void Student::SetFName(string fName){
  m_fName = fName;
}

/*
** Setter - SetLName()
** Using the passed string of the new last name, it updates the
** last name of the student
*/
void Student::SetLName(string lName){
  m_lName = lName;
}

/*
** Setter - SetID()
** Using the passed integer of the new id, it updates the
** ID of the student
*/
void Student::SetID(int id){
  m_id = id;
}

/*
** Overloaded insertion operator
** Outputs the user's full name and ID
*/
ostream& operator<<(ostream& output, Student& st){
  output << st.m_fName << " " << st.m_lName
	 << ", ID: " << st.m_id;
  return output;
}

/*
** Overloaded less than operator
** Checks if the user's last name should go before the other
** user's last name, returns true if need be, false otherwise.
** If the last names are the same, the same comparison is made, but
** using first names instead.
*/
bool operator<(const Student &s1, const Student &s2){

  if(s1.m_lName < s2.m_lName){
    return true;
  }else if(s1.m_lName > s2.m_lName){
    return false;
  }else{
    if(s1.m_fName < s2.m_fName)
      return true;
    else if(s1.m_lName > s2.m_lName)
      return false;
  }
  return true;
}
