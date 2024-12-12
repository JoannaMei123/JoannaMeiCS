#ifndef MUSIC_H
#define MUSIC_H


#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;


class music: public media{
public: 
music(char*title, int year, char* ar, int dur, char* pub);
~music();

char* publisher;
virtual char* getPublisher();

char* artist;
virtual char* getArtist();

int duration;
virtual int getDuration();

virtual void printMusic();

};

#endif