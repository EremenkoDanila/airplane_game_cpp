#ifndef game_map
#define game_map

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

void moveSprite(sf::Sprite& sprite);
class air_vehicles{
    public:
    virtual ~air_vehicles();
    virtual void set_hp() = 0;
    virtual void set_speed() = 0;

    virtual void setTexture() = 0;
    virtual void setPosition() = 0;

    virtual void moveSprite(sf::Sprite& sprite) = 0;
};

class airplane_friend : public air_vehicles{
    private:

    unsigned int hp;
    unsigned int speed;

    sf::Sprite sprite;    
    sf::Texture texture; 

    public:
    ~airplane_friend();
    airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position);
    void set_hp(int hp_) {hp = hp_;}
    void set_speed(int speed_)  { speed= speed_;} 

    void setTexture(const std::string& texturePath);
    void setPosition(const sf::Vector2f& position);

    void moveSprite(sf::Sprite& sprite);

};


class Creator{
    public:
    virtual ~Creator();
    virtual air_vehicles *airplane_friend()=0;

};

class ConcreteCreator : public Creator{
    public:
    ~ConcreteCreator();
    air_vehicles *airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position)
     {
        return new airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position)
     };
};

#endif