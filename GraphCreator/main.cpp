#include <iostream>
#include <cstring>

using namespace std;

/*
 * Author: Joanna Mei
 * Date: May 30th
 * This is the graph creator! You can create a graph, add vertices and edges, remove them, print the graph, and find the shortest path between two vertices using Dijkstra's Algorithm
 */

//The original structure that holds the algorithm
struct table {
  char label;
  int shortest;
  char prev;
};

//Initializing functions
bool Empty(int count, char unvisited[]);
int Smallest(table Table[], int count, char unvisited[]);
int locate(char find, char vertices[], int count);

int main(){
  //Initializing the weird matrix and the array of vertices
  int graph[20][20]; 
  char vertices[20];
  int vertexCount = 0;

  //Emptying out the arrays
  for(int i=0; i<20; i++){
    vertices[i] = '\0';
    for(int j=0; j<20; j++){
      graph[i][j] = 0;
    }
  }

  //Ask for user input
  char command[15];
  bool running = true;
  cout << "Enter a command:" << endl;
  cout << "Use the command addV to add a vertex, or addE to add an edge" << endl;
  cout << "removeV to remove vertex, and removeE to remove edge" << endl;
  cout << "'print' (to print the matrix), 'find' (to find the shortest path), or 'quit'" << endl;
  while(running){
    cin >> command;

    //Allow upper and lower case commands
    for(int i=0; i < strlen(command); i++) {
      command[i] = toupper(command[i]);
    }

    //If adding a vertex
    if(strcmp(command, "ADDV") == false){
      //Ask for a label
      cout << "Enter any chracter (A-Z) to enter a vertex" << endl;
      char label;
      cin >> label;
      bool used = false;
      //Check if the label has already been used
      for(int i=0; i<20; i++){
    if(vertices[i] == label){
      cout << "This label has already been used" << endl;
      used = true;
    }
      }

      //Adding to vertices if the label has not been used
      if(!used){
    vertexCount++;
    for(int i=0; i<20; i++){
      if(vertices[i] == '\0'){
        vertices[i] = label;
        break;
      }
    }
      }
      cout << "Enter another command (addV, addE, removeV, removeE, print, find, or quit)" << endl;
    }
    //If adding an edge
    else if(strcmp(command, "ADDE") == false){
      //Asking for vertixes that user wants to connect
      cout << "Enter the two vertices you want to connect (eg. A E)" << endl;
      char v1;
      char v2;
      cin >> v1;
      cin >> v2;
      int v1Index = -1;
      int v2Index = -1;
      int weight = 0;

      //Check if those vertices exist
      if(v1 != v2){
    for(int i=0; i<20; i++){
      if(vertices[i] == v1){
        v1Index = i;
      }
      else if(vertices[i] == v2){
        v2Index = i;
      }
    }

    //If they both exist, ask for the weight of the edge
    if(v1Index != -1 && v2Index != -1){
      cout << "Enter the weight of the edge" << endl;
      cin >> weight;

      //Add the edge to the matrix
      graph[v2Index][v1Index] = weight;
    }
    else{ //If the vertices were missing
      cout << "One of those vertices were not found!" << endl;
    }
      }
      //Two of the vertices were the same
      else
    cout << "You entered two of the same vertices" << endl;
      cout << "Enter another command (addV, addE, removeV, removeE, print, find, or quit)" << endl;
    }
    //If printing the matrix
    else if(strcmp(command, "PRINT") == false){
      //Print out the label of the vertices
      if(vertexCount > 0){
    for(int i=0; i<20; i++){
      if(vertices[i]){
        cout << "\t" << vertices[i];
      }
    }
    cout << endl;
    //Print out the label and the corresponding edges
    for(int i=0; i<20; i++){
      if(vertices[i]){
        cout << vertices[i] << "\t";
      }
      if(vertices[i]){
        for(int j=0; j<20; j++){
          if(j < vertexCount)
        cout << graph[j][i] << "\t";
        }
        cout << endl;
      }
    }
      }
      //If there is nothing in the graph
      else
    cout << "The graph is empty!" << endl;
      cout << "Enter another command (addV, addE, removeV, removeE, print, find, or quit)" << endl;
    }
    //If removing a vertex
    else if(strcmp(command, "REMOVEV") == false){
      //Ask for the label the user wants to remove
      cout << "Enter the vertex you want to remove (eg. A, B, or C)" << endl;
      char remove;
      cin >> remove;
      bool found = false;
      //Find the corresponding vertex
      for(int i=0; i<20; i++){
    if(vertices[i] == remove){ //Once found
      found = true;
      //Delete and shift over the vertex labels
      for(int j=i; j<20; j++){
        vertices[j] = vertices[j+1];
      }
      //Shifting the rows and columns in the matrix
      for(int h=i; h<vertexCount; h++){
        for(int j=0; j<vertexCount; ++j){
          graph[j][h] = graph[j][h+1]; //Rows
        }
        for(int y=0; y<vertexCount; ++y){
          graph[h][y] = graph[h+1][y]; //Columns
        }
      }
      cout << "Removed!" << endl;
      vertexCount--;
    }
      }
