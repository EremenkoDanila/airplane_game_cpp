#ifndef Composite_h
#define Composite_h

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "air_vehicles.h"
#include "shooting_lib/shooting_header.h"

#include "air_vehicles.h"
#include "Creator.h"


class Composite {
    public:
    Composite(){};
    virtual ~Composite(){};
    virtual void addObject(air_vehicles* object)=0;
    virtual void removeObject(air_vehicles* object)=0;
    virtual void moveAllObjects()=0;
    virtual void moveAllObjects(std::vector<char> mass_for_move, int now)=0;
    virtual void changeSpeedOfAllObjects(int newSpeed)=0;
    virtual void renderAllObjects(sf::RenderWindow& window)=0;
    virtual void shootAllObjects() = 0;
    virtual void updateShootingForAllObjects(sf::RenderWindow& window) = 0;    
};


#endif 