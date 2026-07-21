#include "Party.h"
#include "Player.h"

Party::Party(){
    numMembers = 0;
    members = NULL;
}

Party::Party(const Player& player){
    numMembers = 1;
    members = new Player*[numMembers];
    members[0] = player.clone();
}

Party::Party(const Party& other){
    this->numMembers = other.numMembers;

    if (other.numMembers == 0)
    {
       this->numMembers = 0;
       return;
    }

    this->members = new Player*[other.numMembers];

    for (int s = 0; s < other.numMembers; s++){
        this->members[s] = other.members[s]->clone();
    }
}

Party::~Party(){
    for (int s = 0; s< this->numMembers;s++)
    {
         delete members[s];
    }
    delete[] members;
    members = NULL;
    numMembers = 0;
}

Party& Party::operator=(const Party& other){
    if (this == &other)
    {
        return *this;
    }

    for (int s= 0; s < this->numMembers; s++)
    {
        delete this->members[s];
    }   

    delete[] this->members;

    this->members = new Player*[other.numMembers];
    this->numMembers = other.numMembers;

   for (int s=0; s < other.numMembers; s++){
       this->members[s] = other.members[s]->clone();
   }

   return *this;   
}

std::ostream& operator<<(std::ostream& os, const Party& party){
    for (int s = 0; s < party.numMembers;s++){
       os<< *party.members[s];
       if (s < party.numMembers-1)
       {os<<"\n";}     
    }
    return os;
}

int Party::getNumMembers() const{
    return numMembers;
}

Player* Party::operator[](int index) const{
   if (index < 0 || index >= this->numMembers){
    return NULL;
   }
    //std::cout <<index;
   return this->members[index];
}

Player* Party::operator[](int index){
     if (index < 0 || index >= this->numMembers){
    return NULL;
   }
  // std::cout <<index;
   return this->members[index];
}

Party Party::operator+(Player& player) const{

    Party newParty;
    newParty.numMembers = this->numMembers + 1;
    newParty.members = new Player*[newParty.numMembers];

   for (int s = 0; s< this->numMembers; s++){
    newParty.members[s] = this->members[s]->clone();//deep copy
    std::cout << newParty.members[s]->name;
   }
     newParty.members[this->numMembers] = player.clone();//clone does deep copy 
    // std::cout << newParty.numMembers<< std::endl;//remove later
     return newParty;
}

Party& Party::operator+=(Player& player){
      /* Player** newMember = new Player*[this->numMembers];

       for (int s = 0; s < this->numMembers; s++){
        newMember[s] = this->members[s]->clone();
       }
       newMember[this->numMembers] = player.clone();
       delete[] members;//might need to delete the pointers within
       
       members = newMember;
       numMembers++;
       
       return *this;*/

       Player** arr = new Player*[this->numMembers+1];

       for (int s = 0; s< this->numMembers; s++){
        arr[s] = this->members[s]->clone();
       }
       
       for (int s = 0; s < numMembers;s++){
        delete members[s];
       }
       delete[] members;


       arr[this->numMembers] = player.clone();
       this->members = arr;
       this->numMembers +=1;
       return *this;
}

Party Party::operator-(int index)const{
    if (index < 0 || index>this->numMembers)
    {
        return *this;
    }

    Party newParty;
    newParty.numMembers = this->numMembers -1;

    newParty.members = new Player*[newParty.numMembers];

  for (int s=0,idx=0; s<this->numMembers;s++){
    if (s != index){
       newParty.members[idx++] = this->members[s]->clone();
    }
  }

   return newParty;
}

Party& Party::operator-=(int index){
    if (index < 0 || index > this->numMembers){
        return *this;
    }

    Player** arr = new Player*[this->numMembers-1];


    for (int s = 0; s < this->numMembers;s++){
        if (s != index){
           arr[s] = this->members[s]->clone();
        }
    }
    for (int s; s < numMembers;s++){
        delete members[s];
    }
    delete[] members;

    members = arr;
    numMembers--;
    return *this;
}

Party Party::operator>>(const Party& otherParty) const{
    
    Party newParty = *this;//copy constructor
     for (int s=0; s < this->getNumMembers();s++){
        *newParty.members[s] >> otherParty;
     }

     return newParty;
}

Party& Party::operator>>=(Party& otherParty){
    
    for (int s = 0; s< this->getNumMembers(); s++){
        *this->members[s] >> otherParty;
    }

    return *this;
}

Party Party::operator<<(const Party& otherParty) const{
    Party newParty = otherParty;

     for (int s =0; s< this->getNumMembers(); s++){
        *newParty.members[s] << otherParty;
     }
     return newParty;

}

Party& Party::operator<<=(Party& otherParty){
    for (int s=0; s < this->getNumMembers(); s++){
        *this->members[s] << otherParty;
    }
    return *this;         
}
