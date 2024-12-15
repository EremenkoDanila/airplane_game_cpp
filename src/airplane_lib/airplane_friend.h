#ifndef AIRPLANE_FRIEND_H
#define AIRPLANE_FRIEND_H


#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "air_vehicles.h"
#include "shooting_lib/shooting_header.h"



class airplane_friend : public air_vehicles{
    private:

    unsigned int hp;
    unsigned int speed;

    sf::Sprite sprite;    
    sf::Texture texture; 
    
     unsigned int window_width;
     unsigned int window_height;

    void addObject(air_vehicles* object){};
    void removeObject(air_vehicles* object){};

    Shooting shooting;

    public:
    airplane_friend();
    ~airplane_friend() override = default;
    airplane_friend(
                        char flg, int hp_, int speed_, const std::string& texturePath, 
                        const sf::Vector2f& position,  unsigned int window_width,
                         unsigned int window_height
                     );

    void set_hp(int hp_) {hp = hp_;}
    void set_speed(int speed_)  { speed= speed_;} 

    void setTexture(const std::string& texturePath);
    void setPosition(const sf::Vector2f& position);


    const sf::Texture& getTexture();
    sf::Vector2f getPosition() override; 
    void moveSprite();
    void moveSprite(std::vector<char> mass_for_move,  int now) override;
    void display(sf::RenderWindow& window);
    void shoot() override; 
    void updateShooting(sf::RenderWindow& window) override; 



 
};

#endif // AIRPLANE_FRIEND_H