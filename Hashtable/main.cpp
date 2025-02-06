#include <iostream>
#include <ctime>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <iomanip>
#include <fstream>

/*

  Hash table
  2/2/25
  Joanna Mei

  You are tasked to create a student list. You can either add a student, print all the students. delete\
 students or quit trying. Below are the instructions for each command, and what they do. 

 + Implementation of Hash table to structure students versus vector list




 */


using namespace std;

//Creating the struct that stores all the information of the student
struct structureInfo {
  char firstName[100];
  char lastName[100];
  int studentId;
  int hashTableValue;
  float GPA;
  structureInfo * next = NULL;
};



void addCmd(structureInfo **&hashtable, int & size);
void printCmd(structureInfo **&hashtable, int & size);
structureInfo ** addStudent(structureInfo **&hashtable, int & size, structureInfo * newStudent);
structureInfo ** deleteCmd(structureInfo **&hashtable, int & size);
void generateCmd(structureInfo **&hashtable, int &size);


int main() {
  //Initiating vector
  int size = 100;
  srand(time(NULL));
  structureInfo **hashtable = new structureInfo*[size];



  while (true) {

  cout << "Please type a command in the prompt below. Type ADD to create a new entry, PRINT to print th\
e student information, GENERATE to generate a random student, and DELETE to remove the student. If you want to quit the program, enter QUIT" <\
< endl;
  char playerInput[100];

  cin >> playerInput;

  //The "ADD" function (When the player types ADD)
  if (strcmp(playerInput, "ADD") == 0) {
    addCmd(hashtable, size);
  }

  //Function for the "GENERATE" Command
  if (strcmp(playerInput, "GENERATE") == 0) {
    generateCmd(hashtable, size);
  }


  //Function for "PRINT" Command
  if (strcmp (playerInput,"PRINT") ==0) {  
      printCmd(hashtable, size);

   }

  //Functionn for "DELETE"
  if (strcmp(playerInput, "DELETE") ==0) {
    deleteCmd(hashtable, size);
  } // cmdDelete if state ment

  //Function for the "QUIT" Cmd
  if (strcmp(playerInput, "QUIT") == 0) {
    //print(vecList)
    exit(0);
  }

  }  //While Loop Brackjet

 }//  Main Function Bracket

void addCmd(structureInfo **&hashtable, int & size) {


  structureInfo* students = new structureInfo();

    cout << "What is the students first name" <<endl;
    cin >> students->firstName;

    cout << "What is the Students last name" <<endl;
    cin >> students ->lastName;
  cout << "What is the students id?" <<endl;
    cin >> students -> studentId;

    cout << "What is their gpa?" <<endl;
    cin >> students -> GPA;


    //Adding students to our hash table
    hashtable = addStudent(hashtable, size, students);
}

//Checks Collision detection
structureInfo** addStudent(structureInfo **&hashtable, int & size, structureInfo *newStudent) {
  structureInfo* currentStudent = hashtable[newStudent->hashTableValue];
  int hashCollision = 0;

  //If there is no current student
  if (currentStudent == NULL) {
    //If the student is NOT inside the hash table slot, add the student
    hashtable[newStudent->hashTableValue] = newStudent;
  } else {

    //If the students next slot is not empty, then we need to check for collision
    while (currentStudent->next != NULL) {
      currentStudent = currentStudent->next;

      //Add to collision to increase increment
      hashCollision++;
    }
     currentStudent -> next = newStudent;
  }


  //If the collision is equal to 3, then we need to increase the size of the hash table
  if (hashCollision == 3) {
    cout << "Hash table is full" <<endl;

    //Increasing hash table size by multiple of 2
    structureInfo **newHashtable = new structureInfo*[size * 2];
    for (int i = 0; i < size; i++) {
      structureInfo* currenttemp = hashtable[i];
      while (currenttemp != NULL) {
        int newHashValue = newStudent->studentId % (size * 2);
        structureInfo* copiedStudents = new structureInfo();
        copiedStudents -> next = NULL;

        //Copying values into temp variables
        strcpy(copiedStudents->firstName, currenttemp->firstName);
         strcpy(copiedStudents->lastName, currenttemp->lastName);
        copiedStudents->studentId = currenttemp->studentId;
        copiedStudents->GPA = currenttemp->GPA;
        copiedStudents -> hashTableValue = newHashValue;

        //If the new hash table is empty, then add the student
        if (newHashtable[newHashValue] == NULL) {
          newHashtable[newHashValue] = copiedStudents;
        } else{
          //If the new hash table is not empty, then we need to check for collision
          structureInfo* temp = newHashtable[newHashValue];
          while (temp->next != NULL) {
            temp = temp->next;
          }

          temp->next = copiedStudents;
        }
        currenttemp = currenttemp->next;


      }
    }
    //Deleting the old hash table
    hashtable = newHashtable;
    size*=2;
    hashCollision = 0;
  }
  return hashtable;
}


//Printing out
void printCmd(structureInfo **&hashtable, int & size) {
    for (int i = 0; i < size; i++) {

      //If the hashtables index is NOT empty
      if (hashtable[i] != NULL) {
        //Print out all the hash table values stored for that index
        cout << hashtable[i]->firstName << " " << hashtable[i]->lastName << " " <<hashtable[i]->studentId << " " << hashtable[i]->GPA <<endl;

        //Creating a temp variable to store the next value
        structureInfo *currentStudent = hashtable[i];
        while (currentStudent ->next!=NULL) {
          currentStudent = currentStudent ->next;
      //Printing out the next values in the hash
          cout << currentStudent->firstName << "," << currentStudent->lastName << "," <<currentStudent->studentId << ", " << currentStudent->GPA <<endl;
        }
      }
      else {
        ;
      }
    }
}

//Delete command
structureInfo** deleteCmd(structureInfo **&hashtable, int & size) {
    int removeStudentID;
    cout << "Which student do you want to remove?" <<endl;
    cin >> removeStudentID;


  //Creating IF loop to interate through the has table
  for (int i = 0; i < size; i++) {
    if (hashtable[i]!=NULL) {
      //If the structures current student is in the same place as the hashtables current index
      structureInfo* currentStudent = hashtable[i];
      structureInfo* prevStudent = NULL;
      while (currentStudent != NULL) {

        //If the ID is the same as one typed
        if (currentStudent->studentId == removeStudentID) {
          //Add previous student is not there
          if (prevStudent == NULL) {

            //setting current hash table index to the current students "next" slot
            hashtable[i] = currentStudent->next;
          } else {
            prevStudent->next = currentStudent->next;
          }
          return hashtable;
        }
        prevStudent = currentStudent;
        currentStudent = currentStudent -> next;
      }
    }
    else {
      ;
    }
  }
  return hashtable;
}

//Functio to generate NAMES
void generateCmd(structureInfo** &hashtable, int &size){
  cout<<"How many students would you like to add?"<<endl;
  int students;
  cin>>students;
  for (int i=0; i<students; i++){

    ifstream f("FirstName.txt");
    //Pick random name out of the 1000 names within the file (File taken from Fiona Wang's first name file)
    int num=rand()% 1000;
    char firstname[100];
    for (int i = 1; i <= num; i++){ 
      //Making the first name
      f.getline(firstname,sizeof(firstname));
    }
    f.close();

    //last name file was taken from Fiona Wang's Hash Table Last Name file
    ifstream l("LastName.txt");
    int num2=rand()% 1000;
    char lastname[100];
    for (int i = 1; i <= num2; i++){
      l.getline(lastname,sizeof(lastname));
    }
    l.close();



   //Adding new student
    structureInfo* student= new structureInfo();
   //Assigning variables
    strcpy(student->firstName,firstname);
    cout<<student->firstName;
    strcpy(student->lastName,lastname);
    cout<<student->lastName;

    //Creating a fake ID
    int id= rand()% 981023;
    student->studentId=id;

    float gpa = (double)(rand()%50)/10;
    student->GPA = gpa;
    //Adding to table and rehasing if collisions
    hashtable = addStudent(hashtable, size, student);
  }
}