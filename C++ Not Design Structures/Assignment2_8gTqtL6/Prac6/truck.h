#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle
{
   private:
   double carry;

   public:
   Truck(std::string registration,double gasUsage, double mileage, double carry);
   ~Truck();
   const double getCarry() const;
   void calculateCost();
   std::string vehicleInfo();
};

#endif
