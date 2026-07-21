#ifndef FLEET_H
#define FLEET_H

#include "car.h"
#include "bus.h"
#include "truck.h"
#include <fstream>
#include <sstream>

class Fleet
{
     private:
     int currCars, currBuses, currTrucks, maxSize;
     Car** cars;
     Bus** buses;
     Truck** trucks;
//** == 1D-Arrays
     public:
     Fleet(int size, std::string path);
     Fleet(const Fleet* toCopy);
     //void print();//test function for copy construct
     ~Fleet();
     const Car** getCars() const;
     const Truck** getTruck() const;
     const Bus** getBuses() const;
     const int getCurrentCars() const;
     const int getCurrentBuses() const;
     const int getCurrentTrucks() const;
     const int getMaxSize() const;
     bool addCar(const Car* carToAdd);
     bool addTruck(const Truck* truckToAdd);
     bool addBus(const Bus* busToAdd);
     std::string fleetInfo();
};

#endif