#include "Node.h"


Node::Node(Student *newStudent) {
  next = NULL;
  studentValue = newStudent;
}

Node::~Node(){
  delete &studentValue;
  next = NULL;
}

void Node::setStudent(Student * newStudent) {
  studentValue = newStudent;
}

//Initializing functions and returning values to be taken from in main.cpp
char* Node::getStudent() {
  return studentValue -> getfirstName();
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

Node* Node::getNext() {
  return next;
}