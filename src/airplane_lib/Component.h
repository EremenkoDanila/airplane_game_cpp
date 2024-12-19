#ifndef Component_h
#define Component_h
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "AirVehicle_class.h"
#include "shooting_lib/shooting_header.h"
#include "Creator.h"


class Component : public AirVehicle {
 private:
      std::vector<AirVehicle*> objects_; 
 public:
      Component();
      Component(int number_of_plane);
      ~Component();
      void AddObject(AirVehicle* object) override;
      void RemoveObject(AirVehicle* object) override;
      void SetHp(int hp);
      void SetSpeed(int speed);
      void SetTexture(const std::string& texturePath);
      void SetPosition(const sf::Vector2f& position) ;
      const sf::Texture& GetTexture();
      sf::Vector2f GetPosition() ; 
      void MoveSprite();
      void MoveSprite(std::vector<char> mass_for_move, int mov_num);
      void Display(sf::RenderWindow& window);
      void Shoot(); 
      void UpdateShooting(sf::RenderWindow& window) ; 
};



#endif 