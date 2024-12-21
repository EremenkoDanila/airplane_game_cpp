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
    bool destroyed = false; 
 public:
    Airplane();
    ~Airplane();
    Airplane(char flg, int hp, int speed, 
             const std::string& texturePath,
             const sf::Vector2f& position, 
             const unsigned int KWINDOW_WIDTH, 
             const unsigned int KWINDOW_HEIGHT);
    void SetHp(int hp);
    void SetSpeed(int speed);
    void SetTexture(const std::string& texturePath);
    void SetPosition(const sf::Vector2f& position);
    const sf::Texture& GetTexture() override;
    sf::Vector2f GetPosition() override; 
    void MoveSprite();
    void MoveSprite(std::vector<char> mass_for_move,  int mov_num) override;
    void Display(sf::RenderWindow& window);
    void Shoot() override; 
    void UpdateShooting(sf::RenderWindow& window) override; 
    void HandleInput(sf::Keyboard::Key key) override;  // Смена оружия
    void TakeDamage(int damage);  // Уменьшить HP при попадании пули
    bool IsDestroyed() const override;     // Проверить, уничтожен ли самолет
    std::vector<sf::Sprite>& getProjectiles() override;
    sf::FloatRect GetBounds() const override;
};

#endif 