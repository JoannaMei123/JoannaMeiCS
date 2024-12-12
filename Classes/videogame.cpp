#include <iostream>
#include "videogame.h"

using namespace std;

videogame::videogame(char*title, int year, char* p, int r):media(title,year) {
  publisher = new char[100];
  strcpy(publisher, p);  
  rating = r;

}

videogame::~videogame() {
  delete[] publisher;
}

char * videogame::getPublisher(){
  return publisher;
}

int videogame::getRating() {
  return rating;
}
void videogame::printVideogame() {
 cout << "Media Type: Videogame" << endl;
 cout << "Title: " << title << endl;
 cout << "Publisher: " << publisher << endl;
 cout << "Year: " << year << endl;
 cout << "Rating: " << rating << endl; 

}