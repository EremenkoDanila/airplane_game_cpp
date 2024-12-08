#ifndef airplane_lib
#define airplane_lib

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

void moveSprite(sf::Sprite& sprite);
class air_vehicles{
    public:
    virtual ~air_vehicles();
    virtual void set_hp(int hp_) = 0;
    virtual void set_speed(int speed_) = 0;

    virtual void setTexture(const std::string& texturePath) = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;

    virtual void moveSprite(sf::Sprite& sprite) = 0;
    virtual void display(sf::RenderWindow& window) = 0;
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
    void display(sf::RenderWindow& window);

};


class Creator{
    public:
    virtual ~Creator();
    virtual air_vehicles *creat_airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position)=0;
    virtual void remove_airplane_friend(air_vehicles *airplane)=0;
};

class ConcreteCreator : public Creator{
    public:
    ~ConcreteCreator();
    air_vehicles *creat_airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position) override
     {
        air_vehicles *tmp = new airplane_friend(hp_, speed_, texturePath, position);
        return tmp;
     }
     void remove_airplane_friend(air_vehicles *airplane) override {delete airplane;}
};

#endif