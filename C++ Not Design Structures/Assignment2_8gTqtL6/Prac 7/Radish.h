#ifndef RADISH_H
#define RADISH_H
#include "SmallPlant.h"

class Radish : public SmallPlant{
 
       int period;

       public: 
       Radish(Plot* plot, int period);
       virtual ~Radish() ;
       void water();
       void harvest();

};

#endif