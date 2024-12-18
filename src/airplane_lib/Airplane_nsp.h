#ifndef airplane_lib
#define airplane_lib
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "shooting_lib/shooting_header.h"
#include "AirVehicle_class.h"
#include "Airplane_class.h"


namespace airplane{
void MoveSpriteUserControl(sf::Sprite&, int,sf::Vector2u,unsigned int window_width,unsigned int window_height);
}



#endif