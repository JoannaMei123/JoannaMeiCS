#ifndef VIDEOGAME_H
#define VIDEOGAME_H


#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;


class videogame: public media{
public: 
videogame(char*title, int year, char* p, int r);
~videogame();

char* publisher;
virtual char* getPublisher();

int rating;
virtual int getRating();
virtual void printVideogame();

};

#endif