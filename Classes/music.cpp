#include <iostream>
#include "music.h"

using namespace std;

music::music(char*title, int year, char* newar, int newdur, char* newpub):media(title,year) {
  publisher = new char[100];
  strcpy(publisher, newpub);  

  artist = new char[100];
  strcpy(artist, newar);

 duration = newdur;
}

music::~music() {
  delete[] publisher;

  delete[] artist;
}

char * music::getPublisher(){
  return publisher;
}

char * music::getArtist(){
  return artist;
}

int music::getDuration() {
  return duration;
}

void music::printMusic() {
 cout << "Media Type: Music" << endl;
 cout << "Title: " << title << endl;
 cout << "Publisher: " << publisher << endl;
 cout << "Year: " << year << endl;
 cout << "Artist: " << artist << endl;
 cout << "Duration" << duration << endl;

}