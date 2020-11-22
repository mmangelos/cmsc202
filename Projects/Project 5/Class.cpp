/*
** Class.cpp
** from Class.h
*/

#include "Class.h"

/*
** Class default constructor.
** Initializes the name and section of the class.
*/
Class::Class(){
  m_name = "";
  m_section = 0;
}

/*
** Class overloaded constructor
** Using the two passed parameters for the class name
** and section, this initializes the name and section.
*/
Class::Class(string name, int section){
  m_name = name;
  m_section = section;
}

/*
** Class destructor
** Iterates through the two Tqueue objects and
** deallocates the Students.
*/
Class::~Class(){

  for(int i = 0; i < m_roster.Size(); i++){
    delete m_roster[i];
    m_roster[i] = nullptr;
  }
  for(int i = 0; i < m_waitlist.Size(); i++){
    delete m_waitlist[i];
    m_waitlist[i] = nullptr;
  }
}

/*
** DisplayStudents
** Prints the section name and section
** Prints all enrolled and waitlisted
** students.
*/
void Class::DisplayStudents(){
  
  cout << endl << *this << " Class Roster" << endl
       << "---- Enrolled students ----" << endl;
  for(int i = 0; i < m_roster.Size(); i++){
    cout << *m_roster[i] << endl;
  }
  if(!m_waitlist.IsEmpty()){
    cout << "---- Waitlisted students ----" << endl;
    for(int i = 0; i < m_waitlist.Size(); i++){
      cout << *m_waitlist[i] << endl;
    }
  }else{
    cout << "There are no waitlisted students." << endl;
  }
}
  

/*
** AddStudent
** A function that, based on whichever next seat is open,
** inserts a new Student, the passed parameter, into the class.
*/
bool Class::AddStudent(Student* newStudent){
  if(!IsRosterFull()){
    m_roster.Enqueue(newStudent);
    return true;
  }else if(!IsWaitlistFull()){
    m_waitlist.Enqueue(newStudent);
    return true;
  }
  return false; //if the student couldn't be added
}

/*
** SortStudents
** Sorts the two Tqueue objects of Students
*/
void Class::SortStudents(){
  
  m_roster.Sort();
  if(!m_waitlist.IsEmpty())
    m_waitlist.Sort();
}

/*
** Getter - GetName()
** Returns a string of the name of the class.
*/
string Class::GetName(){
  return m_name;
}

/*
** Setter - SetName()
** Using a passed string, this updates the name.
*/
void Class::SetName(string name){
  m_name = name;
}

/*
** Getter - GetSection()
** Returns an integer with the section of this instance of the Class
*/
int Class::GetSection(){
  return m_section;
}

/*
** Setter - SetSection()
** Using the passed integer, this updates the section.
*/
void Class::SetSection(int section){
  if(section < 1)
    m_section = 1;
  else
    m_section = section;
}

/*
** TransferWaitToRoster
** Iterates through the waitlist and copies them to
** the passed destination Class.
** It then proceeds to clear the data of this Class.
*/
void Class::TransferWaitToRoster(Class& destination){

  for(int i = 0; i < m_waitlist.Size(); i++){
    destination.AddStudent(m_waitlist[i]);
  }
  m_waitlist.ClearData();
}

/*
** IsRosterFull()
** Checks if there's no more spots in the roster.
** Returns true if there's no more spots, false otherwise
*/
bool Class::IsRosterFull(){
  if(m_roster.Size() == ROSTER_MAX)
    return true;
  return false;
}

/*
** IsWaitlistFull()
** Checks if there's no more spots in the waitlist.
** Returns true if there's no more spots, false otherwise.
*/
bool Class::IsWaitlistFull(){
  if(m_waitlist.Size() == WAIT_MAX)
    return true;
  return false;
}

/*
** SearchClass
** Iterates through both the roster and waitlist (if it's not empty)
** to see if the passed string matches any first or last name in the Class.
*/
bool Class::SearchClass(string item){

  for(int i = 0; i < m_roster.Size(); i++){
    if(item == m_roster[i]->GetFName() ||
       item == m_roster[i]->GetLName())
      return true;
  }
  if(m_waitlist.Size() != 0){
    for(int i = 0; i < m_waitlist.Size(); i++){
      if(item == m_waitlist[i]->GetFName() ||
	 item == m_waitlist[i]->GetLName())
	return true;
    }
  }
  return false;
}

/*
** Overloaded insertion operator
** Outputs the name of the class as well as its section.
*/
ostream& operator<<(ostream& output, Class& c){
  output << c.m_name << " - Section " << c.m_section;
  return output;
}
