#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct node {
    int data;
    node* left;  
    node* right;
    node* parent;
    char color;

};

/*
Red black tree!
Date: 5/13/25
Author: Joanna Mei

This program aims to create a red black tree and allow the user to insert, search, delete, and print the tree. The user can also insert numberbers from a file.

+ You are now able to delete nodes from tree!
*/




//  Creating functions! 
node* insert(node*& root, int number);
void checkViolation(node*& root, node*& current);
void print(node* root, int emptyNode);
void Left(node*& turningNode, node*& root);
void Right(node*& turningNode, node*& root);
bool search(node* root, int numberToSearch);
void deleteNode(node*& root, int number);
void deleteHelp(node* root, node* node);
node* lowest(node* root);

int main() {
    node* root = NULL;
    int emptyNode = 0;
    node* current = NULL;
    int number;

    while (true) {
        char input[100];
        cout << "Hello there, what woudl you like to do? Add: MANUALLY, FILE, SEARCH, DELETE, PRINT, QUIT" << endl;
        cin >> input;

      //if statements that check what the user wants to do
        if (strcmp(input, "MANUALLY") == 0) {
            int numberofreps = 0;
            cout << "How many numbers would you like to add? ";
            cin >> numberofreps;
            for (int i = 0; i < numberofreps; i++) {
                cout << "Please enter a number: ";
                cin >> number;
                current = insert(root, number);
                checkViolation(root, current);
                print(root, emptyNode);
                cout << endl;
            }
        } else if (strcmp(input, "DELETE") == 0) {
            cout<<"Which number would you like to delete?: ";
            int number;
            cin>>number;
            deleteNode(root, number);
            print(root, emptyNode);
        } else if (strcmp(input, "SEARCH") == 0) {
            cout << "What number would you like to search for? ";
            cin >> number;
            if (search(root, number)) {
                cout << "Found it: " << number << endl;
            } else {
                cout << "Not found: " << number << endl;
            }
        } else if (strcmp(input, "PRINT") == 0) {
            print(root, emptyNode);
        } else if (strcmp(input, "FILE") == 0) {
            char fileName[100];
            cout << "Please enter the file name along with .txt: ";
            cin >> fileName;
            cin.ignore();
            ifstream f(fileName);
            while (f >> number) {
                current = insert(root, number);
                checkViolation(root, current);
            }
            f.close();
            print(root, emptyNode);
        } else if (strcmp(input, "QUIT") == 0) {
            exit(0);
        }
    }
}

// The searching function which determines if the node exists within the tree, and where it is located
bool search(node* root, int numberToSearch) {
    if (root == NULL) {
        return false;
    }
    if (numberToSearch == root->data) {
        return true;
    }
    if (numberToSearch < root->data) {
        return search(root->left, numberToSearch);
    } else {
        return search(root->right, numberToSearch);
    }
}

// Function that inserts nodes within the tree 
//The default color value is always RED, and later gets changed
node* insert(node*& root, int number) {
    node* current = new node();
    current->data = number;
    current->color = 'R';
    current->left = NULL;
    current->right = NULL;
    current->parent = NULL;

  //Setting all new node colors to RED
    if (root == NULL) {
        root = current;
        return root;
    }

    // Inserting the node into the tree
    if (number < root->data) {
        if (root->left) {
            return insert(root->left, number);
        } else {
            root->left = current;
            current->parent = root;
            return current;
        }
      //Checks roots, if the parent of the newly added node is red, then it cannot be red
    } else {
        if (root->right) {
            return insert(root->right, number);
        } else {
            root->right = current;
            current->parent = root;
            return current;
        }
    }
}

// Pinting the actual tree
void print(node* root, int emptyNode) {
    if (root == NULL) {
        return;
    }
    int count = 5;
   emptyNode += count;
    print(root->right, emptyNode);
    cout << endl;
    for (int i = count; i < emptyNode; i++) {
        cout << " ";
    }
    if (root->color == 'R') {
        cout << root->data << "(R)" << endl;
    } else {
        cout << root->data << "(B)" << endl;
    }
    print(root->left, emptyNode);
}

// A function that finds the lowest node wtiin the tree
node* lowest(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Checks the violations of the red rule in the tree
void checkViolation(node*& root, node*& current) {
    node* parent = NULL;
    node* previousParent = NULL;
    node* relatedNode = NULL;
    while ((current != root) && (current->color != 'B') && (current->parent->color == 'R')) {
      parent = current->parent;
      previousParent = current->parent->parent;
      if (parent == previousParent->left) {
  relatedNode = previousParent->right;

        //Cannot have two red nodes be in a leaf or near each other
  if (relatedNode && relatedNode->color == 'R') {
                previousParent->color = 'R';
                parent->color = 'B';
                relatedNode->color = 'B';
                current = previousParent;
            } else {
                if (current == parent->right) {
                    Left(parent, root);
                    current = parent;
                    parent = current->parent;
                }
                Right(previousParent, root);
                parent->color = 'B';
                previousParent->color = 'R';
                current = parent;
            }
        } else {
            relatedNode = previousParent->left;
            if (relatedNode && relatedNode->color == 'R') {
                previousParent->color = 'R';
                parent->color = 'B';
                relatedNode->color = 'B';
                current = previousParent;
            } else {
                if (current == parent->left) {
                    Right(parent, root);
                    current = parent;
                    parent = current->parent;
                }
                Left(previousParent, root);
                parent->color = 'B';
                previousParent->color = 'R';
                current = parent;
            }
        }
    }
    root->color = 'B';
}

// Function that rotates the nodes left
void Left(node*& turningNode, node*& root) {
    node* rotatiningNode = turningNode->right;
    turningNode->right = rotatiningNode->left;
    if (rotatiningNode->left) {
        rotatiningNode->left->parent = turningNode;
    }
    rotatiningNode->parent = turningNode->parent;

  //If the parent of the turning is NULL then it is allowed to change to the root
    if (turningNode->parent == NULL) {
        root = rotatiningNode;
    } else if (turningNode == turningNode->parent->left) {
        turningNode->parent->left = rotatiningNode;
    } else {
        turningNode->parent->right = rotatiningNode;
    }
    rotatiningNode->left = turningNode;
    turningNode->parent = rotatiningNode;
}

// Right rotation function
void Right(node*& turningNode, node*& root) {
    node* rotatiningNode = turningNode->left;
    turningNode->left = rotatiningNode->right;
    if (rotatiningNode->right) {
        rotatiningNode->right->parent = turningNode;
    }
    rotatiningNode->parent = turningNode->parent;
    if (turningNode->parent == NULL) {
        root = rotatiningNode;
    } else if (turningNode == turningNode->parent->right) {
        turningNode->parent->right = rotatiningNode;
    } else {
        turningNode->parent->left = rotatiningNode;
    }
    rotatiningNode->right = turningNode;
    turningNode->parent = rotatiningNode;
}

//Deleting nodes within a red and black tree 
void deleteNode(node*& root, int value) {
    node* target = root;

    //If the function hasn't found the correct value yet 
    while (target && target->data != value) {
      if (value < target->data){
  target = target->left;
      }
      else{
  target = target->right;
      }
    }

    //If node is not fund
    if (!target){
      return; 

    }; // Node not found


    node* rotatiningNode = target;
    //Color of the original node matters alot
    char rotatiningNodeOriginalColor = rotatiningNode->color;
    node* turningNode = NULL;
    node* turningNodeParent = NULL;

    // When node has children
    if (target->left && target->right) {
        rotatiningNode = lowest(target->right);
        rotatiningNodeOriginalColor = rotatiningNode->color;
        target->data = rotatiningNode->data; // Replace value
        target = rotatiningNode; 
    }

    turningNode = (target->left) ? target->left : target->right;
    turningNodeParent = target->parent;

    if (turningNode){
      turningNode->parent = target->parent;
    }
    if (!target->parent){
      root = turningNode;
    }
    else if (target == target->parent->left){
      target->parent->left = turningNode;
    }
    else{
      target->parent->right = turningNode;
    }
   //Omg the stupid start of the cases of the redblack tree
    if (rotatiningNodeOriginalColor == 'B') {
      //If color is still black, then more manipulation is required
        while (turningNode != root && (!turningNode || turningNode->color == 'B')) {
            if (turningNode == turningNodeParent->left) {
                node* sib = turningNodeParent->right;
                if (sib && sib->color == 'R') {
      //Required rotation because sibling is red and doesn't work
                    sib->color = 'B';
                    turningNodeParent->color = 'R';
                    Left(turningNodeParent, root);
                    sib = turningNodeParent->right;
                }

                if ((!sib->left || sib->left->color == 'B') &&
                    (!sib->right || sib->right->color == 'B')) {
      if (sib) {
        sib->color = 'R';
      }
                    turningNode = turningNodeParent;
                    turningNodeParent = turningNode->parent;
                }

    else {
                    if (!sib->right || sib->right->color == 'B') {
                        if (sib->left) sib->left->color = 'B';
                        sib->color = 'R';
                        Right(sib, root);
                        sib = turningNodeParent->right;
                    }
                    sib->color = turningNodeParent->color;
                    turningNodeParent->color = 'B';
                    if (sib->right) sib->right->color = 'B';
                    Left(turningNodeParent, root);
                    break;
                }
            } else {
                node* sib = turningNodeParent->left;
                if (sib && sib->color == 'R') {
                    sib->color = 'B';
                    turningNodeParent->color = 'R';
                    Right(turningNodeParent, root);
                    sib = turningNodeParent->left;
                }

                if ((!sib->left || sib->left->color == 'B') &&
                    (!sib->right || sib->right->color == 'B')) {
                    if (sib) sib->color = 'R';
                    turningNode = turningNodeParent;
                    turningNodeParent = turningNode->parent;
                } else {
                    if (!sib->left || sib->left->color == 'B') {
                        if (sib->right) sib->right->color = 'B';
                        sib->color = 'R';
                        Left(sib, root);
                        sib = turningNodeParent->left;
                    }
                    sib->color = turningNodeParent->color;
                    turningNodeParent->color = 'B';
                    if (sib->left) sib->left->color = 'B';
                    Right(turningNodeParent, root);
                    break;
                }
            }
        }
        if (turningNode) {
    turningNode->color = 'B';
  }
    }

    //if not then just delete!! simple if it is red 
    delete target;
}