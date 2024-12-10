#include <iostream>
#include <cstring>
#include "media.h"
#include "videogame.h"
#include "movies.h"
#include "music.h"
#include <vector>
#include <iterator>

/*
Author: joanna Mei
Date: 11/20
This program combines and uses 5 different classes to add, search and delete media types





  */
using namespace std;

//Initilization of functions
void add (int &x, vector<media*> &database);
void search(vector<media*> &database);
void mediaDelete(vector<media*> &database);

int main() {
  vector<media*> database;


  int x = 0;
  bool active = true;

  char playerInput[7];

  //Inilization of commands
  char ADD[] = "ADD";
  char SEARCH[] = "SEARCH";
  char DELETE[] = "DELETE";
  char QUIT[] = "QUIT";


  cout << "You are in the database and can enter a set of commands to do tasks" <<endl;
  cout << "Enter a command: ADD, SEARCH, DELETE, QUIT" <<endl;

  while (active == true) {


    cin.get(playerInput, 7);
    cin.get();

    //Main function that calls the functionalities of all the commands
    if (strcmp(playerInput, ADD) == 0) {
      add(x, database);
    } else if (strcmp(playerInput, SEARCH) == 0) {
      search(database);
    } else if (strcmp(playerInput, DELETE) == 0) {
      mediaDelete(database);
    } else if (strcmp(playerInput, QUIT) == 0) {
      active = false;
    } 
  }
  return 0;
}

//Add parameter that takes in the vector and the media type
void add (int &x, vector<media*> &database) {
  cout << "Which type of media would you like to add?" <<endl;
  cout << "videogame, music, or movie?" << endl;
  char vg[] = "videogame";
  char mus[] = "music";
  char mov[] = "movie";
  char addType[20];
  cin.get(addType, 20);
  cin.get();

  bool match = false;
  while(match == false) {
    if (strcmp(addType, vg) == 0) {
      char * title = new char[80];
      int year;
      char *publisher = new char[80];
      int r;


      cout << "Enter the videogame title: " <<endl;
      cin.get(title, 80);
      cin.get();

      cout << "Enter the year the videogame was released: " <<endl;
      cin >> year;
      cin.get();

      cout << "Enter the publisher of the video game: " << endl;
      cin.get(publisher,80);
      cin.get();

      cout << "Enter the rating of the video game: " << endl;
      cin >> r;
      cin.get();

      //PUshes the data obtained into the vector list 
      videogame * newvg = new videogame(title, year, publisher, r);
      database.push_back(newvg);
      x++;
      return;
      match = true;
    } else if (strcmp(addType, mus) == 0) {
      char * title = new char[80];
      int year;
      char *artist = new char[80];
      int duration;
      char *publisher = new char[80];

      cout << "Enter the music title: " <<endl;
      cin >> title;


      cout << "Enter the year the music was released: " <<endl;
      cin >> year;
      cin.ignore();
      
      cout << "Enter the artist of the music: " <<endl;
      cin >> artist;

      cout << "Enter the publisher of the music: " << endl;
      cin >> publisher;

      cout << "Enter the duration of the music: " << endl;
      cin >> duration;
      cin.ignore();

      music* newmu = new music(title, year, artist, duration, publisher);
      database.push_back(newmu);
      x++;
      return;
      match=true;
    } else if (strcmp(addType, mov) == 0) {
      char * title = new char[80];
      int year;
      char *director = new char[80];
      int duration;
      int rating;

      cout << "Enter the movie title: " <<endl;
      cin >> title;


      cout << "Enter the director of the movie: " <<endl;
      cin >> director;

      
      cout << "Enter the year the movie was released: " <<endl;
      cin >> year;
      cin.ignore();

      cout << "Enter the duration of the move: " << endl;
      cin >> duration;
      cin.ignore();
   
      cout << "Enter the rating of the movie: " << endl;
      cin >> rating;
      cin.ignore();
      
      movies* newmov = new movies(title, director, year, duration, rating);
      database.push_back(newmov);
      x++;
      match=true;
     
    } else {
      cout << "Enter a valid media type" <<endl;
      cin.get(addType,20);
      cin.get();
    }

    
  }

  
}

//Search Parameter 
void search(vector<media*> &database) {

  //Determines whether the database has any added information to the vector list or not
  if (database.size() == 0) {
    cout << "Database has no information" <<endl;
    return;
  }

  //Searches whether player is searching for title or year
  cout << "Please select whether you are searching for a title or year" <<endl;
  char userSelection;
  char t = 't';
  char isY = 'y';
  bool isYear = false;
  bool found = false;


  
  cin >> userSelection;
  cin.get();


  //Creates new input (actual character array vs singular char)
  char*enteredInput = new char [50];
  int yearInput;

  //Determines if entered t or y
  if (userSelection == t) {
    cout << "Enter a title" << endl;
    cin.getline(enteredInput, 80, '\n');
  } else if (userSelection == isY) {
    cout << "Enter the year" << endl;
    isYear = true;
    cin >> yearInput;
  }




  while(found==false){
    //Go through the database to see what is equal to what the user is typing
    for(int i=0; i<database.size(); i++){
      if (isYear == false && strcmp(enteredInput, database[i]->getTitle()) == 0) {
  database[i]->printMedia();
  found=true;
      } else if (isYear == true){
          for(int i=0; i<database.size(); i++){
            if (database[i]->getYear() == yearInput) {
              database[i]->printMedia();
              found = true;
            }
          }
      }
    }
  }
}

//Delete paramater
void mediaDelete(vector<media*> &database) {
  if (database.size() == 0) {
    cout << "Database has no information" <<endl;
    return;
  }
  cout << "Please select whether you are searching for a title or year" <<endl;
  char userSelection;
  char t = 't';
  char isY = 'y';
  bool isYear = false;
  bool found = false;

  cin >> userSelection;
  cin.get();

  int currentIndex;
  char*enteredInput = new char [50];
  int yearInput;

  if (userSelection == t) {
    cout << "Enter a title" << endl;
    cin.getline(enteredInput, 80, '\n');
  } else if (userSelection == isY) {
    cout << "Enter the year" << endl;
    isYear = true;
    cin >> yearInput;
  }

  //If found is false, then delete command isn't finished yet
  while (found == false) {
    for(int i=0; i<database.size(); i++){
      if (isYear == false && strcmp(enteredInput, database[i]->getTitle()) == 0) {
        database[i]-> printMedia();
        //Once printed selected media, takes the current index to remove from vector list 
        currentIndex = i;


        cout << "Do you want to delete this media?" <<endl;

        char*deleteInput = new char [90];
        //Checks if the delete input is same as YES / no
        cin.getline(deleteInput, 90, '\n');
        if (strcmp(deleteInput, "YES") == 0) {
          cout << "You deleted: " << database[currentIndex]->getTitle() <<endl ;
          database.erase(database.begin() + currentIndex);
          found = true;
          
        } else if (isYear == true) {
          for(int i=0; i<database.size(); i++){
            if (database[i]->getYear() == yearInput) {
              database[i]->printMedia();
              currentIndex = i;
              cout << "Do you want to delete this media?" <<endl;

              char*deleteInput = new char [90];

              cin.getline(deleteInput, 90, '\n');
              if (strcmp(deleteInput, "YES") == 0) {
                cout << "You deleted: " << database[currentIndex]->getTitle() << endl;
                database.erase(database.begin() + currentIndex);
                found = true;
            } 
          } 
        }
        }
      } 
    }
  }
  
}


