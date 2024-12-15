#include "airplane_header.h"
#include "airplane_friend.h"





sf::Vector2f airplane_friend::getPosition() {
    return sprite.getPosition();
}  


airplane_friend::airplane_friend() : shooting("../pic/bullet.png", 10.f) {
    std::cout<<"the airplane_friend was created without some parametrs"<<std::endl;
}


   

airplane_friend::airplane_friend(char flg, int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position, unsigned int window_width, unsigned int window_height) : shooting("../pic/bullet.png", 10.f) {
    this->hp = hp_;
    this->speed = speed_;
    this->window_width=window_width;
    this->window_height=window_height;
    setTexture(texturePath);
    setPosition(position);
    if (flg == 'f') {
        sprite.rotate(90);
        sprite.scale(0.5f, 0.5f);
         std::cout<<"the airplane_friend was created"<<std::endl;
    }
    if(flg == 'e') {
        sprite.rotate(-90);
        sprite.scale(0.2f, 0.2f);
         std::cout<<"the airplane_enemy was created"<<std::endl;
    }
}


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



void airplane_friend:: display(sf::RenderWindow& window) {;
    window.draw(sprite);
}


const sf::Texture& airplane_friend::getTexture(){
    return texture;
}


void airplane_friend::moveSprite(std::vector<char> mass_for_move,int now)
{
    int speed_tmp = this->speed;
    if (static_cast<int>(mass_for_move.size()) > now)
    {
        char tmp = mass_for_move[now];
         switch(tmp) {
            case 'w':
                sprite.move(0.f, -speed_tmp);  // Изменение координаты Y вверх
                break;
            case 's':
                sprite.move(0.f, speed_tmp);   // Изменение координаты Y вниз
                break;
            case 'a':
                sprite.move(-speed_tmp, 0.f);  // Изменение координаты X влево
                break;
            case 'd':
                sprite.move(speed_tmp, 0.f);   // Изменение координаты X вправо
                break;
            default:
                break;
        }
    }

}

void airplane_friend::moveSprite() {

    airplane::moveSprite_all(sprite, speed, texture.getSize(), window_width, window_height);

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



    // Реализация метода стрельбы
void airplane_friend::shoot() {
    shooting.shoot(getPosition()); // Стрельба из текущей позиции самолёта
}

// Обновление снарядов
void airplane_friend::updateShooting(sf::RenderWindow& window) {
    shooting.update(window); // Обновление и отрисовка снарядов
}
