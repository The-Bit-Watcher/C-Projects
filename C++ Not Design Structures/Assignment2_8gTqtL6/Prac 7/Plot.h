#ifndef PLOT_H
#define PLOT_H

class Plant;

class Plot{ 
   int numRows, numCols, numPlants;
   int** soil;
   Plant** plants;

   public:
   Plot(int numRows, int numCols);
   ~Plot();
   void waterAllPlants();
   void harvestAllPlants();
   void printPlot();
   int getNumRows() const;
   int getNumCols() const;
   int* getPosition(int col, int row) const;
   Plant* getPlant(int idx) const;
   int addPlant(Plant* plant);
};

#endif

