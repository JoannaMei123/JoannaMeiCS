#include "student.h"
#include "node.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;

/*
  Takes a list of students and manipulates a linked list to add, print, delete and average the gpa of the students inputted
  Author: Joanna Mei
  Date: 1/9/2024
 */

//Intializing functions
void ADD(Node* current, Node* previous, Student* newStudent, Node* &head);
void PRINT(Node* head);
void DELETE(Node* current, Node* previous, int id, Node* &head);
void AVERAGE(Node* current, Node* head, int count, float average);

int main() {
  //Initilization of variables
  Node* head = NULL;
  char input[20];

  while (true) {

    //Using choosing to use commands add, print, delete, average or quit
    cout << "ADD, PRINT, DELETE, AVERAGE or QUIT" << endl;
    cin>>input;
    cin.ignore();

    //Giant iff statement that checks the input of the user, and calls functions. Organization wise this is very efficient. 
    if (strcmp(input, "ADD") == false) {
      char* first= new char[100];
      char* last= new char[100];
      int id;
      float gpa;

      //Getting the inputted information the user does, that will be added to the linked list
      cout << "Please enter the student's first name: ";
      cin.getline(first, 100);

      cout << "Please enter the student's last name: ";
      cin.getline(last, 100);

      cout << "Please enter the student's ID: ";
      cin >> id;
      cin.ignore();

      cout << "Please enter the student's GPA: ";
      cin>>gpa;
      cin.ignore();

      //Makig a new student node that has the first name, last name, id and their gpa
      Student* newStudent = new Student((char*)first, (char*)last, id, (float)gpa);
      cout << endl;

      ADD(head, head, newStudent, head);
    }
    //Prints all the students, unless the list is empty
    else if (strcmp(input, "PRINT") == false) {
        if (head == NULL) {
            cout << "There are no students in the list currently." << endl;
            ;
        }
        else{
            PRINT(head);
        }
    }
    else if (strcmp(input, "DELETE") == false) {
      cout << "Enter in the id of the student you'd like to delete: " << endl;
      int idfordelete = 0;
      cin >> idfordelete;
      cin.ignore();

      DELETE(head, head, idfordelete, head);
    }
    else if (strcmp(input, "AVERAGE") == false) {
      AVERAGE(head, head, 0, 0.0f);
    }
    else if (strcmp(input, "QUIT") == false) {
      exit(0);
    }
  }
  return 0;
}

//Adding in students using a recursion technique
void ADD(Node* current, Node* previous, Student* newStudent, Node* &head) {
    // If the first node of the list is empty, then there are no students in the list
    if (head == NULL) {
        head = new Node(newStudent);

        return;
    }

    if (current == NULL || newStudent->getstudentID() <= current->getStudent()->getstudentID()) {
        Node* newNode = new Node(newStudent);

        // If the current node is equal to null, that means we have reached the end of the list
        if (current == NULL) {
            previous->setNext(newNode);
        } else {

            newNode->setNext(current);
            previous->setNext(newNode);

        }
        return;  
    }


    ADD(current->getNext(), current, newStudent, head);
}

//Function that prints all the students within the linked list
void PRINT(Node* head) {
  if (head == NULL) {
    return;
  }
  else {
    if (head!= NULL) {
      cout<<head->getStudent()->getfirstName()<< " ";
      cout<<head->getStudent()->getlastName()<<",";
      cout<<fixed<<setprecision(2)<<head->getStudent()->getstudentID()<<",";
      cout<<head->getStudent()->getGPA()<<endl;
      PRINT(head->getNext());
    }
  }
}

void AVERAGE(Node* current, Node* head, int count, float average) {
    //If no students are in the list, then there is no average
    if (current == NULL) {

        if (count == 0) {
            cout << "No students to calculate average." << endl;
        //Otherwise, calculate the average GPA
        } else {
            // Ensures the output of the average includes 2 decimal points
            cout.setf(ios::fixed, ios::floatfield);
            cout.setf(ios::showpoint);
            cout.precision(2);
            cout << "Average GPA: " << average / count << endl;
        }
        return;  
    }
    average += current->getStudent()->getGPA();
    count++;  
    AVERAGE(current->getNext(), head, count, average);
}

//Function to delete a student based on the ID inputted
void DELETE(Node* current, Node* pre, int id, Node* &head) {
    // If the list is empty
    if (current == NULL) {
        cout << "Nothing in database" << endl;
        return;
    }

    // If the node to delete these students have been retrieved
    if (current != NULL && current->getStudent()->getstudentID() == id){ 
        // If the node is in the front of the list
        if (head == current) {
            head = current->getNext();
            delete current;
        }
        // If the node is in the middle or end of the list
        else {
            pre->setNext(current->getNext());  
            delete current;  // Delete the current node
        }
        return;  
    }


    DELETE(current->getNext(), current, id, head);
}