#include <iostream>
#include <cstring>
#include <cctype> 

using namespace std;

/*
This program follows the shunting yard algorithm to conver infix to postfix expressions. 

Author: Joanna Mei
Date: 3/7/25

*/

//creating the node structure!
struct node {
    node* next;
    node* right;
    node* left;
    char data;
};

//three main functions to create, delete, and print the stack
void push(node*& head, node* add); 
node* peek(node* head);
void pop(node*& head); 


//the queing functions!
void enqueue(node*& head, char input); 
void dequeue(node*& head); 


//Functions for the shunting yard algorithm
void shuntingYard(node*& head, char* output); 
int order(char operators);

//Building shunting stack stuff
void tree(node*& head);
void prefix(node* head); //originakl formatting for operators
void infix(node* head); 
void postfix(node* head); //where the operators will end ujp



int main() {
  node* head = NULL; //head for the head NULL that will bne utilized everywhere
  while (true){
    char input[101];
    cout<<"Please put an expression using numbers and operators. Please only have single digit nuumbers and use the operators +,-,*,/, ^, and (,)."<<endl;
    cin.getline(input, 100, '\n');
    int length = strlen(input);
//remove spaces
    char output[101];
    int a = 0;
   //run through array to remove spaces
    for (int i = 0; i < length; i++) {
      if (input[i] != ' ') {
  output[a] = input[i];
  a++;
      }
    }

    //Initializing tree and shunting yard functions
    shuntingYard(head, output);
    tree(head);
    while (true){
      char ins[102];
      cout<<endl;
      cout<<endl;
      cout<<"What type of expression would you like to see? PREFIX,INFIX, or POSTFIX?: PLease put in all CAPS."<<endl;;

      cin.getline(ins,100,'\n');//ins;

      //If infix is selected
      if (strcmp(ins,"INFIX")==0){
  cout << "Infix: ";
  infix(head);
      }
      //If postfdix is selected
      else if (strcmp(ins,"POSTFIX")==0){
  cout << "Postfix: ";
  postfix(head);
      }
      //If prefix notation is selected
      else if (strcmp(ins,"PREFIX")==0){
  cout << "Prefix: ";
  prefix(head);
      }
      else if (strcmp(ins,"NEW")==0){
  main();
      }
      else if (strcmp(ins,"QUIT")==0){
  exit(0);
      }
    }
  }
    return 0;
}



//Adding an initial node to the stack
void push(node*& head, node* add) {
  if (head == NULL) {
    head = add;
  }
  else {
    node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    //Creating a new node at the end of the stack
    current->next = add;
  }
}

//Peeking function
node* peek(node* head) {
  node* current = head;
 //Going through the stack list
  while (current != NULL && current->next != NULL) {
    current = current->next;
  }
 //Returning node
  return current;
}

//Creating a pop node for teh stack
void pop(node*& head) {
  node* current = head;

  if (current->next == NULL) {
  //set head to NULL so it has a place to go
    head = NULL;
 //delete node head once the head has a NULL 
    delete current;
    return;
  }

   //keep going until second to last node
  while (current->next->next != NULL) {
    current = current->next;
  }
  //delete the last one
  delete current->next;
  //set value to NULL
  current->next = NULL;
}

//Queueing function for the stack
void enqueue(node*& head, char input) {
  node* brandNode = new node();
  brandNode->data = input;
 brandNode->next = NULL;

  //if head is NULL, the baand new node is now the headc
  if (head == NULL) {
    head = brandNode;
  }
  else {
    node* current = head;

    while (current->next != NULL) {
      current = current->next;
    }

    current->next = brandNode;
  }
}
//Only for expression and not shunting algorithm
void dequeue(node* &head) {
  node*current=head;
  if (current->next== NULL) {
    head = NULL;
    delete current;
  }
  else if (current->next!= NULL) {
    node* temp = current->next;
    head = NULL;
    delete current;
    head = temp;
  }
}

//Order of opreators
int order(char operators) {
  if (operators == '+' || operators == '-') {
    return 1; //Lowest tier 
  }
  else if (operators == '*' || operators == '/') {
    return 2; // Highest prority
  }
  else if (operators=='^'){
    return 3; //Weird one, right assosciated for some reason
  }
  return 0;
}

void shuntingYard(node*& head, char* output) {
  cout << "Input expression: " << output << endl;
  int length = strlen(output);
  //The stack that is used when operating stack isn't
  node* operatorStack = NULL;
  //Goes through number of characters
  for (int i = 0; i < length; i++) {
    //If it is a digit
    if (isdigit(output[i])) {
      //Simply add to output queue
      enqueue(head, output[i]);
    }
    //If parenthesis
    else if (output[i] == '(') {
      node* temp = new node();
      temp->data = '(';
      temp->next = NULL;
      temp->right=NULL;
      temp->left=NULL; 
      //add it operator stack
      push(operatorStack, temp);
    }
    //if it is a closed parentheses
    else if (output[i] == ')') {
    //keep popping stack
      while (peek(operatorStack) && peek(operatorStack)->data != '(') {

  enqueue(head, peek(operatorStack)->data); 
  //if adding to output queue
  pop(operatorStack);
      }

      if (peek(operatorStack) && peek(operatorStack)->data == '(') {

  pop(operatorStack); 
      }
    }
    else if (!isdigit(output[i]) && output[i] != '(' && output[i] != ')') {

      while (peek(operatorStack) && order(peek(operatorStack)->data) >= order(output[i]) &&output[i]!='^') {
  enqueue(head, peek(operatorStack)->data); 
  pop(operatorStack);
      }
      node* temp = new node();
      temp->data = output[i];
      temp->next = NULL;
      temp->right=NULL;
      temp->left=NULL; 
      push(operatorStack, temp);
    }
  }
  while (operatorStack != NULL) {
    //adding operators to ouitput
    enqueue(head, peek(operatorStack)->data);
    pop(operatorStack);
  }
}


//building tree func
void buildTree(node*& head) {
  node* current = head;

  node* operandStack = NULL;
  while (current != NULL) {

    if (isdigit(current->data)) {
      //creating new node and pushing to stack
      node* operandNode = new node();
      operandNode->data = current->data; 
      push(operandStack, operandNode); 
    }
    else {

      node* operatorNode = new node();

      operatorNode->data = current->data;

      //creating right and lefats nodes
      node* rightOperand = new node();

      rightOperand->data=peek(operandStack)->data;

      rightOperand->right=peek(operandStack)->right;

      rightOperand->left=peek(operandStack)->left;

      operatorNode->right = rightOperand;

      pop(operandStack);
      //lefat one now!
      node* leftOperand = new node();
      leftOperand->data=peek(operandStack)->data;
      leftOperand->right=peek(operandStack)->right;
      leftOperand->left=peek(operandStack)->left;

      operatorNode->left = leftOperand;
      pop(operandStack);
    //pushing to stack
      push(operandStack, operatorNode);
    }
    //Move element
    dequeue(head);
    current = head;
  }
  head = peek(operandStack); 
}

//XChanging to infix notation
void infix(node* head) {
  if (head != NULL) {
   //checking on left
    infix(head->left);
    //checking on value
    cout << head->data << " ";
    //calling function on right
    infix(head->right);
  }
}

//changing fix to postfix
void postfix(node* head) {
  if (head != NULL) {
    //call on the left node first
    postfix(head->left);
    //then the right
    postfix(head->right);
    //and then print out head
    cout << head->data << " ";
  }
}

//changing to prefix notation
void prefix(node* head) {
  if (head != NULL) {
    //print the value
    cout << head->data << " ";
    //then call on left
    prefix(head->left);
    //and then call on right
    prefix(head->right);
  }
}