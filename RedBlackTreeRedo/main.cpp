#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

/*
  Author: Joanna Mei
  Date: 5/23/25
  This program reads in either a file or input and sorts it in a binary tree
 */

// Class to orgaize the data inside the node used for the program
struct node{
  int data;
  node* left;
  node* right;
  node* parent;
  char color;
};

  // setting the functions and get
  void insert(node* newNode, char color);
  void printTree(node* newNode, char color);
  void Left(node* newNode, node* checkParent);
  void Right(node* newNode, node* checkParent);
  void fix(node* newNode, node* checkParent);
  void Delete(node* newNode, node* current);
  void search(node* current, char color);


int main() {
  // Initializing variables

  // Used to organize binary tree nodes
  char input[100];
  char* color = "Black";
  bool active = true;
  char fileType[9];

  cout << "Enter a command: ADD, SEARCH, QUIT, DELETE, PRINT" << endl;
  while (active == true) {
    cin >> input;

    //Allows input to be both upper and lowercase
    for (int i = 0; i < strlen(input); i++) {
      input[i] = toupper(input[i]);
    }

    //Structure to check which function user wants to use
    if (strcmp(input, "ADD") == false) {
      cout << "Enter a input type (console or file)" << endl;
      cin >> fileType;

      if (strcmp(fileType, "CONSOLE") == false) {
        int numInputted = 0;
        cout << "How many numbers do you want to enter?" << endl;  
        cin >> numInputted;

        char numbers[numInputted + 1];

      } else if (strcmp(fileType, "FILE") == false) {
        char *fileName = new char[20];

        // Ask the user to enter the file name
        cout << "Enter the name of the file: (including .txt)" << endl;
        cin >> fileName;
        fstream file;
        file.open(fileName);

        // Command to extract numbers from file
        int input = 0;
        char color;
        while (file >> input) {
         insert(input, color);
        }
        file.close();
      }
    } else if (strcmp(input, "SEARCH") == false) {
      cout << "what number do you want to find?" << endl;
      int searchNum;
      cin >> searchNum;
      int found = search(node& current, color);
      if (found == searchNum)
        cout << searchNum << " exists in the tree!" << endl;
      else
        cout << searchNum << " does not exist in the tree!" << endl;
      cout << "Enter a command: ADD, SEARCH, QUIT, DELETE, PRINT" << endl;

    } else if (strcmp(input, "DELETE") == false) {
      if found = search (node& current, color);

      if (found == deleteNum) {
        Delete(node& current, color);
      } else {
        cout << "Node does not exist in the tree!";
      }
    } else if (strcmp(input, "PRINT") == false) {
      printTree(node& current, color);
    } else if (strcmp(input, "QUIT") == false) {
      active = false;
      return 0;
    }
  }
}

//Creating functions that will house all the important functions
void insert(){

}

void Left() {

}

void Right() {

}

void printTree() {

}

void fix() {


}


void Delete() {

}

void search() {

}