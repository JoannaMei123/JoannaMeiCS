#ifndef MOVIES_H
#define MOVIES_H


#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;


class movies: public media{
public: 
movies(char*title, char* director, int year, int d, int r);
~movies();



char * movieDirector;
virtual char* getDirector();

int duration;
virtual int getDuration();

int rating;
virtual int getRating();
virtual void printMovie();

};

#endif