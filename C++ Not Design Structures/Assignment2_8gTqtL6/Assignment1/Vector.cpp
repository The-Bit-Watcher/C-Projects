#include "Vector.h"

Vector::Vector(std::string array)
{
   int commaCount = 0; 
  
    std::string newArray = array.substr(1, array.size() - 2);

   for (int i = 0; i < newArray.length(); i++) 
   {
     if (newArray[i] == ',')
     {
        commaCount++;
     }
   }
     
     this->size = commaCount; 
    
     this->array = new double[size];

      std::stringstream ss(newArray);
      std::string item;
      double value; 

        int index = 0; 
      while (std::getline(ss,item,','))
      {
        item.erase(0, item.find_first_not_of(" \t"));
        item.erase(item.find_last_not_of(" \t") + 1);
      
            std::getline(ss, item, ',');
         std::istringstream iss(item); //extract item        
         iss >> value;//convert item

         this->array[index++] = value;//store item
      }
}

Vector::Vector(const double* array, int size)
{
    if (size < 0 or array == NULL)
    {
        this->size = 0; 
        this->array = NULL; 
    }else
    {  this->size = size;
       this->array = new double[size];
       
       for (int k = 0; k < size; k++)
       {
          this->array[k] = array[k];
       }
       
    }

}

Vector::Vector(const Vector& other)
{
  array = new double[other.size]; 

  for (int k = 0; k < other.size; k++)
  {
    array[k] = other.array[k]; 
  }

}

Vector::~Vector()
{
   delete[] array;
}

double* Vector::getArray() const
{
   //std::string output = "";   
   return array;
}

int Vector::getSize() const
{
   return size; 
}

double Vector::fromStringToDouble(std::string v)
{
    double value;
     std::stringstream ss(v);
     ss >> value;

    return value;
}

std::string Vector::fromDoubleToString(double v)
{
     std::ostringstream streamObj;
      streamObj << v;

      return streamObj.str(); 
}

const std::string Vector::toString() const
{
   std::stringstream ss;

   ss << "["; 
      // std::string newArray;
       for (size_t i = 0; i < size; i++) {

        ss << fromDoubleToString(array[i]);
        if (i < size - 1) 
        {
            ss << ", ";
        }
    }

    ss << "]";

    return (ss.str());
}

double Vector::get(int index) const
{
   if (index > size)
   {return 0;}

   return (array[index]); 
}

bool Vector::equal(const Vector& other) const
{
   if (this->size != other.size)
   {return false;}
   
   
      for (int k = 0; k < this->size; k++)
      {
         if (this->array[k] != other.array[k])
         {return false;}
      }
   
   return true; 
}