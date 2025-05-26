#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

/*
    Author: Joanna Mei 
    Date: 5/26/25
    Description: This program creates a red black tree that allows the user to add numbers to the tree, search for numbers, and print the tree.
    Citations: https://www.geeksforgeeks.org/introduction-to-red-black-tree/
    https://www.eecs.umich.edu/courses/eecs380/ALG/red_black.html
    https://www.geeksforgeeks.org/introduction-to-red-black-tree/v
    */

// Creating the original node that stores all the values for the red black tree
struct node {
    int data;
    node* left;
    node* right;
    node* parent;
    char color; //Setting color to either red or black


//Default color on all red black trees start with red
    node(int d) : data(d), left(NULL), right(NULL), parent(NULL), color('R') {}
};

// Declaring all the functino prototypes 
void insert(node*& root, node* newNode);
void fixInsert(node*& root, node* current);
void rotateLeft(node*& root, node* x);
void rotateRight(node*& root, node* x);
void printTree(node* root, int space = 0);
node* search(node* root, int val);

//Delete function prototypes


// Inserting function that adds nodes to tree
void insert(node*& root, node* newNode) {
    node* current = root;
    node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (newNode->data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    //If the parent is null then the node is the root
    newNode->parent = parent;
    if (parent == NULL)
        root = newNode;
    else if (newNode->data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    //Fixing the insert
    fixInsert(root, newNode);
}

// Adding the fixing logic 
void fixInsert(node*& root, node* current) {
    while (current != root && current->parent->color == 'R') {
        node* parent = current->parent;
        node* grandparent = parent->parent;

        //Ensures that two reds are never in order next to each other
        if (parent == grandparent->left) {
            node* uncle = grandparent->right;
            if (uncle && uncle->color == 'R') {
                parent->color = 'B';
                uncle->color = 'B';
                grandparent->color = 'R';
                current = grandparent;
            } else {
                if (current == parent->right) {
                    current = parent;
                    rotateLeft(root, current);
                }
                parent->color = 'B';
                grandparent->color = 'R';
                rotateRight(root, grandparent);
            }
        } else {
            // 
            node* uncle = grandparent->left;
            if (uncle && uncle->color == 'R') {
                parent->color = 'B';
                uncle->color = 'B';
                grandparent->color = 'R';
                current = grandparent;
            } else {
                if (current == parent->left) {
                    current = parent;
                    rotateRight(root, current);
                }
                parent->color = 'B';
                grandparent->color = 'R';
                rotateLeft(root, grandparent);
            }
        }
    }
    root->color = 'B';
}

// Rotating the tree left
void rotateLeft(node*& root, node* x) {
    node* y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;
    if (!x->parent)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

//Rotating right function that fixes the tree
void rotateRight(node*& root, node* x) {
    node* y = x->left;
    x->left = y->right;
    if (y->right)
        y->right->parent = x;

    y->parent = x->parent;
    if (!x->parent)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;

    y->right = x;
    x->parent = y;
}

// Allowing yourself to print the stree!
void printTree(node* root, int space) {
    if (!root)
        return;
    space += 5;
    printTree(root->right, space);
    cout << setw(space) << root->data << "(" << root->color << ")" << endl;
    printTree(root->left, space);
}

// Search function that checks the roots / data and compares with input 
node* search(node* root, int val) {
    while (root != NULL && root->data != val) {
        if (val < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// -Main function 
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

        } else if (strcmp(input, "DELETE") == 0) {
                int delVal;
                cout << "Enter number to delete: ";
                cin >> delVal;
                deleteNode(root, delVal);
        } else {
            cout << "Invalid command. Try again." << endl;
        }

        if (active)
            cout << "\nEnter a command: ADD, SEARCH, PRINT, QUIT, DELETE" << endl;
    }

    return 0;
}
