#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

//Initializing the entire class
Student::Student(char *newfirstName, char*newlastName, int newstudentID, float \
newGPA) {
  lastName = new char[100];
  firstName = new char [100];
  strcpy(firstName, newfirstName);
  strcpy(lastName, newlastName);
  studentID = newstudentID;
  GPA = newGPA;
}

//Initializing the functions
char *Student::getfirstName() {
  return firstName;
}

char * Student::getlastName() {
  return lastName;
}

int Student::getstudentID() {
  return studentID;

}

float Student::getGPA() {
  return GPA;

}

