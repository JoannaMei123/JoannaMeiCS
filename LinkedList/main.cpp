#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>

/*
  This code is used to check the h and cpp files of the node and student. There are pre inputted information in the list that can be easily changed by altering the name and numbers. This test is ran to ensure the nodes are working properly

Author: Joanna Mei
Date: 12/12/24



  */

using namespace std;
int main() {



  //Forcing information to check if it works
  Student * forcedStudent = new Student((char*)"Bob", (char*)"Jones", 120392, 4);

  char firstName[100];
  char lastName[100];


  strcpy(firstName, forcedStudent-> getfirstName());
  strcpy(lastName, forcedStudent ->getlastName());

  cout << firstName <<endl;
  cout << lastName <<endl;
  cout << forcedStudent->getstudentID() <<endl;;
  cout << forcedStudent -> getGPA() <<endl;

  //Creating a new "test" node that will be used to run the test
  Node* testNode = new Node(forcedStudent);

  //Pointing node to the new student
  testNode -> setStudent(forcedStudent);

  cout << "People in list" <<endl;
  cout << testNode -> getStudent() <<endl;


  Student * secondforcedStudent = new Student((char*)"Diya", (char*)"Shah", 192833, 5);
  Node* secondtestNode = new Node(secondforcedStudent);

  //Pointing first node to the second node of information
  testNode -> setNext(secondtestNode);
  cout <<"This is who was added to list, and everything in it" <<endl;
  cout << testNode->getStudent() << "," << testNode->getNext()->getStudent()<<endl;
}


