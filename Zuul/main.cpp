#include <iostream>
#include <cstring>
#include "room.h" 
#include "item.h"
#include <map>
#include <vector>
#include <memory>

using namespace std;

void goingToPlace(vector<room*>rooms, map<char*, room*> &exits, room* &currentRoom);
void getItem(vector<item*> items, vector<item*> &currentItems, room* &currentRoom);
void getInv(vector<item*>&currentItems, room*&currentRoom);
void dropItem(vector<item*> items, vector<item*> &currentItems, room*&currentRoom);

int main() {
  vector <room*> rooms;
  vector<item*> items;
  vector<item*> currentItems;
  map<char*, room*>exits;
  room* currentRoom; 
  char go[3]="GO";
  char playerDirection[100];

  //Making all the item names
  item* plunger=new item((char*)"Plunger");
  item* key=new item((char*)"Key");
  item* bucket=new item((char*)"Bucket");
  item* pushpin=new item((char*)"pushpin");
  item* rifle=new item((char*)"Rifle");
  item* ladder=new item((char*)"Ladder");


  room* locker= new room((char*)"You are in the locker room");
  room* pool=new room ((char*)"You are at the pool. There seems to be a locked door up north...");
  room* gym=new room((char*)"You are in the gym");
  room* range=new room((char*)"You are now in the range.");


}
