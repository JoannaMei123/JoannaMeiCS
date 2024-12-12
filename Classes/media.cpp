#include <iostream>
#include "media.h"

//Main media class that stores the primary main functions of title and year
using namespace std;

media::media() {
  title = new char[100];
}


media::media(char*newtitle, int newyear) {
  title = new char[100];
  strcpy(title, newtitle);
  year = newyear;
  
}

//Enables media to be deleted 
media::~media() {
  delete[] title;
}

char * media::getTitle(){
  return title;
}

int media::getYear() {
  return year;
}

void media::printMedia() {
  cout << "Title: " << title << endl;
  cout << "Year: " << year << endl;

  
}