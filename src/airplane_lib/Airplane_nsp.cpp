#include "airplane_nsp.h"
#include "Airplane_class.h"
#include "AirVehicle_class.h"
#include "Creator.h"
#include "ConcreteCreator.h"
#include "Component.h"

void airplane::MoveSpriteUserControl(sf::Sprite& sprite, int speed,
                                     sf::Vector2u size, const unsigned int KWINDOW_WIDTH,
                                     const unsigned int KWINDOW_HEIGHT){
    int width = size.x;
    int height = size.y;
    //переделать под длину 
    sf::Vector2f position = sprite.getPosition();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (position.y > 0 )){
        // Перемещаем спрайт вверх
        sprite.move(0.f, -speed);  
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (position.y < (KWINDOW_HEIGHT - (KWINDOW_HEIGHT * 0.01)) - (height / 2))){
        // Перемещаем спрайт вниз
        sprite.move(0.f,speed);   
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (position.x > (width / 2) )) {
        // Перемещаем спрайт влево
        sprite.move(-speed, 0.f);  
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (position.x < (KWINDOW_WIDTH-(KWINDOW_WIDTH * 0.01)) - 600)){
        // Перемещаем спрайт вправо
        sprite.move(speed, 0.f);   
    }
}


std::vector<sf::Sprite>& Airplane::getProjectiles() {
    return shooting.getProjectiles();
}

sf::FloatRect Airplane::GetBounds() const {
    return sprite_.getGlobalBounds();  // Возвращаем границы спрайта
}