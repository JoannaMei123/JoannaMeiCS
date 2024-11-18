#ifndef ROOMS_H
#define ROOMS_H
#include <iostream>

using namespace std;

class Rooms{
 public:
  Rooms(int roomPosition, char*name, map<char, int> e, vector<Item*> i);


  virtual int roomPosition();
  virtual void printDescription();
  virtual void removeItems(char* it);
  virtual void addItems(char* newIt);





}
