#include <iostream>
#include <ctime>
#include <cstring>


//This is a guessing game, where your objective is to guess the random number from 1-100 in the lowest amount of tries
//The system will notify whether the guess is too high or low

/* 3 Rules for C++
   1. No global variables
   2. No Strings
   3. Avoid usnig mouse
   4. Only use break if you really need, but not recommended
 */
using namespace std;

int main() {
  //srand sets the random number generator based on local computer time (not exactly random but its a manipulation)
  srand(time(NULL));

  //utilizes the rand function to generate a new number from 1-100
  int RandomNumber = rand() % 100 + 1;

  //Setting the game frame with messages to ensure thep player knows what is happening
  //endl is how you break into a new line when printing messages
  cout << "Your objective is to guess the random number from 1-100 in the lowest amount of tries" << endl;
  cout << "The system will notify whether the guess is too high or low" << endl;
  cout << "Please pick a number from 1-100" << endl;
  
  //initializing the variables
  int input = 0;
  int guesses = 0;
  bool continuegame = true;

  
  //while loop for the main program    
  while (input != RandomNumber && continuegame == true) {

    //grabbing a new input (cin) everytime 
    cin >> input;

    //If statements to check whether number is too high or low
    if (input > RandomNumber) {
      cout << "The number you guessed was too high" << endl;
      guesses = guesses + 1;
      cin.clear();
    }
      if (input < RandomNumber) {
      cout << "The number you guessed was too low" << endl;
      guesses = guesses + 1;
      cin.clear();
    }
      if (input == RandomNumber){
      guesses = guesses + 1;
      cout << "Congratulations, it took you "  << guesses << " guesses" <<endl;
      cout << "Would you like to play again?" << endl;
      cout << "Answer y if yes, and n for no" << endl;
      cin.clear();
      guesses = 0;

      //Initializing the continue feature
      char str [2];
      cin >> str;

      //Comparing the input character with the preset answer character of y (standing for yes)
      //If the strcmp returns a 0, then that means the strings are equal. Otherwise, if it returns a 1, then it means they are not equal.
      if ((strcmp(str,"y")) == 0) {
	  guesses = 0;
	  input = 0;
	  RandomNumber = rand() %100 + 1;
	  cout << "Nice! Guess another number" <<endl;
	} else {
	  continuegame == false;
	  cout << "Thanks for playing" << endl;
	}
	  
   }
  } 
}


  

