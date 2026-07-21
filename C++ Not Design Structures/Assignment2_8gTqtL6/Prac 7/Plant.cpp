#include "Plant.h"

Plant::Plant(char icon, Plot* plot): icon(icon), plot(plot) {
   this->planted = false;
   this-> waterLevel = 0;
}

Plant::~Plant(){}

void Plant::water(){}

void Plant::harvest(){}

bool Plant::plantSeed(){}

Plant** Plant::getNeighbours() const{}

char Plant::getIcon() const{
    return this->icon;
}

int& Plant::getWaterLevel(){
    return waterLevel;
}

bool& Plant::getPlanted(){
    return planted;
}

