#include <cstdio>
#include <iostream>

#include "rental.h"
#include "vehicle.h"
#include "car.h"
#include "bus.h"

int main() {
    //Happy Testing
    /*Vehicle m("klfnc12", 100,299);
    
    m.setCost(1234) ;
   std::cout << m.getCost()<< std::endl;
   std::cout << m.getGasUsage()<< std::endl;
   std::cout << m.getRegistration()<< std::endl;
   std::cout << m.getMileage()<< std::endl;*///works
    
    Car m("dcdfvds", 123,123,100);
   // m.setCost(1234) ;
   //std::cout << m.getCost()<< std::endl;
   //std::cout << m.getGasUsage()<< std::endl;
   //std::cout << m.getRegistration()<< std::endl;
   //std::cout << m.getMileage()<< std::endl;

   m.calculateCost();
   //std::cout << m.vehicleInfo() << std::endl;
   //so far vehicle and car works

   /*Bus m("djhs", 12.4, 100.4, 28);
   m.calculateCost();
  std::cout << m.vehicleInfo()<< std::endl;
  std::cout << m.getCost();*///works bus
  //so far vehicle ,car and bus works

  /*Truck m("djhs", 12.4, 100.4, 12);
   m.calculateCost();
  std::cout << m.vehicleInfo()<< std::endl;
  std::cout << m.getCost();*///so far vehicle, car, bus and truck works
   
  std::string path = "fleet.txt";
  int size = 10;
  Fleet input(size, path); //constructor fleet works
  //input.print();
  //std::cout << std::endl;

 // Fleet day = input;
  //day.print();//copy construct works
  //std::cout << std::endl;
 
   //input.addCar(&m);add works
   //std::cout << std::endl;  
   
    //input.print(); //add does not work

   //std::cout << input.fleetInfo();

   Rental s(10, 20 , path);
   Rental sr(10, 20 , path);
   s.newBooking(&input);
   std::cout << s.bookingSummary();
   //std::cout << sr.booking[S];

   //std::cout << s.bookingSummary(); 

   //s.cancelBooking(0);

  //std::cout << s.bookingSummary(); 
    return 0;
}