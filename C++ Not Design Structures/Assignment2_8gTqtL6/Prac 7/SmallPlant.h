#ifndef SMALLPLANT_H
#define SMALLPLANT_H

#include <iostream>
#include "Plant.h"

class SmallPlant : public Plant{

protected:
int x, y;

public:
SmallPlant(char icon, Plot* plot);
virtual ~SmallPlant();
virtual void water() = 0;
virtual void harvest() = 0;
bool plantSeed();
Plant** getNeighbours() const;
};

#endif