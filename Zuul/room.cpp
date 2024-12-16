#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

room::room() {

}

room::room(char* newDescription) {
  roomDescription = newDescription;

}

char* room::getroomDescription() {
  return roomDescription;
}

void room::makeExit(char *newdirection, room *newconnectedRoom) {
  exits.insert(pair<char*, room*>(newdirection, newconnectedRoom));
}

void room::getExitsExisting() {
  cout << "EXITS:";
  map<char*, room*>:: iterator i;

  for (i = exits.begin(); i != exits.end(); i++) {
    cout << i ->first<< " " <<endl;
  }

}

map<char*, room*> room::getExit() {
  return exits;
}

void room::placeItem(item* newItem) {
  items.push_back(newItem);
}

void room::printItem() {
  cout << "ITEMS:" <<endl;
  for (int i =0; i < items.size(); i++) {
    char out[1000];
    strcpy(out, items[i] ->getItemInfo());
    cout << out <<endl;
  }
}

int room::noItems(){
  int length = items.size();

  return length;
}

item* room::matchItem(char* newdescription){
  for(int i=0; i<items.size();i++){
    char out[1000];
    strcpy(out,items[i]->getItemInfo());
    if (strcmp(newdescription,out)==0){
      return items[i];
    }
    else {
      ;
    }
  }
  return NULL;
}

void room::itemFound(char*random){
  //vector<item*>::iterator i;
  for(int i=0;i<items.size();i++){
      if(strcmp(random,items[i]->getItemInfo())==0){
        items.erase(items.begin()+i);
      }
    }
}