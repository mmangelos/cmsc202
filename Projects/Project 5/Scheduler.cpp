/*
** Scheduler.cpp 
** from Scheduler.h
*/

#include "Scheduler.h"

/*
** Scheduler default constructor
** Prompts user to give a file name to load and initializes the name.
*/
Scheduler::Scheduler(){
  
  cout << "Please enter the file name to load: ";
  cin >> m_fileName;
  m_name = "";
}

/*
** Scheduler overloaded constructor
** Sets file name to the passed paramater file name
*/
Scheduler::Scheduler(string fileName){

  m_fileName = fileName;
  m_name = "";
}

/*
** Scheduler destructor
** Iterates through all Class objects in the vector
** and deallocates them.
*/
Scheduler::~Scheduler(){
  
  for(Class* c : m_classes){
    delete c;
    c = nullptr;
  }
}

/*
** LoadFile()
** Iterates through the file specified by user and
** adds a new student to a Class
*/
void Scheduler::LoadFile(){
  
  ifstream inputStream(m_fileName);

  string fName, lName, id, course;
  while(getline(inputStream, fName, ',') &&
	getline(inputStream, lName, ',') &&
	getline(inputStream, id, ',') &&
	getline(inputStream, course, '\n')){
    AddStudent(new Student(fName, lName, stoi(id)), course);
  }
    
  inputStream.close();
}

/*
** MainMenu()
** Prints the main menu and the user can choose which
** action to carry out
*/
void Scheduler::MainMenu(){

  bool gameLoop = true;
  int choice = -1;
  do{
    choice = -1;
    cout << " -- Menu --" << endl
	 << "1. Display All Courses" << endl
	 << "2. Display a Specific Course" << endl
	 << "3. Search for a Specific Student" << endl
	 << "4. Sort Roster" << endl
	 << "5. Quit" << endl;
    cin >> choice;

    cout << endl;
    switch(choice){
    case 1:
      DisplayCourses();
      break;
    case 2:
      DisplaySpecific();
      break;
    case 3:
      SearchStudent();
      break;
    case 4:
      SortRoster();
      break;
    case 5:
      gameLoop = false;
      break;
    default:
      cout << "Please enter a valid choice." << endl;
    }

    cout << endl;
    
  }while(gameLoop == true);
  
}

/*
** DisplayCourses()
** Iteratoes through all Classes in the vector
** and prints their name and section
*/
void Scheduler::DisplayCourses(){

  cout << "All courses:" << endl;
  for(unsigned i = 0; i < m_classes.size(); i++){
    cout << *m_classes.at(i) << endl;
  }
}

/*
** DisplaySpecific()
** Prompts user to pick which course they want
** to print the students of.
*/
void Scheduler::DisplaySpecific(){

  int choice = -1;
  do{
    cout << "Courses:" << endl;
    for(unsigned i = 0; i < m_classes.size(); i++){
      cout << i+1 << ". " << *m_classes.at(i) << endl;
    }
    cout << "Enter which class to display: ";
    cin >> choice;
  }while((choice < 1) || (choice > int(m_classes.size())));

  m_classes.at(choice - 1)->DisplayStudents();
}

/*
** Prompts user for what student to find in all the classes
** and prints whichever class that name was found in.
** This function is case-sensitive.
*/
void Scheduler::SearchStudent(){

  string student;
  cout << "Enter a student you wish to search for: ";
  cin >> student;

  bool isFound = false;
  for(unsigned i = 0; i < m_classes.size(); i++){
    if(m_classes.at(i)->SearchClass(student)){
      cout << *m_classes.at(i) << endl;
      isFound = true;
    }
  }
  
  if(!isFound){
    cout << "The entry \"" << student << "\" was not found." << endl;
  }
}

/*
** SortRoster()
** Asks user which roster they want to sort (waitlist included)
** and sorts said roster.
*/
void Scheduler::SortRoster(){

  int classToSort = -1;
  do{
    for(unsigned i = 0; i < m_classes.size(); i++){
      cout << i+1 << ". " << *m_classes.at(i) << endl;
    }
    cout << "Enter which roster to sort: ";
    cin >> classToSort;
  }while((classToSort < 1) || (classToSort > int(m_classes.size())));

  m_classes.at(classToSort - 1)->SortStudents();
}

/*
** Start()
** Calls load file and main menu, starting the
** user's experience of the program.
*/
void Scheduler::Start(){
  
  this->LoadFile();
  this->MainMenu();
}

/*
** FindClass
** Using the string class that's passed, this function
** returns the index of the Class to put the user into.
*/
int Scheduler::FindClass(string c){
  for(int i = int(m_classes.size()) - 1; i >= 0; i--){
    if((m_classes.at(i)->GetName() == c) &&
       (!m_classes.at(i)->IsRosterFull() ||
	!m_classes.at(i)->IsWaitlistFull())){
      return i;
    }
  }
  return -1;
}

/*
** AddStudent()
** A helper function that adds the passed student to a class
** that matches the string class name that is passed.
*/
void Scheduler::AddStudent(Student* newStudent, string c){
  //if there are classes in the vector
  if(m_classes.size() != 0){
    int index = FindClass(c); //find index of class to add student to
    if(index == -1){ //if there exists no class to add the student to (or a class is full)
      int newSection = 1;
      for(int i = int(m_classes.size()) - 1; i >= 0; i--){
	//iterate through the classes and find the most recent class with the same name
	if(m_classes.at(i)->GetName() == c){
	  newSection = m_classes.at(i)->GetSection() + 1; //make a new section number
	  i = -1;
	}
      }
      m_classes.push_back(new Class(c, newSection)); //add that class
      m_classes.at(m_classes.size() - 1)->AddStudent(newStudent); //add that student
    }else{
      m_classes.at(index)->AddStudent(newStudent); //adds new student to the index specified      
      if(m_classes.at(index)->IsRosterFull() ||
	 m_classes.at(index)->IsWaitlistFull()){ //if the class is full in both rosters	
	m_classes.push_back(new Class(c, m_classes.at(index)->GetSection() + 1)); //create a new class, same name, new section
	m_classes.at(index)->TransferWaitToRoster(*m_classes.at(m_classes.size() - 1)); //transfer all waitlisted students to new class.
      }
    }
  }else{
    //if there are no classes, add the first class to the vector
    m_classes.push_back(new Class(c, 1));
    m_classes.at(0)->AddStudent(newStudent);
  }
}
