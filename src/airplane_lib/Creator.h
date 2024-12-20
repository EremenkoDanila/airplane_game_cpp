#ifndef Creator_h
#define Creator_h
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "AirVehicle_class.h"
#include "shooting_lib/shooting_header.h"

class Creator{
    public:
    Creator(){std::cout << "Creator was created" << std::endl;};
    virtual ~Creator(){std::cout << "Creator was deleted" << std::endl;};
    virtual AirVehicle* CreatAirplane(
                                      char flg, int hp, int speed, const std::string& texturePath,
                                      const sf::Vector2f& position, const unsigned int KWINDOW_WIDTH,
                                      const unsigned int KWINDOW_HEIGHT
                                        )=0;
    virtual void RemoveAirplane(AirVehicle *airplane)=0;
};

#endif 