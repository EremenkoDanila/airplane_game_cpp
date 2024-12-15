#ifndef Component_h
#define Component_h

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "air_vehicles.h"
#include "shooting_lib/shooting_header.h"

#include "air_vehicles.h"
#include "Creator.h"
#include "Composite.h"


class Component : public Composite, public air_vehicles {
    private:
    std::vector<air_vehicles*> objects; 

    public:
    Component();
    Component(int number_of_plane);
    ~Component();
    void addObject(air_vehicles* object) override;
    void removeObject(air_vehicles* object) override;
    void moveAllObjects() override;
    void moveAllObjects(std::vector<char> mass_for_move, int now) override;
    void changeSpeedOfAllObjects(int newSpeed) override;
    void renderAllObjects(sf::RenderWindow& window) override;
    void shootAllObjects() override;
    void updateShootingForAllObjects(sf::RenderWindow& window) override;




     void set_hp(int hp_);
     void set_speed(int speed_);

     void setTexture(const std::string& texturePath);
     void setPosition(const sf::Vector2f& position) ;

     const sf::Texture& getTexture();
           sf::Vector2f getPosition() ; 
     void moveSprite();
     void moveSprite(std::vector<char> mass_for_move, int now );
     void display(sf::RenderWindow& window);
     void shoot(); 
     void updateShooting(sf::RenderWindow& window) ; 
};



#endif 