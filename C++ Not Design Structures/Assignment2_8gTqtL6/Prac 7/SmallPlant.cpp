#include "SmallPlant.h"
//y = row x = col
SmallPlant::SmallPlant(char icon, Plot* plot) : Plant(icon, plot){
    this->x = -1; this->y = -1;
    //Plant(icon, plot);ask about this
}//what ,ust plot do. And how to use. As well as icon

SmallPlant::~SmallPlant(){}

void SmallPlant::water(){}

void SmallPlant::harvest(){}

bool SmallPlant::plantSeed(){
   if (this->getPlanted() == true)
   {

   }else
   {
      for (int s = 0; s < plot->getNumRows(); s++){
        for (int m = 0; m < plot->getNumCols(); m++){
            int* position = plot->getPosition(s, m);
            if (*position == -1) {            
                *position = plot->addPlant(this);
                x = m;
                y = s;
                  this->getPlanted() = true;
      int index = plot->addPlant(this);
      return true;
            }
      }//think getPositions of plot is the answer
   }  
}
}

Plant** SmallPlant::getNeighbours() const{
   std::string sline; 

   Plant** arr = new Plant*[4];

  for (int s = 0; s < 4; s++)
  {
   arr[s] = NULL;
  }

  if (x - 1 >=0){
   int *left = plot->getPosition(y, x-1);
   if (*left != -1)
   {
      arr[0] = plot->getPlant(*left);
   }
  }

   if (x+1 < plot->getNumCols()){
      int* right = plot->getPosition(y, x+1);
   if (*right != -1){
      arr[2] = plot->getPlant(*right);
   }
   }

  if (y-1>=0){
   int *top = plot->getPosition(y-1, x);
   if (*top != -1){
      arr[1] = plot->getPlant(*top);
   }
  }

  if (y+1 < plot->getNumRows()){
      int* bottom = plot->getPosition(y+1, x);
   if (*bottom != -1){
      arr[2] = plot->getPlant(*bottom);
   }
   }

   return arr;
}