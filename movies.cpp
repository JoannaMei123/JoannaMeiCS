#include <iostream>
#include "movies.h"

//Subclasses of MEDIA (takes the h file)
//Used to get functions for ever different constraint 
using namespace std;

movies::movies(char*title, char* director, int year, int d, int r):media(title,year) {
  movieDirector = new char[100];
  strcpy(movieDirector, director);  
  duration = d;
  rating = r;

}

movies::~movies() {
  delete[] movieDirector;
}

char * movies::getDirector(){
  return movieDirector;
}

int movies::getDuration() {
  return duration;
}

int movies::getRating() {
  return rating;
}
void movies::printMovie() {
 cout << "Media Type: Movie" << endl;
 cout << "Title: " << title << endl;
 cout << "Director: " << movieDirector << endl;
 cout << "Year: " << year << endl;
 cout << "Duration: " << duration << endl;
 cout << "Rating: " << rating << endl; 

}