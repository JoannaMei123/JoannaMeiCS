#include <iostream>
#include <ctime>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
#include <iterator>

/*

  Student List
  11/5/24
  Joanna Mei

  You are tasked to create a student list. You can either add a student, print all the students. delete students or quit trying. Below are the instructions for each command, and what they do.





 */


using namespace std;

//Creating the struct that stores all the information of the student
struct structureInfo {
  char firstName[100];
  char lastName[100];
  int studentId;
  float GPA;
};


int main() {
  //Initiating vector
  vector<structureInfo> vecList;
  

  
  while (true) {
 
  cout << "Please type a command in the prompt below. Type ADD to create a new entry, PRINT to print the student information, and DELETE to remove the student. If you want to quit the program, enter QUIT" << endl;
  char playerInput[100];

  cin >> playerInput;

  //The "ADD" function (When the player types ADD)
  if (strcmp(playerInput, "ADD") == 0) {
    structureInfo students;
    char firstName [20];
    char lastName [20];
    int studentID;
    float GPA;

    
    cout << "What is the students first name" <<endl;
    cin >> firstName;

    cout << "What is the Students last name" <<endl;
    cin >> lastName;
    
    cout << "What is the students id?" <<endl;
    cin >> studentID;

    cout << "What is their gpa?" <<endl;
    cin >> GPA;

    //Copying the strings that have been entered into the struct
    strcpy (students.firstName, firstName);
    strcpy (students.lastName, lastName);
    students.studentId = studentID;
    students.GPA = GPA;

    //Inserting the students "structure" into the vector
    vecList.push_back(students);
  }

  //Function for the "QUIT" Cmd
  if (strcmp(playerInput, "QUIT") == 0) {
    //print(vecList)
    exit(0);
  }

  //Function for "PRINT" Command
  if (strcmp (playerInput,"PRINT") ==0) {

    //Iterator is the way to loop through vectors
    for (std::vector<structureInfo>:: iterator i= vecList.begin(); i != vecList.end(); i++) {

      //To print you use -> 
      cout <<i -> firstName << " " << i -> lastName << "  " << i -> studentId<< " " << i -> GPA << endl; 
      
    }
    
  }

  //Functionn for "DELETE"
  if (strcmp(playerInput, "DELETE") ==0) {
    int removeStudentID;
    cout << "Which student do you want to remove?" <<endl;
    cin >> removeStudentID;
    int currentIndex = 0;


    //Looping through our vector list
    for (std::vector<structureInfo>:: iterator r = vecList.begin(); r != vecList.end(); r++) {
      if (r -> studentId == removeStudentID) {

	//Takes value of current index
	int value = currentIndex -1;

	//Erases the data inside the vector at the current index value
      	vecList.erase(vecList.begin()+currentIndex);

	break;
      }
    }
    
  } // cmdDelete if state ment

  }  //While Loop Brackjet

 } //  Main Function Bracket



