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
    air_vehicles *creat_airplane_friend(char flg, int hp_, int speed_, const std::string& texturePath,
                                        const sf::Vector2f& position, unsigned int window_width, unsigned int window_height) override;
   //air_vehicles * creat_airplane_enemie();
    void remove_airplane_friend(air_vehicles *airplane) override;
};



#endif 