#ifndef TQUEUE_CPP
#define TQUEUE_CPP

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: ClearData
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Empty m_data
  void ClearData();
  //Name: Enqueue
  //Desc: Adds item to the back of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue
  //NOTE: You may implement to only deal with dereferenced pointers
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (ascending)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****



/*
** Default constructor for Tqueue
** Dynamically allocates m_data with type T,
** size N.
** Sets both front and back to 0 to show an empty
** Tqueue.
*/
template <class T, int N>
Tqueue<T,N>::Tqueue(){
  m_data = new T[N];
  m_front = 0;
  m_back = 0;
}

/*
** Tqueue copy constructor
** Makes a unique, but equal, copy of the passed Tqueue.
*/
template <class T, int N>
Tqueue<T,N>::Tqueue(const Tqueue<T,N>& x){

  this->m_data = new T[N];
  for(int i = 0; i < N; i++){
    this->m_data[i] = x.m_data[i];
  }
  this->m_front = x.m_front;
  this->m_back = x.m_back;
}

/*
** Tqueue destructor
** Deallocates m_data
*/
template <class T, int N>
Tqueue<T,N>::~Tqueue(){
  delete[] m_data;
  m_data = nullptr;
}

/*
** ClearData()
** Deallocates m_data and creates a new empty m_data
** Sets front and back to 0
*/
template <class T, int N>
void Tqueue<T,N>::ClearData(){
  delete[] m_data;
  m_data = new T[N];
  m_front = 0;
  m_back = 0;
}

/*
** Enqueue()
** Adds data to the back of the queue.
*/
template <class T, int N>
void Tqueue<T,N>::Enqueue(T data){

  if(IsFull() == 1)
    return;
  m_data[m_back] = data;
  m_back++;
}

/*
** Dequeue()
** Removes data from the front and shifts all data back one place
*/
template <class T, int N>
void Tqueue<T,N>::Dequeue(){

  if(IsEmpty() == 1)
    return;
  for(int i = 0; i < m_back; i++){
    m_data[i] = m_data[i+1];
  }
  m_back--;
}

/*
** Sort()
** Sorts all the data
*/
template <class T, int N>
void Tqueue<T,N>::Sort(){
  
  if(m_back <= 1)
    return;
  
  for(int i = 0; i < m_back - 1; i++){
    for(int j = 0; j < m_back - i - 1; j++){
      
      if(*m_data[j+1] < *m_data[j]){
	
	T temp = m_data[j];
	m_data[j] = m_data[j+1];
	m_data[j+1] = temp;
      }
      
    }
  }
}

/*
** IsEmpty()
** If the queue is empty, aka no elements in m_data,
** it returns 1, 0 otherwise.
*/
template <class T, int N>
int Tqueue<T,N>::IsEmpty(){
  if(m_back == 0)
    return 1;
  return 0;
}

/*
** IsFull()
** If the queue is full, aka no more elements can go in m_data,
** it returns 1, 0 otherwise.
*/
template <class T, int N>
int Tqueue<T,N>::IsFull(){
  if(m_back == N)
    return 1;
  return 0;
}

/*
** Size()
** Returns m_back, the amount of elements in m_data.
*/
template <class T, int N>
int Tqueue<T,N>::Size(){
  return m_back;
}

/*
** Overloaded equals operator
** Takes an existing Tqueue, clears it and copies all
** elements and attributes from the passed Tqueue.
*/
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=(Tqueue<T,N> y){
  this->m_front = y.m_front;
  this->m_back = y.m_back;
  delete[] m_data;
  this->m_data = nullptr;
  this->m_data = new T[N];
  for(int i = 0; i < N; i++){
    this->m_data[i] = y.m_data[i];
  }
  return *this;
}

/*
** Overloaded [] operator
** Returns the data at index x.
*/
template <class T, int N>
T& Tqueue<T,N>::operator[](int x){
  return m_data[x];
}




/*
// To test just Lqueue follow these instructions:
//   1.  Uncomment out int main below
//   2.  make Tqueue
//   3.  ./Tqueue (try valgrind too!)


int main () {
  //Test 1 - Default Constructor and Push
  cout << "Test 1 - Default Constructor and Push Running" << endl;
  //Test Default Constructor
  Tqueue <int, 10> newTQ1;
  //Push 4 nodes into Lqueue
  newTQ1.Enqueue(45);
  newTQ1.Enqueue(20);
  newTQ1.Enqueue(86);
  newTQ1.Enqueue(2);
  newTQ1.Enqueue(852);
  newTQ1.Enqueue(4);
  newTQ1.Enqueue(3);
  newTQ1.Enqueue(10);
  newTQ1.Enqueue(8);
  newTQ1.Enqueue(400);
  
  cout << endl;
  
  //Test 2 - Copy Constructor and Assignment Operator
  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;
  //Test Copy constructor
  Tqueue <int, 10> newTQ2(newTQ1);
  //Test Overloaded Assignment Operator
  Tqueue <int, 10> newTQ3;
  newTQ3 = newTQ1;
  cout << endl;

  //Test 3 - Test Dequeue
  cout << "Test 3 - Dequeue" << endl;
  //cout << newTQ1.Dequeue() << endl;
  newTQ1.Dequeue();
  cout << endl;
  newTQ1.Sort();
  //Test 4 - Test Overloaded []
  cout << "Test 4 - Test Overloaded []" << endl;
  for(int i = 0; i < newTQ1.Size(); i++){
    cout << newTQ1[i] << endl;
  }
  //Test 5 - Test Size and ClearData
  cout << "Test 5 - Size and ClearData" << endl;
  //Test GetSize()
  cout << "Outputting the size" << endl;
  cout << newTQ1.Size() << endl;
  //Test Clear()
  cout << "Clearing all nodes" << endl;
  newTQ1.ClearData();
  cout << "Outputting the size" << endl;
  cout << newTQ1.Size() << endl;
  cout << endl;
  
  return 0;
}
*/
#endif
