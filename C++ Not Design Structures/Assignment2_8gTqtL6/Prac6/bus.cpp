#include "bus.h"
#include "vehicle.h"
#include <cmath>
#include <iostream>
#include <sstream>

Bus::Bus(std::string registration, double gasUsage, double mileage, int seats) : Vehicle(registration, gasUsage, mileage)
{
  this->seats = seats;
}

Bus::~Bus()
{

}

const int Bus::getSeats() const
{
    return this->seats;
}

void Bus::calculateCost()
{
   double baseCost;
  
  if (seats <= 26)
  {
     baseCost = 20000;
  } else if (seats > 26 && seats <= 40)
  {
     baseCost = 30000;
  } else
  {
    baseCost = 40000;
  }
 double decay = 0.025;
 double costMileage = baseCost * exp(-baseCost * decay);

  double multiplier = 1000;

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

std::string Bus::vehicleInfo()
{
    std::ostringstream oss;
    
    oss << "R: " << getRegistration()  << " G: " << getGasUsage() << " M: " << getMileage() << " S: " << getSeats();
    return oss.str();
}