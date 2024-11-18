#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <cstring>

using namespace std;

class Items{
 public:
  Items(char* tempName);


  char* itemName;
  virtual char* getItemName();

};
#endif
