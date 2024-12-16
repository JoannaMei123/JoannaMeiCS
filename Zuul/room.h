#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <map>
#include "item.h"
#include <vector>

using namespace std;

class room{
public: 
room();
room(char* roomDescription);

void makeExit(char * direction, room* connectedRoom);

char* getroomDescription();

map <char*, room*> getExit();
int index;
char* playerDirection;
room* connectedRoom;
char* itemName;

void itemFound (char* itemName);
item* newItem;

void placeItem(item* newItem);
void printItem();

vector<item*> items;
map<char*, room*> exits;

char* roomDescription;

void getExitsExisting();
int noItems();

char* itemDescription;
item* matchItem(char* itemDescription);

};
#endif