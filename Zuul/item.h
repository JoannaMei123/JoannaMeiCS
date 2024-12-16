#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class item{
public:

char *itemInfo;
item(char* itemInfo);
char* getItemInfo();


};
#endif