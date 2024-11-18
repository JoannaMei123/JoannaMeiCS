#include <iostream>
#include <cstring>
#include <map>

using namespace std;

struct items {
  char itemName[100];
  char itemLocation[100];
};


int main() {
  map <string, int> itemLocations;

  //Initializing Items
  itemLocations["Book"] = 2;
  itemLocations["Plunger"] = 3;

  

}
