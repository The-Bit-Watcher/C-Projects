#include "Carrot.h"

Carrot::Carrot(Plot* plot, int harvestCycle) : SmallPlant(c, plot)
{
    if (harvestCycle <= 0){
        harvestCycle = 1;
    }else
    {
        this->harvestCycle = harvestCycle;
    }

    numLeaves = 0;
}

Carrot::~Carrot(){}

void Carrot::water(){
     if (getPlanted() == false){
        return;
      }

     getWaterLevel() = getWaterLevel() +1;
      numLeaves++;
      numLeaves = numLeaves % harvestCycle;
}

void Carrot::harvest(){
    if (getPlanted() && getWaterLevel() >= 8){

        getPlanted() = false;
        getWaterLevel() = 0;
 

      std::cout << "Harvested_{" << numLeaves <<"}_carrots"
    }
}
