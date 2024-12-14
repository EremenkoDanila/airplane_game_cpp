#include "airplane_header.h"

void moveSprite_all(sf::Sprite& sprite, int speed, sf::Vector2u size,unsigned int window_width,unsigned int window_height) {
    int width = size.x;
    int height = size.y;
    //переделать под длину 
    sf::Vector2f position = sprite.getPosition();
    // Получаем состояние клавиш
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (position.y > 0 )) {
        // Перемещаем спрайт вверх
        sprite.move(0.f, -speed);  // Изменение координаты Y
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (position.y < (window_height-(window_height*0.01))-(height/2))) 
    {
        // Перемещаем спрайт вниз
        sprite.move(0.f,speed);   // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (position.x > (width/2) )) {
        // Перемещаем спрайт влево
        sprite.move(-speed, 0.f);  // Изменение координаты X
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (position.x < (window_width-(window_width*0.01)) )) {
        // Перемещаем спрайт вправо
        sprite.move(speed, 0.f);   // Изменение координаты X
    }
}

//-------------------------------------

sf::Vector2f airplane_friend::getPosition() {
    return sprite.getPosition();
    }  


airplane_friend::airplane_friend() : shooting("../../pic/bullet.png", 10.f) {
    std::cout<<"the airplane_friend was created without some parametrs"<<std::endl;
}


    // Конструктор с параметрами

airplane_friend::airplane_friend(char flg, int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position, unsigned int window_width, unsigned int window_height) : shooting("../../pic/bullet.png", 10.f) {
    this->hp = hp_;
    this->speed = speed_;
    this->window_width=window_width;
    this->window_height=window_height;
    setTexture(texturePath);
    setPosition(position);
    if (flg == 'f') {
        sprite.rotate(90);
        sprite.scale(0.5f, 0.5f);
    }
    if(flg == 'e') {
        sprite.rotate(-90);
        sprite.scale(0.2f, 0.2f);
    }
    std::cout<<"the airplane_friend was created"<<std::endl;
}

    // Реализация метода стрельбы
void airplane_friend::shoot() {
    shooting.shoot(getPosition()); // Стрельба из текущей позиции самолёта
}

// Обновление снарядов
void airplane_friend::updateShooting(sf::RenderWindow& window) {
    shooting.update(window); // Обновление и отрисовка снарядов
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
    ::moveSprite_all(sprite, speed, texture.getSize(), window_width, window_height);

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

//-----------------------------------------


air_vehicles* ConcreteCreator::creat_airplane_friend(char flg, int hp_, int speed_, const std::string& texturePath,const sf::Vector2f& position,unsigned int window_width, unsigned int window_height) {
    std::cout<<"the ConcreteCreator is trying to  created a airplane_friend"<<std::endl;
     return new airplane_friend(flg, hp_, speed_, texturePath, position, window_width,window_height);
}


void ConcreteCreator::remove_airplane_friend(air_vehicles* airplane) {
    delete airplane;
    std::cout<<"the airplane_friend was deleted"<<std::endl;
}

ConcreteCreator::ConcreteCreator(){
    std::cout<<"the ConcreteCreator was created"<<std::endl;
}

ConcreteCreator::~ConcreteCreator(){
    std::cout<<"the ConcreteCreator was deleted"<<std::endl;
}



//----------------------------------------------------------------------------



    Component::Component() {}
    Component::~Component() {
        for (auto object : objects) {
            delete object;
        }
    }

    // Метод для добавления нового объекта
    void Component::addObject(air_vehicles* object) {
        objects.push_back(object);
    }

    // Метод для удаления объекта
    void Component::removeObject(air_vehicles* object) {
        auto it = std::find(objects.begin(), objects.end(), object);
        if (it != objects.end()) {
            delete *it;
            objects.erase(it);
        }
    }

    // Метод для перемещения всех объектов
    void Component::moveAllObjects() {
        for (auto object : objects) {
            object->moveSprite();
        }
    }


    
    void Component::moveAllObjects(std::vector<char> mass_for_move,int now) {
        for (auto object : objects) {
            object->moveSprite(mass_for_move, now);
        }
    }

    // Метод для изменения скорости всех объектов
    void Component::changeSpeedOfAllObjects(int newSpeed) {
        for (auto object : objects) {
            object->set_speed(newSpeed);
        }
    }

    // Метод для отображения всех объектов
    void Component::renderAllObjects(sf::RenderWindow& window) {
        for (auto object : objects) {
            object->display(window);
        }
    }

  // Стрельба для всех объектов
    void Component::shootAllObjects() {
        for (auto object : objects) {
            object->shoot(); // Вызываем метод стрельбы для каждого объекта
        }
    }

    // Обновление снарядов всех объектов
    void Component::updateShootingForAllObjects(sf::RenderWindow& window) {
        for (auto object : objects) {
            object->updateShooting(window); // Обновляем снаряды для каждого объекта
        }
    }
  



    Component::Component(int number_of_plane){

    }