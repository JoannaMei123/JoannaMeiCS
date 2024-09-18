#include <iostream>
#include <cstring>
#include <stdio.h>
#include <ctype.h>

//Palindrome!
//Enter a word in this program and it would detect whether the word is a palindrome or not. This program will ignore puncuation, digits and spaces.
using namespace std;
int main() {


  char PlayerInputArray[81];
  char PunctuationRemovedArray[81];
  char ReversedArray[81];
  
  cout << "This program determines whether a word is a palindrome or not" << endl;
  cout << "A palindrome is when a word is the same when reversed backwards. Racecar for example when backwards is just equivalent to racecar" << endl;
  cout << "Please enter a word to check if it is a palidrome: ";
  //getline(cin, PlayerInputArray);
  cin.getline(PlayerInputArray, 80, '\n');
  int length = 0;
  int a = 0;
 
  //Going through the plantey array to remove punctuation

  int j = 0;
  for (int i =0; i <= strlen(PlayerInputArray); i++) {

    //cout << ispunct(PlayerInputArray[i]) << endl;
    int CheckPunc = ispunct(PlayerInputArray[i]);

    //if there isn't a punctuation, and no space, then it would transfer the letters into the new array
    if (ispunct(PlayerInputArray[i]) == false && (PlayerInputArray[i]!= ' ') && isdigit(PlayerInputArray[i])==false) {
      PunctuationRemovedArray[j] = PlayerInputArray[i];
      j++;
    }
  }


  //looping through the length of the array to reverse the characters
  for (int i = strlen(PunctuationRemovedArray)-1; i >= 0; i--) {
    ReversedArray[a] = PunctuationRemovedArray[i];
    a++;
  } ReversedArray[a] = '\0';

  //Getting stuck here for some re
PunctuationRemovedArray[j] = '\0';
//Comparing the punctuation removed array string with the reversed one
   if (strcmp(PunctuationRemovedArray, ReversedArray) == 0) {

    cout << "The word was a palindrome" << endl;
  } else {
     cout <<"The word was not a palindrome" << endl;
   }

}
