#ifndef CARROT_H
#define CARROT_H
#include "SmallPlant.h"

class Carrot : public SmallPlant{
   int numLeaves, harvestCycle; 

   public :
   Carrot(Plot* plot, int harvestCycle);
   virtual ~Carrot() ;
   void water();
   void harvest();   
};

#endif