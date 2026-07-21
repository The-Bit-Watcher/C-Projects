#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car: public Vehicle
{
    private:
        int topSpeed;
    public:
    Car(std::string registration , double gasUsage,double mileage,int topSpeed);
    ~Car();
    void calculateCost();
    std::string vehicleInfo();
    const int getTopSpeed() const;
};

#endif
