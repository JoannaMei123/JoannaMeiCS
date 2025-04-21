#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*
  Author: Joanna Mei
  Date: March 21st 2025
  This program reads in either a file or input and sorts it in a binary tree
 */

//Class to orgaize the data inside the BinaryNode used for the program
class BinaryNode {
  int data;
  BinaryNode* left;
  BinaryNode* right;

public:
  //Constructors
  BinaryNode(int newData){
    data = newData;
    left = NULL;
    right = NULL;
  }

  //setting the functions and get
  void setLeft(BinaryNode* newLeft){
    left = newLeft;
  }

  void setRight(BinaryNode* newRight){
    right = newRight;
  }

  BinaryNode* getLeft(){
    return left;
  }

  BinaryNode* getRight(){
    return right;
  }

  void setData(int newData){
    data = newData;
  }

  int getData(){
    return data;
  }
};

//Functions used inside the program
void Console(BinaryNode* &tree);
void File(BinaryNode* &tree);
void add(BinaryNode* tree, int data);
void printTree(BinaryNode* tree, int count);
int search(BinaryNode* tree, int searchNum);

//Functions to delete + Next value
BinaryNode* deleteOne(BinaryNode* tree, int deleteNum);
BinaryNode* nextValue(BinaryNode* tree);
int branchCount(BinaryNode* node);

int main() {
  //Initializing variables

  //Used to organize binary tree nodes
  BinaryNode* tree = new BinaryNode(-1);
  char input[15];
  char fileType[10];
  bool running = true;

  //Ask the user for a command
  cout << "Enter a command: ADD, SEARCH, QUIT, DELETE, PRINT" << endl;
  while(running == true){
    cin >> input;

    //Allows inptu to be both ujpper and lowercase
    for(int i=0; i < strlen(input); i++) {
      input[i] = toupper(input[i]);
    }

    if(strcmp(input, "ADD") == false){
      cout << "Enter a input type (console or file)" << endl;
      cin >> fileType;


      for(int i=0; i < strlen(fileType); i++) {
  fileType[i] = toupper(fileType[i]);
      }

      //Asking whether it is a console input (manual) or file input
      if(strcmp(fileType, "CONSOLE") == false){
  Console(tree);
      }
      else if(strcmp(fileType, "FILE") == false){
  File(tree);
      }

      cout << " Branches: " << branchCount(tree) << endl;

      cout << "Enter a command: ADD, SEARCH, QUIT, DELETE, PRINT" << endl;
    }
    else if(strcmp(input, "SEARCH") == false){
        //Asks the user the number to find
      cout << "What number do you seek to find?" << endl;
      int searchNum;
      cin >> searchNum;
      int found = search(tree, searchNum);


      //Searching for the number in the tree
      if(found == searchNum)
  cout << searchNum << " exists in the tree!" << endl;
      else
  cout << searchNum << " does not exist in the tree!" << endl;
      cout << "Enter a command: ADD, SEARCH, QUIT, DELETE, PRINT" << endl;
    }
    else if(strcmp(input, "DELETE") == false){

 //Askikng user what number to delet

      cout << "What number do you want to delete?" << endl;
      int deleteNum;
      cin >> deleteNum;
      int found = search(tree, deleteNum);
      //int root = tree->getData();

      //Double checks to see if number exists in tree
      if(found == deleteNum)
        tree = deleteOne(tree, deleteNum);
      else
        cout << deleteNum << " does not exist in the tree!" << endl;

      cout << "Enter a command: ADD, SEARCH, QUIT, DELETE, PRINT" << endl;
    }
    else if(strcmp(input, "PRINT") == false){
      //Print the whole tree
      printTree(tree, 0);
      cout << "Enter a command (enter add, search, delete, print, or quit)" << endl;
    }
    else if(strcmp(input, "QUIT") == false){
      running = false;
    }
    else{
      cout << "Please enter a valid command:" << endl;
    }
  }

  return 0;
}

//Counting the number of b ranches + leaves in the tree
int branchCount(BinaryNode* node){
  if(!node)
    return 0;
  else if(!node->getLeft() && !node->getRight())
    return 1;
  else
    return branchCount(node->getLeft()) + branchCount(node->getRight());
}

//Functino to take data from the file 
void File(BinaryNode* &tree){
  char* fileName = new char[20];

  //Ask the user to enter the file name
  cout << "Enter the name of the file: (including .exe)" << endl;
  cin >> fileName;
  fstream file;
  file.open(fileName);

  //Command to extract numbers from file
  int input = 0;
  while(file >> input){
    add(tree, input);
  }
  file.close();
}

//Taking input numbers from console
void Console(BinaryNode* &tree){
  bool entering = true;
  char input[10];


  cout << "Enter number from 1-999, type DONE when finished" << endl;


  while(entering){
    cin >> input;
    //Allows lower and upper
    for(int i=0; i < strlen(input); i++) {
      input[i] = toupper(input[i]);
    }

    //Checking if the input is DONE
    bool isNum = true;
    for(int i=0; i<strlen(input); i++){
      if(!isdigit(input[i])){
  isNum = false;
      }
    }

    //Quit loop if DONE
    if(strcmp(input, "DONE") == false){
      entering = false;
    }
    //Else keep on asking for more numbers
    else if(!isNum){
      cout << "Enter number from 1-999, type DONE when finished" << endl;
    }
    else{
      int num = atoi(input);
      add(tree, num);
      cout << "Enter number from 1-999, type DONE when finished" << endl;
    }
  }
}

//Adding stuff to tree!
void add(BinaryNode* tree, int data){
  //Ensuring you are at the root first
  if(tree->getData() == -1) {
    tree->setData(data);
    return;
  }
  else {
    //Functino that checks whether data goes left or right
    if(data < tree->getData() && tree->getLeft()){
      tree = tree->getLeft();
      add(tree, data);
    }
    //Addind node!
    else if(data < tree->getData() && !tree->getLeft()){
      BinaryNode* newNode = new BinaryNode(data);
      tree->setLeft(newNode);
      return;
    }

    //If to the right, check if base of tree
    if(data > tree->getData() && tree->getRight()){
      tree = tree->getRight();
      add(tree, data);
    }
    //Adding node
    else if(data > tree->getData() && !tree->getRight()){
      BinaryNode* newNode = new BinaryNode(data);
      tree->setRight(newNode);
      return;
    }
  }
}

//Function to print out the binary search tree
void printTree(BinaryNode* tree, int count) {
  //Check if there is anything in the tree
  if(!tree || tree->getData() == -1){
    cout << "The tree is empty!" << endl;
    return;
  }

  //Go through the right side of the tree
  if(tree->getRight())
    printTree(tree->getRight(), count+1);

  //Print with right amount of tabs
  for(int i=0; i<count; i++){
    cout << "\t";
  }
  cout << tree->getData() << endl;

  //Go through the left side of the tree
  if(tree->getLeft())
    printTree(tree->getLeft(), count+1);
}

//Checking certain number in tree
int search(BinaryNode* tree, int searchNum) {
  //If the number has been found or the tree is empty
  if(!tree || tree->getData() == searchNum){
    return tree->getData();
  }

  //If the number is bigger, then go right
  if(tree->getData() < searchNum){

    if(!tree->getRight())
      return tree->getData();
    return search(tree->getRight(), searchNum);
  }

  //If the number is smaller, thengo to the left
  else {

    if(!tree->getLeft())
      return tree->getData();
    return search(tree->getLeft(), searchNum);
  }
}

//DSeleting specific node from tree
BinaryNode* deleteOne(BinaryNode* tree, int deleteNum){
  //If the tree is empty
  if(!tree){
    return tree;
  }

  if(tree->getData() < deleteNum){
    tree->setRight(deleteOne(tree->getRight(), deleteNum));
  }

  else if(tree->getData() > deleteNum){
    tree->setLeft(deleteOne(tree->getLeft(), deleteNum));
  }


  else if(tree->getData() == deleteNum){

    if(!tree->getLeft() && !tree->getRight()){
      return NULL;
    }


    else if(!tree->getLeft()){
      BinaryNode* temp = tree->getRight();
      delete tree;
      return temp;
    }
    else if(!tree->getRight()){
      BinaryNode* temp = tree->getLeft();
      delete tree;
      return temp;
    }

    //If two children
    BinaryNode* temp = nextValue(tree->getRight());
    tree->setData(temp->getData());
    tree->setRight(deleteOne(tree->getRight(), temp->getData()));
  }
  return tree;
}

//Finding smalest number in tree
BinaryNode* nextValue(BinaryNode* tree){
  BinaryNode* current = tree;
  //Traverse to the bottom of the tree
  while(current && current->getLeft()){
    current = current->getLeft();
  }
  return current;
}