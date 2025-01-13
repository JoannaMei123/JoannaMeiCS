#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;
class Student{
 public:
  Student();

//Creating variables
  char * firstName;
  char * lastName;
  int studentID;
  float GPA;

  //Initializing the function
  Student(char*firstName, char*lastName, int studentID, float GPA);

  //SEtting up functions within the class
  char * getfirstName();
  char * getlastName();
  int getstudentID();
  float getGPA();
};

#endif