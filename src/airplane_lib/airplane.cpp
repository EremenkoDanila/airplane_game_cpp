#include "airplane_header.h"
#include "airplane_friend.h"
#include "air_vehicles.h"
#include "Creator.h"
#include "ConcreteCreator.h"
#include "Component.h"

void airplane::MoveSpriteUserControl(sf::Sprite& sprite, int speed, sf::Vector2u size,unsigned int window_width,unsigned int window_height){
    int width = size.x;
    int height = size.y;
    //переделать под длину 
    sf::Vector2f position = sprite.getPosition();
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (position.y > 0 )){
        // Перемещаем спрайт вверх
        sprite.move(0.f, -speed);  
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (position.y < (window_height - (window_height * 0.01)) - (height / 2))){
        // Перемещаем спрайт вниз
        sprite.move(0.f,speed);   
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (position.x > (width / 2) )) {
        // Перемещаем спрайт влево
        sprite.move(-speed, 0.f);  
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (position.x < (window_width-(window_width * 0.01)) - 450)){
        // Перемещаем спрайт вправо
        sprite.move(speed, 0.f);   
    }
}
