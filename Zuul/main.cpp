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
  item* pushpin=new item((char*)"Pushpin");
  item* rifle=new item((char*)"Rifle");
  item* ladder=new item((char*)"Ladder");

  //Upper Half of Rooms
  room* locker= new room((char*)"You are in the locker room");
  room* pool=new room ((char*)"You are at the pool. There seems to be a locked door up north...");
  room* gym=new room((char*)"The stench of sweat fills your lungs. You have entered the gym.");
  room* range=new room((char*)"You are now in the range.");


  //Mid Map
  room* closet = new room((char*) "You have now entered the closet");
  room* cafeteria = new room((char*) "The room around you has expanded... you have entered the cafeteria");
  room* electrical = new room((char*) "Wires, so many wires. You have entered the electrical room.");
  room* garden = new room((char*) "You feel the breeze of the wind. You have entered the garden");

  //Lower Half of Map
   room* attic = new room((char*) "You notice cobwebs above you. You have entered the attic");
   room* office = new room((char*) "The unsettling smell of dust fills your nose. You have entered the office");
   room* bathroom = new room((char*) "You have entered the bathroom");
   room* upperattic = new room((char*) "The eerie sensation engulfs your body. You have entered the upper attic");


   room* start = new room((char*) "It looks familiar");
   room* bathroomsecret = new room((char*) "Whats this? A place to rest?");


    //Creating the exits of all the rooms. Split into each category used. 
    start->makeExit((char*) "north", cafeteria);
    start->makeExit((char*) "south", office);

    cafeteria->makeExit((char*) "south", start);
    cafeteria->makeExit((char*) "north", pool);
    cafeteria->makeExit((char*) "west", closet);
    cafeteria->makeExit((char*) "east", electrical);

    pool->makeExit((char*) "north", range);
    pool->makeExit((char*) "west", locker);
    pool->makeExit((char*) "east", gym);
    pool->makeExit((char*) "south", cafeteria);

    locker->makeExit((char*) "south", closet);
    locker->makeExit((char*) "east", pool);

    closet->makeExit((char*) "east", cafeteria);
    closet->makeExit((char*) "north", locker);

    gym->makeExit((char*) "west", pool);

    electrical->makeExit((char*) "east", garden);  
    electrical->makeExit((char*) "west", cafeteria);  

    garden->makeExit((char*) "west", electrical);

    office->makeExit((char*) "north", start);
    office->makeExit((char*) "west", attic);
    office->makeExit((char*) "east", bathroom);

    attic->makeExit((char*) "north", upperattic);
    attic->makeExit((char*) "east", office);

    upperattic->makeExit((char*) "south", attic);

    bathroom->makeExit((char*) "north", bathroomsecret);
    bathroom->makeExit((char*) "west", office);


    //placing the items in the designated spots around the map
    closet->placeItem(plunger);
    upperattic->placeItem(key);
    pool->placeItem(pushpin);
    gym->placeItem(rifle);
    range->placeItem(ladder);  
    garden->placeItem(bucket);














}
