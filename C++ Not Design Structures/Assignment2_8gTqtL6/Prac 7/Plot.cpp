#include "Plot.h"
#include "Plant.h"
#include <iostream>

Plot::Plot(int numRows, int numCols) : numRows(numRows), numCols(numCols){

    this->numPlants = 0; 
    this->plants = NULL; 

    this->soil = new int*[numRows];

    for (int s = 0; s < numRows; s++){
        soil[s] = new int[numCols];
        for (int m = 0; m < numCols; m++){
            soil[s][m] = -1; 
        }
    }
}

Plot::~Plot(){

   for (int s = 0; s < this->numRows; s++){
    if (soil[s] != NULL)
    delete soil[s];
   }
   delete[] soil;

   for (int s = 0; s < numPlants; s++){
    if (plants[s] != NULL)
    delete plants[s];
   }
   delete[] plants;
}

void Plot::waterAllPlants(){
  int index = 0;
    for (int s = 0; s < numRows; s++){
        for (int i = 0; i < this->numCols; i++)
        {
           if (soil[s][i] != -1)
           {
             index = soil[s][i]; 
             if (index > numPlants || index < 0)
             {
                return;
             }
             plants[index]->water();
           }
        }
        
    }

}

void Plot::harvestAllPlants(){
    int index = 0;
     for (int s = 0; s < numRows; s++){
        for (int i = 0; i < this->numCols; i++)
        {
          if (soil[s][i] != -1)
           {
             index = soil[s][i]; 
             if (index > numPlants || index < 0)
             {
                return;
             }
             plants[index]->harvest();
           }
        }
        
    }
}

void Plot::printPlot(){
    std::string sline = "";
    int index = 0;
    for (int s = 0; this->numRows; s++){
        for (int m =0; m < this->numCols; m++){
          if (soil[s][m] != -1)
           {
             index = soil[s][m]; 
             if (index > numPlants || index < 0)
             {
                return;
             }
             sline = plants[index]->getIcon();
           }else{
            sline += "-"; 
           }
        sline += "\n";
     }
      std::cout<<sline;
  }
}

int Plot::getNumRows() const{
    return this->numRows;
}

int Plot::getNumCols() const{
    return this->numCols;
}

int* Plot::getPosition(int row, int col) const{
   if (row > this->getNumRows() || row < 0 || col > numCols || col < 0)
   {
     return NULL;
   }

  return &soil[row][col];
}

Plant* Plot::getPlant(int idx) const{
    if (idx == NULL || idx > this->numPlants || idx < 0){
        return NULL;
    }
    return plants[idx];
}

int Plot::addPlant(Plant* plant){
    if (plant == NULL){
        return -1;
    }

    Plant*** arr = new Plant**[numPlants+1];
     int index;
    for (int s = 0; s < numPlants; s++)
    {
       index = s;
       *arr[s] = plants[s];
    }
    delete[] plants;
    plants = *arr;
    return index;
}