#ifndef NODE_H
#define NODE_H
#include "Student.h"

#include <iostream>
#include <cstring>

using namespace std;

class Node{
 public:
  Node(Student* newStudent);
  ~Node();
  void setStudent (Student * newStudent);
  char* getStudent();
  void setNext(Node * newnext);
  Node* getNext();
 private:

  Student * studentValue;
  Node* next;
};
#endif


