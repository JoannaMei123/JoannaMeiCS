#include "student.h"
#include <cstring>
#include <iostream>

using namespace std;

// Code given by my partner: Ayan Masud

class Node {
public:
  Node *next;       // next node
  Student *student; // student in this node

  Node(Student *newstudent); // assign the student this node is carrying in the
                             // constructor
  Node *getNext();           // get the next node from this class
  void setNext(Node *newnext); // set the next node for this class
  Student *getStudent();       // get the student this node is carrying
  ~Node();                     // destructor
};