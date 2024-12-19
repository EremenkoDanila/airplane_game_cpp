#ifndef ConcreteCreator_h
#define ConcreteCreator_h
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "AirVehicle_class.h"
#include "shooting_lib/shooting_header.h"
#include "Creator.h"

class ConcreteCreator : public Creator{
 public:
    ConcreteCreator();
    ~ConcreteCreator() override;
    AirVehicle* CreatAirplane(char flg, int hp, int speed, const std::string& texturePath,
                              const sf::Vector2f& position, const unsigned int KWINDOW_WIDTH,
                              const unsigned int KWINDOW_HEIGHT) override;
    void RemoveAirplane(AirVehicle *airplane) override;
};


#endif 