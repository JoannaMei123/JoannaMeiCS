#include <iostream>
#include <cstring>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string>

/* 
File: Heap
Creator: Joanna Mei 
Date: 2/21/2024




*/ 



//Creating the main function prototypes
void add(int* heap, int &size, int num);
void heaping (int* heap, int index);
void print (int* heap, int pos, int depth, int size);
int deleteAll(int* heap, int index);


//Masin function
using namespace std;
int main () {

  //Initializing the heap with a size of 101
  int heap[101];
  int size = 0;

  //Setting all slots inside heap to be 0, because otherwise we don't know what is inside
  for (int i = 0; i < 101; i++) {
    heap[i] = 0;
  }

  //Main while function
  while (true){
    int index=0;
    char input[200];
    cout<<"Type F for File, and M for manual numbers" <<endl;
    cin>>input;


    //Manually adds numbers
    if (strcmp(input,"M")==0){
      int numofreps=0;

      cout<<"How many numbers would you like to add: ";
      cin>>numofreps;

      //Numbners less then 100 required
      if(numofreps>100){
  cout<<"You can only add less than 100 numbers"<<endl;
  ;
      }

      else{

  for (int i=0;i<numofreps;i++){
    int numtoadd;
    cout<<"Please enter a number: ";
    cin>>numtoadd;
    add(heap,size,numtoadd);
    print(heap,0,0,size);
    cout<<endl;
    cout<<endl;
  }
      }



    }
    //Getting data from user that they want to input a ffile
    else if (strcmp(input,"F")==0){
      char fileName[100];
      //Typing the file exactly
      cout << "Please enter the file name including the .exe: ";
      cin>>fileName;
      cin.ignore();
      ifstream f;
      f.open(fileName);
      int input=0;

      while (f>>input){
  add(heap,size,input);
  index++;
      }
      f.close();
      print(heap,0,0,size);
    }
    //deleting old heap
    else if(strcmp(input,"LARGEST")==0){

      cout<<deleteAll(heap,index)<<endl;

      size--;
    }

    else if (strcmp(input,"ALL")==0){

      while(heap[index] != 0) {
  cout<<deleteAll(heap, index)<<endl;
      }
      //Nothing in the heap, to set everything to 0
      size=0;
    }
    else if (strcmp(input, "QUIT")==0){
      exit(0);
    }

  }

  }

//Adding heap function
void add (int* heap, int &size, int num) {
 heap[size] = num;
  size++;
  heaping(heap, size-1);
}

//Printing the heap function
void print (int* heap, int pos, int depth, int size) {
  if (pos * 2+2 < size) {
    print (heap, pos * 2+2, depth + 1, size);
  }

  for (int a = 0; a < depth; a++) {
    cout << '\t';
  }
  cout << heap[pos] << endl;
  if (pos * 2+1 < size) {
    print (heap, pos *2+1, depth + 1, size);
  }

}

void heaping (int* heap, int index) {
  int initialIndex=(index-1)/2;
  if(index==0){
    return;
  }
  if(heap[initialIndex]>heap[index]){
    return;
  }
  else{

    swap(heap[initialIndex],heap[index]);
    heaping(heap,initialIndex);
  }

}

//Deleting the heap function
int deleteAll(int* heap, int index) {

  //Setting the first position of the heap to the root
    int root=heap[0];

    int sizes=0;
    while(heap[sizes]!=0){
      sizes++;
    }

    sizes=sizes-1;
  //Figuring out the right node of the index
    int rightNode = index;


    heap[index] = heap[sizes];
    heap[sizes] = 0;

    //if the currentn ode is smaller then the right
    while((heap[rightNode] < heap[rightNode * 2+1]) || (heap[rightNode] < heap[rightNode * 2 + 2])) {

      if (heap[rightNode * 2+1] > heap[rightNode * 2 +2]) {

        int temp = heap[rightNode];
        heap[rightNode] = heap[rightNode*2+1];
        heap[rightNode*2+1] = temp;
        rightNode = rightNode*2+1;
      }

    //Checking but jujst for the right node
      else if (heap[rightNode * 2 +2] > heap[rightNode *2+1]) {

        int temp = heap[rightNode];
        heap[rightNode] = heap[rightNode*2+2];
        heap[rightNode*2+2] = temp; 
        rightNode = rightNode*2+2;
      }
    }

    return root; 

  }
