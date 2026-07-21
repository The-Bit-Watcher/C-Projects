#include "rental.h"
#include <iostream>

Rental::Rental(int maxBookings, int bookingSize, std::string path)
{
  this->maxBookings = maxBookings;
  this->currBookings = 0;   

  this->bookings = new Fleet*[maxBookings];

  for (int s = 0; s < maxBookings; s++)
  {
    this->bookings[s] = NULL;
  }

    this->bookings[0] = new Fleet(bookingSize, path);
    currBookings++;

   // std::cout << bookings[0]->fleetInfo()<<std::endl; //constructor works
}

Rental::~Rental()
{
  for (int s = 0; s < currBookings; s++)
  {
    delete bookings[s];
  }
  delete[] bookings;
  bookings = NULL;
}

const Fleet** Rental::getBookings()
{
   return const_cast<const Fleet**>(bookings);
}

const int Rental::getCurrentBookings()
{
    return currBookings;
}

const int Rental::getMaxBookings()
{
   return maxBookings;
}

bool Rental::newBooking(const Fleet* bookingFleet)
{
    if (currBookings >= maxBookings || bookingFleet == NULL)
    {
        return false;
    }
     Fleet** newFleetArray = new Fleet*[currBookings+1];

   
    for (int s = 0; s < currBookings; s++)
    {
        newFleetArray[s] = bookings[s];
    }

    
   // newFleetArray[currBookings] = const_cast<Fleet*>(bookingFleet);
   newFleetArray[currBookings] = new Fleet(*bookingFleet);
    
    delete[] bookings;
    bookings = newFleetArray;
    currBookings++;
     return true;    
}

bool Rental::cancelBooking(int index)//removes fleet object
{
  if (index < 0 || index >= currBookings)
  {
    return false;
  }

delete bookings[index];
bookings[index] = NULL;

  for (int s = index; s < currBookings - 1; s++)
  {
       bookings[s] = bookings[s+1];
  }

 bookings[currBookings-1] = NULL;
 currBookings--;

  return true;
}

std::string Rental::bookingSummary()
{
    std::ostringstream oss;

 for (int s = 0; s < currBookings; s++)
 {
    oss << "Booking: " << s <<" Cars: " << bookings[0]->getCurrentCars() ;
    oss << " Buses: " << bookings[s]->getCurrentBuses();
    oss << " Trucks: " << bookings[s]->getCurrentTrucks();
    oss << " Total Cost: " << calculateBookingCost(s) << '\n';
 }
    return oss.str();
}

double Rental::calculateBookingCost(int index)
{
   if (index < 0 || index >= currBookings)
   {
    return 100;
   }
   double cost = 0;

    Fleet* selectedFleet = bookings[index];

    const Car** carsArray = selectedFleet->getCars();
    int numCars = selectedFleet->getCurrentCars();

    for (int s=0; s < numCars; s++)
    {
      const_cast<Car*>(carsArray[s])->calculateCost();
      cost += carsArray[s]->getCost();
    }

    const Bus** busesArray = selectedFleet->getBuses();
    int numBuses = selectedFleet->getCurrentBuses();

    for (int s=0; s < numBuses; s++)
    {
      const_cast<Bus*>(busesArray[s])->calculateCost();
      cost += busesArray[s]->getCost();
    }

    const Truck** trucksArray = selectedFleet->getTruck();
    int numTrucks = selectedFleet->getCurrentTrucks();

    for (int s=0; s < numTrucks; s++)
    {
      const_cast<Truck*>(trucksArray[s])->calculateCost();
      cost += trucksArray[s]->getCost();
    }

    return cost;
}