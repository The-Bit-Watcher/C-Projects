#include "MediumPlant.h"
#include <iostream>

MediumPlant::MediumPlant(char icon, Plot* plot) : Plant(icon, plot)
{
    for (int s = 0; s < 2; s++){
        x[s] = -1;
        y[s] = -1; 
    }
}

MediumPlant::~MediumPlant(){

}

void MediumPlant::harvest(){}

void MediumPlant::water(){}

bool MediumPlant::plantSeed(){
    if (this->getPlanted())
    {
       return false;
    }

    int rows, cols;
    rows = plot->getNumRows();
    cols = plot->getNumCols();

        for (int s = 0; s < rows-1; s++)
        {
            for (int m = 0; m < cols-1; m++){
                if ((*plot->getPosition(s, m) == -1) and 
                (*plot->getPosition(s, m + 1) == -1) and
                (*plot->getPosition(s + 1, m) == -1) and
                (*plot->getPosition(s + 1, m + 1) == -1)){

                    *plot->getPosition(s,m) = plot->addPlant(this);
                     *plot->getPosition(s,m+1) = plot->addPlant(this);
                      *plot->getPosition(s+1,m) = plot->addPlant(this);
                       *plot->getPosition(s+1,m+1) = plot->addPlant(this);   
                       this->getPlanted() = true;    
                       x[0] = m;
                       x[1] = m+1;
                       y[0] = s;
                       y[1] = s+1;     
                       return true;   
                }
            }
            return false;
        
    }
}

Plant** MediumPlant::getNeighbours() const{

    Plant** arr = new Plant*[8];

    for (int s = 0; s < 8 ; s++){
        arr[s] = NULL;
    }

    int rows,cols;
    rows = plot->getNumRows();
    cols = plot->getNumCols();

    if (y -1 >= 0 and x-1 >=0){
        int* topL = plot->getPosition(y-1, x-1);
        if (*topL != -1)
        arr[0] = plot->getPlant(*topL);
    }

    if (y - 1 >= 0 and x + 1 < plot->getNumCols()) {
        int* topR = plot->getPosition(y - 1, x + 1);
        if (*topR != -1) {
            arr[2] = plot->getPlant(*topR);
        }
    }

    if (y - 1 >= 0) {
        int* top = plot->getPosition(y - 1,x);
        if (*top != -1) {
            arr[1] = plot->getPlant(*top);
        }
    }
        if ( x + 1 < plot->getNumCols()) {
        int* right = plot->getPosition(y , x + 1);
        if (*right != -1) {
            arr[3] = plot->getPlant(*right);
        }
    }

    if (y + 1 < plot->getNumRows() && x + 1 < plot->getNumCols()) {
        int* bottomR = plot->getPosition(y +1 1, x + 1);
        if (*bottomR != -1) {
            arr[4] = plot->getPlant(*bottomR);
        }
    }

    if (y + 1 < plot->getNumRows() ) {
        int* bottom = plot->getPosition(y + 1, x);
        if (*bottom != -1) {
            arr[5] = plot->getPlant(*bottom);
        }
    }

     if (y + 1 < plot->getNumRows() && x - 1 >= 0) {
        int* bottomL = plot->getPosition(y + 1, x - 1);
        if (*bottomL != -1) {
            arr[6] = plot->getPlant(*bottomL);
        }

    }

    if (x - 1 >= 0) {
        int* left = plot->getPosition(y, x - 1);
        if (*left != -1) {
            arr[7] = plot->getPlant(*left);
        }
    }

    return arr;
}