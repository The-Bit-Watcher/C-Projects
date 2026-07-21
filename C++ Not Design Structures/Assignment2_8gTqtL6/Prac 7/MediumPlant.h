#ifndef MEDIUMPLANT_H
#define MEDIUMPLANT_H

#include "Plant.h"

class MediumPlant : public Plant{

protected:
int x[2], y[2];

public:
MediumPlant(char icon, Plot* plot);
virtual ~MediumPlant() ;
virtual void water() ;
virtual void harvest() ;
bool plantSeed();
Plant** getNeighbours() const;
};

#endif