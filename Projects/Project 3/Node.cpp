/* Node.cpp
** from Node.h
*/

#include "Node.h"

Node::Node(){
  //makes an "empty" node.
  m_next = nullptr;
  m_value = true;
}

Node::~Node(){
  //The node destructor is supposed to do nothing.
}

Node::Node(bool value){
  //makes a new node with a passed value to it
  m_next = nullptr;
  m_value = value;
}

void Node::ReplaceValue(){
  //replaces m_value with its opposite
  if(m_value == true){
    m_value = false;
  }else if(m_value == false){
    m_value = true;
  }
}

void Node::SetNext(Node* next){
  //sets that node's connector
  m_next = next;
}

Node* Node::GetNext(){
  return m_next;
}

bool Node::GetValue(){
  return m_value;
}
