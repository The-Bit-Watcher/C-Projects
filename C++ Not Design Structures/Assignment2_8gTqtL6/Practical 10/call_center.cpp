#include "call_center.h"
#include "missed.h"
#include "incoming.h"
#include "exceptions.h"
#include <fstream>
#include <iostream>

CallCenter::CallCenter(std::string filename){
     std::ifstream file(filename.c_str());

     if (!file){
        return;
     }

     std::string line;
     //int count = 0;

     std::getline(file,line);
     std::stringstream(line) >> numOperators;

     std::getline(file,line);
     std::stringstream(line) >> callLimit;

      phones = new int[numOperators];
      int phonesForOperators = 0;
      for (int s = 0; s < numOperators; s++){
         
         file >> phonesForOperators;

         phones[s] = phonesForOperators * 2; 
      }

       operators = new CallHandler**[numOperators];


       for (int s = 0; s < numOperators; ++s){
         operators[s] = new CallHandler*[phones[s]];

         for (int m = 0; m < phones[s]; ++m){
            if (m%2 == 0){//either Incoming or Missed
               operators[s][m] = new Incoming(callLimit);
            }else{
               operators[s][m] = new Missed(callLimit);
            }
         }
       }
    file.close(); 
    
}

CallCenter::~CallCenter(){
    for (int i = 0; i < numOperators; ++i) {
            for (int j = 0; j < phones[i]; ++j) {
               if (operators[i][j] != NULL){
                   delete operators[i][j];
               }             
            }
            if (operators[i] != NULL){
                delete[] operators[i];
            }         
        }
        if (operators != NULL)
        delete[] operators;
        if (phones != NULL)
        delete[] phones;
}

int* CallCenter::getPhones(){
   return phones;
}

int CallCenter::getNumOperators(){
   return numOperators;
}

CallHandler*** CallCenter::getOperators(){
   return operators;
}

int CallCenter::getCallLimit(){
   return callLimit;
}

void CallCenter::recieveCalls(std::string fileName){
  /* std::ifstream file(fileName.c_str());
        
        if (!file.is_open()){
          throw OperatorNotFound();
        }
         int index = 0, indexPhone = 0;
         std::string sline;
        int op;
        file >> op;

        if (op >= numOperators || op < 0){
          throw OperatorNotFound();
        }

        while (std::getline(file, sline)){
           indexPhone = index % phones[op];
           operators[op][indexPhone]->addCall(sline);
           index += 1;
        }file.close();*/
}

std::string CallCenter::takeCall(int op, int calls){
   if (op<0 || op >= numOperators){
       throw OperatorNotFound();
   }

   std::ostringstream output;
   int countPhone = phones[op], countCall = 0;
  // std::cout << countPhone << std::endl;
   //std::cout << calls << std::endl;
   for (int s = 0; (s < countPhone) && (countCall < calls); s++ ){
      try {
         output << operators[op][s]->removeCall()->displayDetails() ;
      output << "\n";
      std::cout << operators[op][s]->removeCall()->displayDetails() << std::endl ;//remove later
      delete (operators[op][s]->removeCall());
      countCall = countCall + 1;
      }
      catch (const IncomingCallsEmpty&){}
   }return output.str();
}

std::string CallCenter::callBack(int op, int calls){
     if (op >= numOperators || op < 0){
      throw OperatorNotFound();
     }

     std::ostringstream output;
     int countPhone = phones[op], countCall = 0;

    // std::cout << countPhone << std::endl;
    // std::cout << calls << std::endl;
     
     for (int s = 0; (countCall < calls) && (s < countPhone); s++){
     try{
         output << operators[op][s]->removeCall()->displayDetails();
         output << "\n";
         delete operators[op][s]->removeCall();
         countCall++;
      }catch (const MissedCallsEmpty&){}
     }return output.str();
}