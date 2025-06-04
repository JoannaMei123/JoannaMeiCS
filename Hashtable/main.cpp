#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

/* Hash table
  2/2/25
  Joanna Mei

  You are tasked to create a student list. You can either add a student, print all the students. delete\
 students or quit trying. Below are the instructions for each command, and what they do. 

 + Implementation of Hash table to structure students versus vector list
*/

//struct of Students with firstname, lastname, id, and gpa
struct Students
{
  char first_name[22];
  char last_name[22];
  int id;
  //this is the key 
  int hash;
  float gpa;
  Students* next = NULL;
};

//function prototypes 
void AddName(Students** &hashtable, int &size);
void GenerateName(Students** &hashtable, int &size);
Students** add(Students* student, Students** &hashtable, int &size);
void printName(Students** &hashtable, int &size);
Students** deleteName(Students** &hashtable, int &size);


int main()
{

  //this is the vector that will be passed everywhere
  int size=100;
  //this is the hash table 
  Students** hashtable = new Students*[size];

  srand(time(NULL));
  while (true)
  {
    char input[21];


    cout<<"Would you like to ADD, GENERATE, PRINT, or DELETE a student or would you like to QUIT this program?"<<endl;
    cin>>input;
    //The "ADD" function (When the player types ADD)
    if (strcmp(input,"ADD")==0)
    {
      AddName(hashtable,size);
    }//The "GENERATE" function (When the player types GENERATE)
    else if (strcmp(input, "GENERATE")==0){
      GenerateName(hashtable,size);
    }
    //The "PRINT" function (When the player types PRINT)
    else if (strcmp(input,"PRINT")==0)
    {
      printName(hashtable,size);
    }

    //The "DELETE" function (When the player types DELETE)
    else if(strcmp(input,"DELETE")==0)
    {
      deleteName(hashtable,size);
    }
    //the "QUIT" function (When the player types QUIT)

    else if (strcmp(input,"QUIT")==0)
    {
      exit(0);
    }
  }

}


//manually adding a new student
//same as student list 
void AddName(Students** &hashtable, int &size)
{

  char first_name[22];
  char last_name[22];
  int id;
  float gpa;
  Students* student=new Students();
  cout<<"Please enter the student's first name: ";
  cin>>student->first_name;
  cout<<"Please enter the student's last name: ";
  cin>>student->last_name;
  cout<<"Please enter the student's ID number: ";
  cin>>student->id;
  cout<<"Please enter the student's GPA: ";
  cin>>student->gpa;
 //Putting all values into a vector
  hashtable = add(student, hashtable, size);

}

//adds a student using randomly generated data from input files 
void GenerateName(Students** &hashtable, int &size){
  cout<<"How many students would you like to add?"<<endl;
  int students;
  cin>>students;
  //run a for loop for the amount of students that need to be added 
  for (int i=0; i<students; i++){


    ifstream f("FirstName.txt");
    //Out of 427 because that is the amount of lines in the file
    int num=rand()% 427;
    char firstname[100];
    for (int i = 1; i <= num; i++){
      //get the line that corresponds to that num
      //copy that line into the firstname char array of size firstname 
      f.getline(firstname,sizeof(firstname));
    }
    f.close();

    //same logic for last name 
    ifstream l("LastName.txt");
    int num2=rand()% 441;
    char lastname[100];
    for (int i = 1; i <= num2; i++){
      l.getline(lastname,sizeof(lastname));
    }
    l.close();


//Creating student
    Students* student= new Students();
    strcpy(student->first_name,firstname);
    cout<<student->first_name;
    strcpy(student->last_name,lastname);
    cout<<student->last_name;
    // set the id to a random number
    int id= rand()% 100001;
    student->id=id;
    //set the float to a random double with 2 decimal places
    float gpa = (double)(rand()%50)/10;
    student->gpa = gpa;
    //add to the table and check for collisions and rehash if needed
    hashtable = add(student, hashtable, size);
  }
}

//function to check for collisions and handles any reshasing that may be necessary 
Students** add(Students* student, Students** &hashtable, int &size) {
  //current spot is the students hash 
  Students* current = hashtable[student->hash];
  int collisions = 0;

  // if there is nothing in the current space
  if(current == NULL){    
    //add the student to that hash spot 
    hashtable[student->hash] = student;
  }
  //if something is already there

  else{

    //while the spot is not empty (meaning there is a collision)
    while(current->next!=NULL){
      //keep going to the next spot
      current = current->next;
      //update collisions 
      collisions++;
      //cout<<"A collision happened"<<endl;
    }

    current->next = student;
  }

  if (collisions==3){
   //Rehasing table
    Students** newTable = new Students*[size*2]();
    for (int i=0;i<size;i++){
      Students* currenttemp= hashtable[i];
      while (currenttemp!=NULL){

  int newHash= student->id % (size*2);

        Students* studentToBeCopiedOver= new Students();
        studentToBeCopiedOver->next = NULL;
        strcpy(studentToBeCopiedOver->first_name,currenttemp->first_name);
        strcpy(studentToBeCopiedOver->last_name,currenttemp->last_name);
        studentToBeCopiedOver->id = currenttemp->id;
        studentToBeCopiedOver->gpa = currenttemp->gpa;
        studentToBeCopiedOver->hash=newHash;

  //if slot in the new table with the new hash is empty 
  if (newTable[newHash] == NULL) {
    //add student into that slot 
          newTable[newHash] = studentToBeCopiedOver;
  }
  //if the slot is not empty - that is a problem because that means it is a collision 
  else{
    //set a temp student to that place that is already filled up in the table
     Students* temp = newTable[newHash];
     //while we havent found a spot to put this student keep going here 
     while(temp->next != NULL){
       // keep moving to the next spot 
       temp=temp->next;
     }
     //we found a place! YAY! put the student here 
     temp->next=studentToBeCopiedOver;
  }
  //move to the next one 
  currenttemp=currenttemp->next;
      }
    }
    //delete [] hashtable;  
    hashtable=newTable;
    size*=2;
    collisions=0;
  }
  return hashtable;
}




Students** deleteName(Students** &hashtable, int &size)
{
  cout<<"Please enter the ID of the student you want to delete"<<endl;
  int input;
  cin>>input;
  for (int i=0; i<size; i++){
    if(hashtable[i]!=NULL){
      //cout<<i<<"here"<<endl;
      //first student from which the linked list is created
      //set the currrent student to the first hashtable spot
      Students* current= hashtable[i];
      Students* prev=NULL;
      //if current is not NULL which means the spot is filled 
      while (current!=NULL){
  //if the id is the same as the inputted id
  if(current->id==input){
    //hashtable[i]=NULL;
    //if the previous one has no space 
    if (prev==NULL){
      hashtable[i]=current->next;
    }
    else{
      prev->next=current->next;
    }
    return hashtable; 
    //main();
  }
  //move to the next one
  prev=current;
  current=current->next;
      }
    }
    else{
      ;
    }
  }
  //return the new hashtable
  return hashtable;
}


void printName(Students** &hashtable, int &size)
{
  //go through all the table slots
  for (int i=0; i<size; i++){
    //if there is something in that slot (aka the first person)
    if(hashtable[i]!=NULL){
      //cout<<i<<"here"<<endl;
      //print that person's information
      //this only works for the first person because the rest is a linked list of that first person
      cout<<hashtable[i]->first_name<<" "<<hashtable[i]->last_name<<","<<hashtable[i]->id<<","<<hashtable[i]->gpa<<endl;
      //cout<<hashtable[i]->last_name<<endl;
      Students* current= hashtable[i];
      while (current->next!=NULL){
        current=current->next;
  //now keep moving through the linked list and print out all the information
  cout<<current->first_name<<" "<<current->last_name<<","<<current->id<<","<<current->gpa<<endl;
      }
    }
    else{
      ;
    }
  }
}