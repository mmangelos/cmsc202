/* DecayList.cpp
** from DecayList.h
*/

#include "DecayList.h"

DecayList::DecayList(){
  //sets the start to a nullptr and the size to 0
  m_head = nullptr;
  m_size = 0;
}

DecayList::~DecayList(){

  //iterates through all nodes and deletes them all
  Node* current = m_head;
  if(m_size == 0){
    return;
  }
  while(current != nullptr){
    Node* next = current->GetNext();
    delete current;
    current = nullptr;
    current = next;
    m_size--;
  }
}

int DecayList::GetSize(){
  return m_size;
}

void DecayList::InvertValue(int index){
  //iterates to the nodes in question, flips its value
  Node* newNode = m_head;
  for(int i = 1; i < index; i++){
    newNode = newNode->GetNext();
  }
  newNode->ReplaceValue();
}

bool DecayList::PrintDecayList(){

  //if the list is empty, return false
  if(m_head == nullptr){
    return false;
  }

  //iterates through all values and creates a list
  Node* temp = m_head;
  cout << DIVIDER;
  while(temp->GetNext() != nullptr){
    cout << temp->GetValue() << DIVIDER;
    temp = temp->GetNext();
  }
  cout << temp->GetValue() << DIVIDER << endl;
  
  return true;
  
}

int DecayList::TraverseList(bool passedVal){

  Node* temp = m_head;
  int removedNodes = 0;
  int tempIndex = 0;
  int streak = 0;
  for(int i = 0; i < m_size; i++){

    if(temp->GetValue() == passedVal){
      streak++;
      if(streak == 1){
	tempIndex = i;
      }
      if(streak == NUM_CONSECUTIVE){
	removedNodes += RemoveNodes(tempIndex, NUM_CONSECUTIVE);
	cout << NUM_CONSECUTIVE << " nodes removed after traversing the list." << endl;
	i = m_size;
      }
    }else{
      streak = 0;
    }
    temp = temp->GetNext();
  }

  return removedNodes;

}

int DecayList::RemoveNodes(int start, int removeAmount){

  Node* current = m_head;
  Node* connectFront;
  bool attemptHeadDel = false;
  for(int i = 0; i < start; i++){
    connectFront = current;
    current = current->GetNext();
  }
  
  for(int j = 0; j < removeAmount; j++){
    Node* next = current->GetNext();
    if(current != m_head){
      delete current;
      m_size -= 1;
    }else{
      attemptHeadDel = true;
    }
    current = next;
  }
  
  if(attemptHeadDel == true){
    m_head = current;
    m_size -= 1;
  }else{
    connectFront->SetNext(current);
  }
  
  return NUM_CONSECUTIVE;
}

bool DecayList::CheckEmpty(){

  //if the list is size 0, return true
  if(m_size == 0){
    return true;
  }else{
    return false;
  }

}

void DecayList::InsertEnd(Node* newNode){

  Node* temp = m_head;
  if(m_head == nullptr){
    m_head = newNode; //if the list is empty, set the first element to the new node
  }else{
    while(temp->GetNext() != nullptr){
      temp = temp->GetNext(); //iterates through list until the last element is found
    }
    temp->SetNext(newNode); //sets new element at the last place
  }
  m_size++; //increases size of list
  
}
