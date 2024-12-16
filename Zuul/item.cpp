#include <iostream>
#include "item.h"
#include <cstring>

using namespace std;


item::item(char* newitemInfo) {
  itemInfo = newitemInfo;

}

char* item::getItemInfo(){
  return itemInfo;
}