#ifndef Component_h
#define Component_h

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "air_vehicles.h"
#include "shooting_lib/shooting_header.h"

#include "air_vehicles.h"
#include "Creator.h"


class Component : public AirVehicle {
    private:
    std::vector<AirVehicle*> objects; 

    public:

    Component();
    Component(int number_of_plane);
    ~Component();
        
    void AddObject(AirVehicle* object) override;
    void removeObject(AirVehicle* object) override;
    

     void set_hp(int hp_);
     void set_speed(int speed_);

     void setTexture(const std::string& texturePath);
     void setPosition(const sf::Vector2f& position) ;

     const sf::Texture& getTexture();
           sf::Vector2f getPosition() ; 
     void MoveSprite();
     void MoveSprite(std::vector<char> mass_for_move, int now );
     void Display(sf::RenderWindow& window);
     void Shoot(); 
     void UpdateShooting(sf::RenderWindow& window) ; 
};



#endif 