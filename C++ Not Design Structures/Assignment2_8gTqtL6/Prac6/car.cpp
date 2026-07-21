#include "car.h"
#include "vehicle.h"
#include <cmath>
#include <iostream>
#include <sstream>


//Vehicle(std::string registration, double gasUsage, double mileage)
Car::Car(std::string registration , double gasUsage,double mileage,int topSpeed) : Vehicle(registration, gasUsage, mileage)
{
  this->topSpeed = topSpeed;
}

Car::~Car()
{

}

void Car::calculateCost()
{
   double baseCost;
  
  if (topSpeed <= 150)
  {
     baseCost = 6000;
  } else if (topSpeed > 150 && topSpeed <= 200)
  {
     baseCost = 12000;
  } else
  {
    baseCost = 20000;
  }
 double decay = 0.015;
 double costMileage = baseCost * exp(-baseCost * decay);

  double multiplier = 500;

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

std::string Car::vehicleInfo()
{
    std::ostringstream oss;
    
    oss << "R: " << getRegistration()  << " G: " << getGasUsage() << " M: " << getMileage() << " S: " << topSpeed;
    return oss.str();
}

 const int Car::getTopSpeed() const
 {
     return topSpeed;
 }