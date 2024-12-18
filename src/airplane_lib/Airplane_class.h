#ifndef AIRPLANE_FRIEND_H
#define AIRPLANE_FRIEND_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "AirVehicle_class.h"
#include "shooting_lib/shooting_header.h"

class Airplane : public AirVehicle{
 private:
    unsigned int hp_;
    unsigned int speed_;
    sf::Sprite sprite_;    
    sf::Texture texture_; 
    unsigned int window_width_;
    unsigned int window_height_;
    Shooting shooting;

    void AddObject(AirVehicle* object);
    void RemoveObject(AirVehicle* object);
    
 public:
    Airplane();
    ~Airplane() override = default;
    Airplane(char flg, int hp, int speed, 
             const std::string& texturePath,
             const sf::Vector2f& position, 
             unsigned int window_width, 
             unsigned int window_height);
    void Set_hp(int hp_);
    void Set_speed(int speed_);
    void SetTexture(const std::string& texturePath);
    void SetPosition(const sf::Vector2f& position);
    const sf::Texture& GetTexture();
    sf::Vector2f GetPosition() override; 
    void MoveSprite();
    void MoveSprite(std::vector<char> mass_for_move,  int now) override;
    void Display(sf::RenderWindow& window);
    void Shoot() override; 
    void UpdateShooting(sf::RenderWindow& window) override; 
};

#endif 