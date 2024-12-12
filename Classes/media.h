#ifndef MEDIA_H
#define MEDIA_H


#include <iostream>
#include <cstring>

using namespace std;


class media{
public: 
media();

char * title;
int year;
media(char*title, int year);
virtual ~media();

virtual char* getTitle();
virtual int getYear();
virtual void printMedia();

};

#endif