#include <cstdio>
#include <iostream>

#include "RandomNumberGenerator.h"
//
#include "Party.h"
//
#include "Player.h"
//
/*#include "MeleeWarrior.h"
#include "Ranger.h"
#include "Support.h"

#include "Barbarian.h"
#include "Cleric.h"
#include "Druid.h"
//#include "Rogue.h"
#include "SiegeWeapon.h"
#include "Wizard.h"*/
#include "Ranger.h"

int main(int argc, char* argv[]) {

     std::string name = "Peter Pan";
     int health, power,speed;
     health = 25; speed = 20; power =10; int numShots = 5;
    Ranger a(name, health,power,speed,numShots);
    Ranger b("js",10,5,23,6);
    Ranger c("ks",120,2,12,7);
    std::cout << a.operator std::string()<<std::endl;//works
    std::cout << b.operator std::string()<<std::endl;
    std::cout << c.operator std::string()<<std::endl;//works


    Party output(a);
    std::cout << output.getNumMembers()<<std::endl;
    std::cout << *a.clone() << std::endl;//works

    output.operator+(b);//works
    std::cout<< *output.operator[](0) << std::endl;//first one works
   
    
     std::cout << output.operator-(1) <<std::endl;


 //std::cout << output.operator[](1)->getName()<<std::endl;//causes error

    /*SiegeWeapon s1("SiegeWeapon1", 100, 2, 2, 5);
    Party p1(s1);

    Druid d1("Druid1", 50, 5, 2, 20);
    Party p2(d1);

    p1 >>= p2;
    p2 >>= p1;

    std::cout << "Party 1 : " << p1 << std::endl
              << "Party 2 : " << p2 << std::endl;*/



    return 0;
}