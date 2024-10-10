#include <iostream>
#include <cstring>
using namespace std;

/*
  Tic Tac Toe
  By: Joanna Mei
 
  This is tic tac toe. You are able to win by having 3 of your pieces in a vertical, horizontal or diagonal order. Please enter a letter to select the row, and the number for the column
 
*/

//Initialize functions
void printBoard(int move[4][4]);
bool checkWin(int board[4][4], int XO);
bool checkTie(int board[4][4]);

int main() {
  //Initialize variables
  int board[4][4]; //0=Empty, 1=X, 2=O
  char playerInput[3];
  int playerMove= 0; //0=X, 1=O
  bool play = true;
  int letter = 0;
  int number = 0;
  int oWin = 0;
  int xWin = 0;

   
  while (play == true) {
   
    for (int row=0; row<4; row++){
      for (int column=0; column<4; column++) {
        board[row][column] = 0;
playerMove=0;
      }
    }
   
    cout << "This is tic tac toe. You are able to win by having 3 of your pieces in a vertical, horizontal or diagonal order. Please enter a letter to select the row, and the number for the column" << endl;
    cout << "for example a1" << endl;
    while (checkWin(board, 1)!=true && checkWin(board, 2)!=true && checkTie(board)!=true) {
      cin.get(playerInput,3);
      cin.get();
      letter = playerInput[0]-96;
      number = playerInput[1]-48;

      //checks if you inputed the right thing
      if(!((playerInput[0]>='a' && playerInput[0]<='c') && (playerInput[1]>='1' && playerInput[1]<='3') && (board[letter][number]==0))){
cout << "Please enter a LETTER followed by a NUMBER" << endl;
      }
      else { //If you don't know what you are doing, this ensures the program doesn't break and patiently waits for you to enter correctly
//Updates the board
if (playerMove == 0) {
 board[letter][number] = 1;
 playerMove=1;
} else {
 board[letter][number] = 2;
playerMove=0;
}
printBoard(board);

//Check if anybody has won or tied
if (checkWin(board, 1)==true) {
 cout << "X wins" << endl;
 xWin++;
}
if (checkWin(board, 2)==true) {
 cout << "O wins" << endl;
 oWin++;
}
if (checkTie(board)==true) {
 cout << "It's a tie, get better" << endl;
}
if (checkWin(board, 1)!=true && checkWin(board, 2)!=true && checkTie(board)!=true) { //Instructions for the player
 if (playerMove==1) {
   cout << "O Turn: Please enter a letter followed by a number" << endl;
 }
 else {
   cout << "X Turn: Please enter a letter followed by a number" << endl;
 }
}

//Check if the player wants to continue to play
if (checkWin(board, 1)==true || checkWin(board, 2)==true || checkTie(board)==true) {
 cout << "X Wins: " << xWin << endl;
 cout << "O Wins: " << oWin << endl;
 cout << "Do you want to play again (y/n)" << endl;
 cout << "If you say no, then Mr. Galbraith will find you :)";
 char yn[2];
 char n[2];
 n[0]='n';
 n[1]='\0';
 cin.get(yn, 2);
 cin.get();
 
 //Compares the strings with one another, and if it is false (they don't compare) then you stop the while loop
 if (strcmp(yn,n)==false) {
   play = false;
       }
}
      }
    }
  }
}


//Checks if there is a win or not
bool checkWin(int board[4][4], int XO) {
  if (board[1][1]==XO && board[1][2]==XO && board[1][3]==XO) {
    return true;
  }
  else if (board[2][1]==XO && board[2][2]==XO && board[2][3]==XO) {
    return true;
  }
  else if (board[3][1]==XO && board[3][2]==XO && board[3][3]==XO) {
    return true;
  }
  else if (board[1][1]==XO && board[2][1]==XO && board[3][1]==XO) {
    return true;
  }
  else if (board[1][2]==XO && board[2][2]==XO && board[3][2]==XO) {
    return true;
  }
  else if (board[1][3]==XO && board[2][3]==XO && board[3][3]==XO) {
    return true;
  }
  else if (board[1][1]==XO && board[2][2]==XO && board[3][3]==XO) {
    return true;
  }
  else if (board[1][3]==XO && board[2][2]==XO && board[3][1]==XO) {
    return true;
  }
  else {
    return false;
  }
}


// Initializing function that checks for ties
bool checkTie(int board[4][4]) {
  for (int row=1; row<4; row++){
    for (int column=1; column<4; column++) {
      if (board[row][column] == 0) {
return false;
      }
    }
  }
  return true;
}


//This is how I print the board out, the function is called everytime and updated after you input a coordinate
void printBoard(int move[4][4]) {
  cout << "\t1\t2\t3" << endl;
  for (int row=1; row<4; row++) {
    char boardOutput[9];
    char abc = 'a'+(row-1);
    boardOutput[0] = abc;
    boardOutput[1] = '\t';
    int x=2;
    for (int column = 1; column<4; column++) {
      if (move[row][column] == 0) {
boardOutput[x] = ' ';
      } else if (move[row][column] == 1) {
boardOutput[x] = 'X';
      } else {
boardOutput[x] = 'O';
      }
      x++;
      boardOutput[x]= '\t';
      x++;
      boardOutput[8]='\0';
    }
    cout << boardOutput << endl;
  }
}
