#ifndef ConcreteCreator_h
#define ConcreteCreator_h

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "air_vehicles.h"
#include "shooting_lib/shooting_header.h"

#include "air_vehicles.h"
#include "Creator.h"

class ConcreteCreator : public Creator{
 public:
    ConcreteCreator();
    ~ConcreteCreator() override;
    AirVehicle* CreatAirplaneFriend(char flg, int hp, int speed, const std::string& texturePath,
                                    const sf::Vector2f& position, unsigned int window_width, unsigned int window_height) override;
    void RemoveAirplane(AirVehicle *airplane) override;
};


#endif 