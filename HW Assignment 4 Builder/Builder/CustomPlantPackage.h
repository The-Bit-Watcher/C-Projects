#ifndef CUSTOMRPLANTPACKAGE_H
#define CUSTOMRPLANTPACKAGE_H

/*
#include "Plant"
#inlcude "Pot"
#include "SoilMix"
Just add the include so long
before having the files
*/
//this is the product. Save the 
//informationn gotten from the 
//factory here
class CustomPlantPackage{
    private:
    Plant* plant;
    Pot* pot;
    SoilMix* soil;

    public: 
    void setSoilMix(SoilMix* s);
    void setPlant(Plant* p);
    void setPot(Pot* p);
};
//maybe we need to add setters, because var is private
#endif // CUSTOMRPLANTPACKAGE_H