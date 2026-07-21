#ifndef RENTAL_H
#define RENTAL_H

#include "fleet.h"
#include <string>

class Rental
{
    private:
    int maxBookings, currBookings;
    Fleet** bookings;//1D arrays of fleet objects

    public:
    Rental(int maxBookings, int bookingSize, std::string path);
    ~Rental();
    const Fleet** getBookings();
    const int getCurrentBookings();
    const int getMaxBookings();
    bool newBooking(const Fleet* bookingFleet);
    bool cancelBooking(int index);
    std::string bookingSummary();
    double calculateBookingCost(int index);
};

#endif