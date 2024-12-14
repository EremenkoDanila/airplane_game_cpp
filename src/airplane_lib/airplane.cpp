#include "airplane_header.h"

void moveSprite_all(sf::Sprite& sprite, int speed, sf::Vector2u size) {
    int width = size.x;
    int height = size.y;
    //переделать под длину 
    sf::Vector2f position = sprite.getPosition();
    // Получаем состояние клавиш
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (position.y > 0 )) {
        // Перемещаем спрайт вверх
        sprite.move(0.f, -speed);  // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (position.y < 1000-(height/2))) 
    {
        // Перемещаем спрайт вниз
        sprite.move(0.f,speed);   // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (position.x > (width/2) )) {
        // Перемещаем спрайт влево
        sprite.move(-speed, 0.f);  // Изменение координаты X
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (position.x < 1900 )) {
        // Перемещаем спрайт вправо
        sprite.move(speed, 0.f);   // Изменение координаты X
    }
    
}


    // Конструктор с параметрами
airplane_friend::airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position){
    this->hp = hp_;
    this->speed = speed_;
    setTexture(texturePath);
    setPosition(position);
    sprite.rotate(90);
    sprite.scale(0.5f, 0.5f);
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

void airplane_friend::moveSprite() {
    ::moveSprite_all(sprite, speed, texture.getSize());

    bool isSpeedUp = true; 
    bool isSlowDown = true; 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        // Перемещаем спрайт вправо
        speed = 15;
        isSpeedUp = false; 
    }
    // сделать откат по времени 
    if (speed > 5){speed -=0.01;}
}


void airplane_friend:: display(sf::RenderWindow& window) {;
    window.draw(sprite);
}

const sf::Texture& airplane_friend::getTexture(){
    return texture;
}


air_vehicles* ConcreteCreator::creat_airplane_friend(int hp_, int speed_, const std::string& texturePath,const sf::Vector2f& position) {
  return new airplane_friend(hp_, speed_, texturePath, position);
}

void ConcreteCreator::remove_airplane_friend(air_vehicles* airplane) {
    delete airplane;
}




