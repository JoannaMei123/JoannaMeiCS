#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

/*
  Author: Joanna Mei
  Date: March 21st 2025
  This program reads in either a file or input and sorts it in a binary tree
 */

// Class to orgaize the data inside the node used for the program
struct node {
    int data;
    node* left;
    node* right;
    node* parent;
    char color; // 'R' or 'B'

    node(int d) : data(d), left(NULL), right(NULL), parent(NULL), color('R') {}
};

// ---------------------- Function Prototypes ------------------------
void insert(node*& root, node* newNode);
void fixInsert(node*& root, node* current);
void rotateLeft(node*& root, node* x);
void rotateRight(node*& root, node* x);
void printTree(node* root, int space = 0);
node* search(node* root, int val);


int main() {
  // Initializing variables

  // Used to organize binary tree nodes
int main() {
    node* root = NULL;
    char input[100];
    bool active = true;

    cout << "Enter a command: ADD, SEARCH, PRINT, QUIT" << endl;

    while (active) {
        cin >> input;

        // Convert input to uppercase
        for (int i = 0; i < strlen(input); ++i)
            input[i] = toupper(input[i]);

        if (strcmp(input, "ADD") == 0) {
            cout << "Enter input type (CONSOLE or FILE): ";
            char fileType[20];
            cin >> fileType;
            for (int i = 0; i < strlen(fileType); ++i)
                fileType[i] = toupper(fileType[i]);

            if (strcmp(fileType, "CONSOLE") == 0) {
                cout << "How many numbers do you want to enter? ";
                int count;
                cin >> count;
                for (int i = 0; i < count; ++i) {
                    int val;
                    cout << "Enter number " << (i + 1) << ": ";
                    cin >> val;
                    node* newNode = new node(val);
                    insert(root, newNode);
                }
            } else if (strcmp(fileType, "FILE") == 0) {
                cout << "Enter the filename (with .txt): ";
                char fileName[100];
                cin >> fileName;

                ifstream file(fileName);
                if (!file) {
                    cout << "Could not open file." << endl;
                    continue;
                }

                int val;
                while (file >> val) {
                    node* newNode = new node(val);
                    insert(root, newNode);
                }
                file.close();
                cout << "Data loaded from file." << endl;
            }
        } else if (strcmp(input, "SEARCH") == 0) {
            int searchNum;
            cout << "Enter number to search: ";
            cin >> searchNum;
            node* result = search(root, searchNum);
            if (result)
                cout << searchNum << " exists in the tree!" << endl;
            else
                cout << searchNum << " does not exist in the tree!" << endl;

        } else if (strcmp(input, "PRINT") == 0) {
            printTree(root);

        } else if (strcmp(input, "QUIT") == 0) {
            active = false;
        } else {
            cout << "Invalid command. Try again." << endl;
        }

        if (active)
            cout << "\nEnter a command: ADD, SEARCH, PRINT, QUIT" << endl;
    }

    return 0;
}
// Adding stuff to tree!
void insert(node *tree, int data) {
  // Ensuring you are at the root first
  if (tree->getData() == -1) {
    tree->setData(data);
    return;
  } else {
    // Functino that checks whether data goes left or right
    if (data < tree->getData() && tree->getLeft()) {
      tree = tree->getLeft();
      add(tree, data);
    }
    // Addind node!
    else if (data < tree->getData() && !tree->getLeft()) {
      node *newNode = new node(data);
      tree->setLeft(newNode);
      return;
    }

    // If to the right, check if base of tree
    if (data > tree->getData() && tree->getRight()) {
      tree = tree->getRight();
      add(tree, data);
    }
    // Adding node
    else if (data > tree->getData() && !tree->getRight()) {
      node *newNode = new node(data);
      tree->setRight(newNode);
      return;
    }
  }
}

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