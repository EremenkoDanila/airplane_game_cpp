#include "airplane_header.h"

void moveSprite_all(sf::Sprite& sprite, int speed) {
    
    // Получаем состояние клавиш
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        // Перемещаем спрайт вверх
        sprite.move(0.f, -speed);  // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        // Перемещаем спрайт вниз
        sprite.move(0.f,speed);   // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        // Перемещаем спрайт влево
        sprite.move(-speed, 0.f);  // Изменение координаты X
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        // Перемещаем спрайт вправо
        sprite.move(speed, 0.f);   // Изменение координаты X
    }

}


    // Конструктор с параметрами
   airplane_friend::airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position) 
   {
        this->hp = hp_;
        this->speed = speed_;
        setTexture(texturePath);
        setPosition(position);

    }


    // Установка текстуры и позиции
    void airplane_friend::setTexture(const std::string& texturePath) {
        if (!texture.loadFromFile(texturePath)) {
            std::cerr << "Failed to load airplane texture from: " << texturePath << std::endl;
            throw std::runtime_error("Texture loading failed");
        }
        sprite.setTexture(texture);
    }

    void airplane_friend::setPosition(const sf::Vector2f& position) {
        sprite.setPosition(position);
    }

void airplane_friend::moveSprite(
    //int test
    ) {
    ::moveSprite_all(sprite, speed); 
}


void airplane_friend:: display(sf::RenderWindow& window) {;
    window.draw(sprite);
}


air_vehicles* ConcreteCreator::creat_airplane_friend(int hp_, int speed_, const std::string& texturePath,const sf::Vector2f& position) 
{
  return new airplane_friend(hp_, speed_, texturePath, position);
}

void ConcreteCreator::remove_airplane_friend(air_vehicles* airplane) {delete airplane;}
