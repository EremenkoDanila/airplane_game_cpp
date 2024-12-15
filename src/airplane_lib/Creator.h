#ifndef Creator_h
#define Creator_h

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "air_vehicles.h"
#include "shooting_lib/shooting_header.h"

#include "air_vehicles.h"

class Creator{
    public:
    Creator(){};
    virtual ~Creator(){};
    virtual air_vehicles *creat_airplane_friend(
                                            char flg, int hp_, int speed_, const std::string& texturePath,
                                            const sf::Vector2f& position, unsigned int window_width, unsigned int window_height
                                            )=0;
    virtual void remove_airplane_friend(air_vehicles *airplane)=0;
};

#endif 