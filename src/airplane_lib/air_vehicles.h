#ifndef AIR_VEHICLES_H
#define AIR_VEHICLES_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "air_vehicles.h"
#include "shooting_lib/shooting_header.h"


class AirVehicle{
    private:
    std::string name;
    AirVehicle *parent_;

    public:
     void SetParent(AirVehicle *parent_) {
          this->parent_ = parent_;
    }

    virtual ~AirVehicle() {};
    virtual void set_hp(int hp_) = 0;
    virtual void set_speed(int speed_) = 0;

    virtual void setTexture(const std::string& texturePath) = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;


    virtual const sf::Texture& getTexture()=0;
    virtual sf::Vector2f getPosition() = 0; 
    virtual void MoveSprite()=0;
    virtual void MoveSprite(std::vector<char> mass_for_move, int now )=0;
    virtual void Display(sf::RenderWindow& window) = 0;
    virtual void Shoot() = 0; 
    virtual void UpdateShooting(sf::RenderWindow& window) = 0; 


    virtual void AddObject(AirVehicle* object) = 0;
    virtual void removeObject(AirVehicle* object) = 0;
};

#endif 