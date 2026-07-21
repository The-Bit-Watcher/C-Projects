#include "Player.h"

Player::Player(std::string name, int health, int power, int speed){
    this->name = name;
    this->health = health;
    this->power = power;
    this->speed = speed;
    
    int seed = health * power * speed + health + power + speed;
   this->dice = new RandomNumberGenerator(seed);
}

Player::Player(const Player& other){
    this->name = other.name;
    this->health = other.health;
    this->power = other.power;
    this->speed = other.speed;
    this->dice = new RandomNumberGenerator(*other.dice);
}

Player& Player::operator=(const Player& other){
    this->name = other.name;
    this->health = other.health;
    this->power = other.power;
    this->speed = other.speed;
    this->dice = new RandomNumberGenerator(*other.dice);//makes deep copy
    return *this;
}



Player::~Player(){
    this->dice = NULL;
}

std::ostream& operator<<(std::ostream& os, const Player& player){
    os << player.name << player.health << player.power << player.speed;

    return os;
}

 Player::operator std::string() const{
      std::ostringstream oss;
        oss << name << ": health=" << health << ", power=" << power << ", speed=" << speed;
        return oss.str();
}

void Player::operator>>(const Party& otherParty)const{
  
}

 void Player::operator>>=(Party& otherParty){
  
}

void Player::operator<<(const Party& otherParty)const{

}

void Player::operator<<=( Party& otherParty){

}

void Player::changeHealth(int change){
    this->health += change;
}

void Player::changePower(int change){
    this->power += change;
}

void Player::changeSpeed(int change){
    this->speed += change;
}

std::string Player::getName(){
    return this->name;
}

int Player::getHealth(){
  return health;
}

