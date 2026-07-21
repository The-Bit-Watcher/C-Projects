#include "Ranger.h"

Ranger::Ranger(std::string name, int health, int power, int speed, int numShots) : Player(name,health,power,speed){
    this->numShots = numShots;
}

Ranger::Ranger(const Ranger& other):Player(other){
    this->numShots = other.numShots;
}

Ranger& Ranger::operator=(const Ranger& other){//might need to call other copy constructor upon this
    if (this == &other){
        return *this;
    }

    Player::operator=(other);
    this->numShots = other.numShots;   
    return *this;
}

Player* Ranger::clone()const{
  return new Ranger(*this);
}

Ranger::~Ranger(){

}

Ranger::operator std::string() const{
   std::ostringstream oss;
    oss << "Ranger:" <<Player::operator std::string() <<"numShots="<<this->numShots;

   return oss.str();
}

int Ranger::Return(){
    return dice->nextInt();
}

void Ranger::operator>>(const Party& otherParty) const{
    if (otherParty.getNumMembers() == 0){
        return;
    }
    
     int damage = 0;
     int numActions = this->numShots * this->speed;

     for (int s=0; s < numActions; s++){

        int diceRoll = this->dice->nextInt();

        if (diceRoll == 20) //damage 3*pow diceRoll 13-19 2*pow 6-12 1*pow 1-5 0 
     {
        damage = this->power*3;
     }else if(diceRoll<=19 and diceRoll>=13){
       damage = this->power*2;
     }
     else if(diceRoll<=12 and diceRoll>=6){
         damage = this->power*1;
     }else if (diceRoll<=5 and diceRoll>=1){
        damage = 0;
     }

      int targetIndex = s % otherParty.getNumMembers();
      Player* targetPlayer = otherParty.members[targetIndex];

        std::cout << this->name << " rolled a " << diceRoll 
                  << " and does " << damage << " damage to " 
                  << targetPlayer.name << std::endl;
     }


 }
 
void Ranger::operator>>=(Party& otherParty){
      if (otherParty.getNumMembers() == 0){
        return;
    }
    
     int damage = 0;
     int numActions = this->numShots * this->speed;

     for (int s=0; s < numActions; s++){

        int diceRoll = this->dice->nextInt();

        if (diceRoll == 20) 
     {
        damage = this->power*3;
     }else if(diceRoll<=19 and diceRoll>=13){
       damage = this->power*2;
     }
     else if(diceRoll<=12 and diceRoll>=6){
         damage = this->power*1;
     }else if (diceRoll<=5 and diceRoll>=1){
        damage = 0;
     }

     otherParty.me

      int targetIndex = s % otherParty.getNumMembers();
      Player* targetPlayer = otherParty.members[targetIndex];

        std::cout << this->name << " rolled a " << diceRoll 
                  << " and does " << damage << " damage to " 
                  << targetPlayer.name << std::endl;
     }

    }

void Ranger::operator<<(const Party& otherParty) const{

    }
void Ranger::operator<<=(Party& otherParty){

    }