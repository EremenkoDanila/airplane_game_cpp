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
    void RemoveObject(AirVehicle* object) override;
    

     void Set_hp(int hp_);
     void Set_speed(int speed_);

     void SetTexture(const std::string& texturePath);
     void SetPosition(const sf::Vector2f& position) ;

     const sf::Texture& GetTexture();
           sf::Vector2f GetPosition() ; 
     void MoveSprite();
     void MoveSprite(std::vector<char> mass_for_move, int now );
     void Display(sf::RenderWindow& window);
     void Shoot(); 
     void UpdateShooting(sf::RenderWindow& window) ; 
};



#endif 