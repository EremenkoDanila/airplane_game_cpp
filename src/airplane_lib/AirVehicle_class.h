#ifndef AirVehicle_H
#define AirVehicle_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "shooting_lib/shooting_header.h"

class AirVehicle{
 private:
    AirVehicle* parent_;

 public:
    void SetParent(AirVehicle *parent) {this->parent_ = parent;}
    virtual ~AirVehicle() {};
    virtual void SetHp(int hp) = 0;
    virtual void SetSpeed(int speed) = 0;
    virtual void SetTexture(const std::string& texturePath) = 0;
    virtual void SetPosition(const sf::Vector2f& position) = 0;
    virtual const sf::Texture& GetTexture()=0;
    virtual sf::Vector2f GetPosition() = 0; 
    virtual void MoveSprite()=0;
    virtual void MoveSprite(std::vector<char> mass_for_move, int now )=0;
    virtual void Display(sf::RenderWindow& window) = 0;
    virtual void Shoot() = 0; 
    virtual void UpdateShooting(sf::RenderWindow& window) = 0; 
    virtual void AddObject(AirVehicle* object) = 0;
    virtual void RemoveObject(AirVehicle* object) = 0;
};

#endif 