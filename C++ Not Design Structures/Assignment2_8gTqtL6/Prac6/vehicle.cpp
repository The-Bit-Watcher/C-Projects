#include "vehicle.h"

Vehicle::Vehicle(std::string registration, double gasUsage, double mileage)
{
     this->registration = registration;
     this->gasUsage = gasUsage;
     this->mileage = mileage;

     this->cost = -1.0;
}

Vehicle::~Vehicle()
{
   
}

const double Vehicle::getGasUsage()
{
    //std::stringstream ss;
   // ss << gasUsage;

    return this->gasUsage;
}

const std::string Vehicle::getRegistration()
{
   return this->registration;
}

const double Vehicle::getMileage()
{
    return this->mileage;
}

const double Vehicle::getCost() const
{
    return this->cost;
}

void Vehicle::setCost(double cost)
{
   this->cost = cost;
}