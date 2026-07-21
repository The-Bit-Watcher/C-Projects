#include "fleet.h"
#include "car.h"
#include "bus.h"
#include "truck.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 

Fleet::Fleet(int size, std::string path)
{
  this->maxSize = size;

  cars = new Car*[maxSize];
  buses = new Bus*[maxSize];
  trucks = new Truck*[maxSize];

  for (int s = 0; s < maxSize; s++)
  { 
       cars[s] = NULL;
       trucks[s] = NULL;
       buses[s]= NULL;
  }

  currCars = 0; currBuses = 0; currTrucks = 0;
  
  std::ifstream inputFile(path.c_str());
  std::string line;

  std::string stype, sregister, sgasUsage, smileage,sderived;


  //std::string 
//double mile,cost,gas
  while (std::getline(inputFile,line))
  {
      std::stringstream iss(line);
      std::string newLine;

      std::getline(iss, newLine , '#');//get type

       std::getline(iss, sregister, '#');//get registr
        
       
        std::getline(iss, sgasUsage, '#');//get gasUsage
        std::stringstream ss_gasUsage(sgasUsage);
        double dgasUsage;
        ss_gasUsage >> dgasUsage;

       std::getline(iss, smileage, '#');//getMileage
       std::stringstream ss_mileage(smileage);
        double dmileage;
        ss_mileage >> dmileage;
        

         std::getline(iss, sderived, '#');//get derived
         std::stringstream ss_derived(sderived);
        double dderived;
        ss_derived >> dderived;

      if (newLine == "Car")
      {//Car::Car(std::string registration , double gasUsage,double mileage,int topSpeed) : Vehicle(registration, gasUsage, mileage)
        cars[currCars] = new Car(sregister, dgasUsage, dmileage, dderived);
        currCars++;
      }else if (newLine == "Truck")
      {
        //Truck(std::string registration,double gasUsage, double mileage, double carry); 
        trucks[currTrucks] = new Truck(sregister, dgasUsage, dmileage, dderived);
         currTrucks++;
      }else if (newLine == "Bus")
      {//Bus(std::string registration, double gasUsage, double mileage, int seats);
         buses[currBuses] = new Bus(sregister, dgasUsage, dmileage, dderived);
        currBuses++;
      }
  } 
inputFile.close();
}

Fleet::Fleet(const Fleet* toCopy)
{
    this->currCars = toCopy->currCars;
     this->currBuses = toCopy->currBuses;
      this->currTrucks = toCopy->currTrucks;
       this->maxSize = toCopy->maxSize;

       cars = new Car*[maxSize];
       buses = new Bus*[maxSize];
       trucks = new Truck*[maxSize];

   for (int s = 0; s < maxSize; s++)
   {
      cars[s] = NULL;
      
   }
   for (int s = 0; s < currCars; s++)
   {
    cars[s] = new Car(*toCopy->cars[s]);
   }

   for (int s = 0; s < maxSize; s++)
     {
        trucks[s] = NULL;
       
     } 
     for (int s = 0; s < currTrucks; s++)
     {
      trucks[s] = new Truck(*toCopy->trucks[s]);
     }
 
    for (int s = 0; s < maxSize; s++)
      {
      buses[s] = NULL;
        
      }
      for (int s = 0; s < currBuses; s++)
      {
        buses[s] = new Bus(*toCopy->buses[s]);
      }
      
     // std::cout << std::endl << "Done";
}

Fleet::~Fleet()
{
  if (cars != NULL) 
  {
  for (int i = 0; i < currCars; i++) 
  {  
    delete cars[i];
  }
    delete[] cars;
    cars = NULL;
  }

    if (buses != NULL)
    {
   for (int s = 0; s < currBuses; s++) 
   {
       delete buses[s];    
   } 
    delete[] buses;
    buses = NULL;
    }
  
 if (trucks != NULL)
 {
  for (int s = 0; s < currTrucks; s++) 
   {       
      delete trucks[s];       
   }   
    delete[] trucks;
    trucks = NULL;
 }
     
}

const Car** Fleet::getCars() const
{
   return (const Car**)cars;
}

const Truck** Fleet::getTruck() const
{
  return (const Truck**)trucks;
}

const Bus** Fleet::getBuses() const
{
   return (const Bus**)buses;
}

const int Fleet::getCurrentCars() const
{
   return currCars;
}

const int Fleet::getCurrentBuses() const
{
    return currBuses;
}

const int Fleet::getCurrentTrucks() const
{
   return currTrucks;
}

const int Fleet::getMaxSize() const
{
  return maxSize;
}

bool Fleet::addCar(const Car* carToAdd)
{
  if (currCars == maxSize || carToAdd == NULL)
  {
    return false;
  }

  Car** newCarArray = new Car*[currCars+1];

  for (int s = 0; s < currCars; s++)
  {
    newCarArray[s] = cars[s];  
  }

  newCarArray[currCars] = new Car(*carToAdd);

  delete[] cars;

  cars = (newCarArray);
  currCars++;
  return true;
}

/*void Fleet::print()
{
   for (int s = 0; s < currCars; s++)
  {
    std::cout << cars[s]->vehicleInfo();
  }
}*/

bool Fleet::addBus(const Bus* busToAdd)
{
  if (currBuses == maxSize || busToAdd == NULL)
  {
    return false;
  }

  Bus** newBusArray = new Bus*[currBuses+1];

  for (int s = 0; s < currBuses; s++)
  {
    newBusArray[s] = buses[s];  
  }

  newBusArray[currBuses] = new Bus(*busToAdd);

  delete[] buses;

  buses = (newBusArray);
  currBuses++;
  return true;
}

bool Fleet::addTruck(const Truck* truckToAdd)
{
  if (currTrucks == maxSize || truckToAdd == NULL)
  {
    return false;
  }

  Truck** newTruckArray = new Truck*[currTrucks+1];

  for (int s = 0; s < currTrucks; s++)
  {
    newTruckArray[s] = trucks[s];  
  }

  newTruckArray[currTrucks] = new Truck(*truckToAdd);

  delete[] trucks;

  trucks = (newTruckArray);
  currTrucks++;
  return true;
}

std::string Fleet::fleetInfo()
{ std::ostringstream oss;
  /*for (int s = 0; s < currCars; s++)
  { 
    oss << "Cars:\n" << "Registration: " << cars[s]->getRegistration() <<" Mileage: " << cars[s]->getMileage() <<" Top Speed: " << cars[s]->getTopSpeed() <<"\n";
  }//check this later to see if output is correct as you thought it should be

  for (int s = 0; s < currBuses; s++)
  { 
    oss << "\nBuses:\n" << "Registration: " << buses[s]->getRegistration() <<" Mileage: " << buses[s]->getMileage() <<" Seats: " << buses[s]->getSeats() <<"\n";
  }
  
  for (int s = 0; s < currTrucks; s++)
  { 
    oss << "\nTrucks:\n" << "Registration: " << trucks[s]->getRegistration() <<" Mileage: " << trucks[s]->getMileage() <<" Carry: " << trucks[s]->getCarry() <<"\n";
  }*/

  //or 
  
  if (currCars == 0) 
  {
    oss << "No cars in the fleet.\n";
  }
if (currBuses == 0) 
{
    oss << "No buses in the fleet.\n";
}
if (currTrucks == 0) 
{
    oss << "No trucks in the fleet.\n";
}

  oss << "Cars:\n";
   for (int s = 0; s < currCars; s++)
  { 
    oss << "Registration: " << cars[s]->getRegistration() <<" Mileage: " << cars[s]->getMileage() <<" Top Speed: " << cars[s]->getTopSpeed() <<"\n";
  }//check this later to see if output is correct as you thought it should be

    oss << "\nBuses:\n";
  for (int s = 0; s < currBuses; s++)
  { 
    oss  << "Registration: " << buses[s]->getRegistration() <<" Mileage: " << buses[s]->getMileage() <<" Seats: " << buses[s]->getSeats() <<"\n";
  }
  oss << "\nTrucks:\n";
  for (int s = 0; s < currTrucks; s++)
  { 
    oss  << "Registration: " << trucks[s]->getRegistration() <<" Mileage: " << trucks[s]->getMileage() <<" Carry: " << trucks[s]->getCarry() <<"\n";
  }

  return oss.str();
}