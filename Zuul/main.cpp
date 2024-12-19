#include "item.h"
#include "room.h"
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

using namespace std;

void goingToPlace(vector<room *> rooms, map<char *, room *> &exits, room *&currentRoom);
void getItem(vector<item *> items, vector<item *> &currentItems, room *&currentRoom);
void getInv(vector<item *> &currentItems, room *&currentRoom);
void dropItem(vector<item *> items, vector<item *> &currentItems, room *&currentRoom);
void checkWin(vector<item *> items, vector<item *> &currentItems, room *&currentRoom, map<char *, room *> &exits);



int main() {
  vector<room *> rooms;
  vector<item *> items;
  vector<item *> currentItems;
  map<char *, room *> exits;
  room *currentRoom;
  char playerDirection[100];

  // Making all the item names
  item *plunger = new item((char *)"Plunger");
  item *key = new item((char *)"Key");
  item *bucket = new item((char *)"Bucket");
  item *pushpin = new item((char *)"Pushpin");
  item *rifle = new item((char *)"Rifle");
  item *ladder = new item((char *)"Ladder");

  // Upper Half of Rooms
  room *locker = new room((char *)"You are in the locker room");
  room *pool = new room((
      char
          *)"You are at the pool. There seems to be a locked door up north...");
  room *gym = new room((
      char *)"The stench of sweat fills your lungs. You have entered the gym.");
  room *range = new room((char *)"You are now in the range.");

  // Mid Map
  room *closet = new room((char *)"You have now entered the closet");
  room *cafeteria = new room((char *)"The room around you has expanded... you "
                                     "have entered the cafeteria");
  room *electrical = new room(
      (char *)"Wires, so many wires. You have entered the electrical room.");
  room *garden = new room(
      (char *)"You feel the breeze of the wind. You have entered the garden");

  // Lower Half of Map
  room *attic = new room(
      (char *)"You notice cobwebs above you. You have entered the attic");
  room *office = new room((char *)"The unsettling smell of dust fills your "
                                  "nose. You have entered the office");
  room *bathroom = new room((char *)"You have entered the bathroom");
  room *upperattic = new room((char *)"The eerie sensation engulfs your body. "
                                    "You have entered the upper attic");

  room *start = new room((char *)"It looks familiar");
  room *bathroomsecret = new room((char *)"Whats this? A place to rest?");

  // Creating the exits of all the rooms. Split into each category used.
  start->makeExit((char *)"north", cafeteria);
  start->makeExit((char *)"south", office);

  cafeteria->makeExit((char *)"south", start);
  cafeteria->makeExit((char *)"north", pool);
  cafeteria->makeExit((char *)"west", closet);
  cafeteria->makeExit((char *)"east", electrical);

  pool->makeExit((char *)"north", range);
  pool->makeExit((char *)"west", locker);
  pool->makeExit((char *)"east", gym);
  pool->makeExit((char *)"south", cafeteria);

  locker->makeExit((char *)"south", closet);
  locker->makeExit((char *)"east", pool);

  closet->makeExit((char *)"east", cafeteria);
  closet->makeExit((char *)"north", locker);

  gym->makeExit((char *)"west", pool);

  electrical->makeExit((char *)"east", garden);
  electrical->makeExit((char *)"west", cafeteria);

  garden->makeExit((char *)"west", electrical);

  office->makeExit((char *)"north", start);
  office->makeExit((char *)"west", attic);
  office->makeExit((char *)"east", bathroom);

  attic->makeExit((char *)"north", upperattic);
  attic->makeExit((char *)"east", office);

  upperattic->makeExit((char *)"south", attic);

  bathroom->makeExit((char *)"north", bathroomsecret);
  bathroom->makeExit((char *)"west", office);

  // placing the items in the designated spots around the map
  closet->placeItem(plunger);
  upperattic->placeItem(key);
  pool->placeItem(pushpin);
  gym->placeItem(rifle);
  range->placeItem(ladder);
  garden->placeItem(bucket);

  // Determines whether the player has entered the secret room or not

  bool enteredsecret = false;

  // Sets starting room for the game
  currentRoom = start;

  while (true) {

    //Win Statement Check
    bool plungerUsed = false;
    bool pushpinUsed = false;
    bool bucketObtained = false;
    bool ladderObtained = false;
    bool keyUsed = false;
    bool rifleObtained = false;


    for (int i = 0; i <= 6; i++) {

      if (strcmp(currentItems[i]->getItemInfo(),"Plunger") == 0) {
        plungerUsed = true;
        cout << "Plunger obtained";
      } else if (strcmp(currentItems[i]->getItemInfo(),"Pushpin") == 0) {
        pushpinUsed = true;
      } else if (strcmp(currentItems[i]->getItemInfo(),"Bucket") == 0) {
        bucketObtained = true;
      } else if (strcmp(currentItems[i]->getItemInfo(),"Ladder") == 0) {
        ladderObtained = true;
      } else if (strcmp(currentItems[i]->getItemInfo(),"Key") == 0){
        keyUsed = true;
      } else if (strcmp(currentItems[i]->getItemInfo(),"Rifle") == 0) {
        rifleObtained = true;
      }
    }



    if (plungerUsed == true && pushpinUsed == true && bucketObtained == true && ladderObtained == true && keyUsed == true && rifleObtained == true && enteredsecret == true)  {
      cout << "Congratulations, you won!";
      break;
    }


  /*  

        ************************Command functions begin down here ****************



      */

    //Grabbing first room
    char asef[100];
    strcpy(asef, currentRoom->getroomDescription());
    cout << asef << endl;
    currentRoom->printItem();


    //Prompting User to use a command
    cout << "Please select a command: MOVE, GRAB, DROP, INVENTORY, QUIT, HELP"
         << endl;

    cin >> playerDirection;
    // cout << "You typed: " << playerDirection << endl;


    //Commands 
    if (strcmp(playerDirection, "MOVE") == 0) {
      goingToPlace(rooms, exits, currentRoom);
    } else if (strcmp(playerDirection, "GRAB") == 0) {
      getItem(items, currentItems, currentRoom);
    } else if (strcmp(playerDirection, "DROP") == 0) {
      dropItem(items, currentItems, currentRoom);
    } else if (strcmp(playerDirection, "INVENTORY") == 0) {
      getInv(currentItems, currentRoom);
    } else if (strcmp(playerDirection, "QUIT") == 0) {
      exit(0);
      cout << "You quit the game" << endl;
    } else if (strcmp(playerDirection, "HELP") == 0) {
      cout << "MOVE: To go to other rooms and move around the map" << endl;
      cout << "GRAB: Enables you to grab items from the map" << endl;
      cout << "DROP: Drops items from the map" << endl;
      cout << "INVENTORY: Views your inventory " << endl;
      cout << "QUIT: Quits the game" << endl;
      cout << "**Commands only work with all CAPS**" << endl;

    } else {
      ;
    }
  }
}

void goingToPlace(vector<room *> rooms, map<char *, room *> &exits,
                  room *&currentRoom) {

  char output[200];

  cout << endl;
  currentRoom->getExitsExisting();
  map <char*, room*> roomMap = currentRoom->getExit();
  map<char *, room *>::iterator i;
  cout << "Enter the one which you would go to" << endl;
  cin >> output;
  cin.ignore();
  cout << endl;


  for (i = roomMap.begin(); i != roomMap.end(); i++) {
    if (strcmp(output, i->first) == 0) {
      currentRoom = i->second;
      break;
    }
  }
}

void getItem(vector<item *> items, vector<item *> &currentItems, room *&currentRoom) {
  char decision[100];

  cout << endl;
  currentRoom->printItem();
  cout << "What item do you want to grab?" << endl;
  cin >> decision;
  cin.ignore();

  if (currentRoom->noItems() == 0) {
    cout << "There are no items in the room." << endl;
  } else {
    currentItems.push_back(currentRoom->matchItem(decision));

    currentRoom->itemFound(decision);
  }
}

void getInv(vector<item *> &currentItems, room *&currentRoom) {

  if (currentItems.size() == 0) {
    cout << "No items in ur inventory." << endl;
  }
  cout << " You currently have these items:  " << endl;

  for (std::vector<item *>::iterator it = currentItems.begin();
       it != currentItems.end(); ++it) {
    cout << (*it)->getItemInfo() << endl;
    ;
  }
}

void dropItem(vector<item *> items, vector<item *> &currentItems,
              room *&currentRoom) {
  char input[100];
  cout << "What item would you like to drop?" << endl;
  cin.getline(input, 101, '\n');
  item *drop;

  if (strcmp(input, "Plunger") == 0 || strcmp(input, "Key") == 0 ||
      strcmp(input, "Ladder") == 0 || strcmp(input, "Pushpin") == 0 ||
      strcmp(input, "Bucket") == 0 || strcmp(input, "Rifle") == 0) {

    for (int i = 0; i < currentItems.size(); i++) {
      if (strcmp(input, currentItems[i]->getItemInfo()) == false) {
        currentItems.erase(currentItems.begin() + i);

        drop = currentItems[i];
      }
    }

    currentRoom->placeItem(drop);
  } else {
    ;
  }
}



