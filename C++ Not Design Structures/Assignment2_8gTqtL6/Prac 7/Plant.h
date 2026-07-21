#ifndef PLANT_H
#define PLANT_H

#include "Plot.h"

class Plant{
  
  int waterLevel;
  char icon;
  bool planted;
  
  protected: Plot* plot;

   public :
    Plant(char icon, Plot* plot);
    virtual ~Plant() = 0;
    virtual void water() = 0;
    virtual void harvest() = 0;
    virtual bool plantSeed() = 0;
    virtual Plant** getNeighbours() const= 0;
    char getIcon() const;
    int& getWaterLevel();
    bool& getPlanted(); 
};

#endif