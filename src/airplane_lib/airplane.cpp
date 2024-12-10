#include "airplane_header.h"

void moveSprite(sf::Sprite& sprite) {
    // Получаем состояние клавиш
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        // Перемещаем спрайт вверх
        sprite.rotate(-45.f);
        sprite.move(0.f, -5.f);  // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        // Перемещаем спрайт вниз
         sprite.rotate(45.f);
        sprite.move(0.f, 5.f);   // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        // Перемещаем спрайт влево
         sprite.rotate(-90.f);
        sprite.move(-5.f, 0.f);  // Изменение координаты X
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        // Перемещаем спрайт вправо
         sprite.rotate(90.f);
        sprite.move(5.f, 0.f);   // Изменение координаты X
    }
}

airplane_friend::airplane_friend() {}

airplane_friend::~airplane_friend() {}

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

void airplane_friend::moveSprite(sf::Sprite& sprite) {}


void airplane_friend:: display(sf::RenderWindow& window) {;
    window.draw(sprite);
}

// Реализация деструктора для класса air_vehicles
air_vehicles::~air_vehicles() {}

// Реализация деструктора для класса Creator
Creator::~Creator() {}
Creator::Creator() {}



ConcreteCreator::ConcreteCreator() {}

ConcreteCreator::~ConcreteCreator() {}

air_vehicles* ConcreteCreator::creat_airplane_friend(int hp_, int speed_, const std::string& texturePath,const sf::Vector2f& position) 
{
  return new airplane_friend(hp_, speed_, texturePath, position);
}

void ConcreteCreator::remove_airplane_friend(air_vehicles* airplane) {}
