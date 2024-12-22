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
      sf::Vector2f GetPosition();
      sf::FloatRect GetBounds() const override;
      void MoveSprite();
      void MoveSprite(std::vector<char> mass_for_move, int mov_num);
      void Display(sf::RenderWindow& window);
      void Shoot(); 
      void Shoots();
      void UpdateShooting(sf::RenderWindow& window);
      void RemoveDestroyedObjects();
      void TakeDamage(int damage) override;
      void HandleInput(sf::Keyboard::Key key) override;
      bool IsDestroyed() const override;
      std::vector<sf::Sprite>& getProjectiles() override;



      void UpdateShooting(sf::RenderWindow& window, AirVehicle* user);
};

#endif 