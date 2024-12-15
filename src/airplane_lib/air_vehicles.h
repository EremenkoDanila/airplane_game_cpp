#ifndef AIR_VEHICLES_H
#define AIR_VEHICLES_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "air_vehicles.h"
#include "shooting_lib/shooting_header.h"


class air_vehicles{
    private:
    std::string name;
    air_vehicles *parent_;

    public:
     void SetParent(air_vehicles *parent_) {
          this->parent_ = parent_;
    }

    virtual ~air_vehicles() {};
    virtual void set_hp(int hp_) = 0;
    virtual void set_speed(int speed_) = 0;

    virtual void setTexture(const std::string& texturePath) = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;


    virtual const sf::Texture& getTexture()=0;
    virtual sf::Vector2f getPosition() = 0; 
    virtual void moveSprite()=0;
    virtual void moveSprite(std::vector<char> mass_for_move, int now )=0;
    virtual void display(sf::RenderWindow& window) = 0;
    virtual void shoot() = 0; 
    virtual void updateShooting(sf::RenderWindow& window) = 0; 


    virtual void addObject(air_vehicles* object) = 0;
    virtual void removeObject(air_vehicles* object) = 0;
};

#endif 