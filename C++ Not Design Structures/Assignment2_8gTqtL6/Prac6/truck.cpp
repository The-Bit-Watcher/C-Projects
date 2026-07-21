#include "truck.h"
#include "vehicle.h"
#include <cmath>
#include <iostream>
#include <sstream>

Truck::Truck(std::string registration,double gasUsage, double mileage, double carry) : Vehicle(registration, gasUsage, mileage)
{
   this->carry = carry;
}

Truck::~Truck()
{

}

const double Truck::getCarry() const
{
    return this->carry;
}

void Truck::calculateCost()
{
    double baseCost;
  
  if (carry <= 2)
  {
     baseCost = 35000;
  } else if (carry > 2 && carry <= 5)
  {
     baseCost = 52000;
  } else
  {
    baseCost = 78000;
  }
 double decay = 0.010;
 double costMileage = baseCost * exp(-baseCost * decay);

  double multiplier = 10000;

 double maxValue;

 if (costMileage > baseCost)
 {
    maxValue = costMileage;
 }else if (costMileage == baseCost)
 {
   maxValue = costMileage;
 } else
 {
    maxValue = baseCost;
 }

 double costGas = maxValue + (multiplier/getGasUsage()) ;

  setCost(costGas); 
}

std::string Truck::vehicleInfo()
{
     std::ostringstream oss;
    
    oss << "R: " << getRegistration()  << " G: " << getGasUsage() << " M: " << getMileage() << " S: " << getCarry();
    return oss.str();
}