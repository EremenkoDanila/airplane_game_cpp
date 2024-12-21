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
    /*
    // Границы спрайта
    sf::FloatRect bounds = sprite.getGlobalBounds();

    // Рассчитываем центр самолета (относительно верхнего левого угла)
    sf::Vector2f center_offset(bounds.width / 2, bounds.height / 2);

    // Рассчитываем смещение для носа самолета
    sf::Vector2f nose_offset(bounds.width / 2, 0);  // Смещение вправо по умолчанию

    // Если враг, корректируем смещение влево
    if (shooting.GetDirection() < 0) {  // Если враг стреляет влево
        nose_offset.x = -bounds.width / 2;
    }

    // Итоговая позиция: верхний левый угол + центр + смещение носа
    return position + center_offset + nose_offset;
    */
}


airplane_friend::airplane_friend() : shooting("../pic/bullet.png", 10.f) {
    std::cout<<"the airplane_friend was created without some parametrs"<<std::endl;
}

std::vector<sf::Sprite>& airplane_friend::getProjectiles() {
    return shooting.getProjectiles();
}

sf::FloatRect airplane_friend::getBounds() const {
    return sprite.getGlobalBounds();  // Возвращаем границы спрайта
}


    // Конструктор с параметрами

airplane_friend::airplane_friend(char flg, int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position, unsigned int window_width, unsigned int window_height)
    : shooting("../pic/bullet.png", 10.f, (flg == 'f' ? 1.f : -1.f)) {  // Передача направления
    this->hp = hp_;
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

// Метод для проверки, уничтожен ли самолет
bool airplane_friend::isDestroyed() const {
    return destroyed;  // Возвращает состояние уничтожения
}

// Реализация метода стрельбы
void airplane_friend::shoot() {
    //shooting.Shoot(getPosition()); // Стрельба из текущей позиции самолёта
    // Получаем текущую позицию самолета (верхний левый угол спрайта)
    sf::Vector2f position = sprite.getPosition();

    // Получаем границы спрайта
    sf::FloatRect sprite_bounds = sprite.getGlobalBounds();

    // Инициализируем смещения
    float bullet_x = position.x;  // По оси X
    float bullet_y = position.y;  // По оси Y

    // Для союзного самолета: пули из правой стороны, центр по высоте
    if (shooting.GetDirection() > 0) {  // Направление вправо
        bullet_x -= sprite_bounds.width / 5;  // Смещение влево
        bullet_y += sprite_bounds.height / 2.5;  // Центр по высоте
    }

    // Для вражеского самолета: пули выходят слева, выше центра
    else if (shooting.GetDirection() < 0) {  // Направление влево
        bullet_x += sprite_bounds.width / 4;  // Смещение вправо
        bullet_y -= sprite_bounds.height / 1.75;  // Поднимаем пули вверх
    }

    // Итоговая позиция пули
    sf::Vector2f bullet_position(bullet_x, bullet_y);

    // Отладочный вывод
    std::cout << "Bullet position: x=" << bullet_position.x << ", y=" << bullet_position.y << std::endl;

    // Передаём позицию для создания пули
    shooting.Shoot(bullet_position);
}

// Обновление снарядов
void airplane_friend::updateShooting(sf::RenderWindow& window) {
    shooting.Update(window); // Обновление и отрисовка снарядов
}

void airplane_friend::handleInput(sf::Keyboard::Key key) {
    shooting.HandleInput(key);  // Переключение стратегии стрельбы через объект Shooting
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

void airplane_friend::takeDamage(int damage) {
    hp -= damage;  // Уменьшаем здоровье
    std::cout << "Airplane hit! HP remaining: " << hp << std::endl;

    if (hp <= 0) {
        std::cout << "Airplane destroyed!" << std::endl;
        destroyed = true;  // Устанавливаем флаг уничтожения
    }
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
        object->updateShooting(window);  // Обновляем снаряды объекта

        // Проверяем столкновения с другими объектами
        for (auto target : objects) {
            if (object == target) continue;  // Пропускаем проверку с самим собой

            // Получаем пули объекта
            std::vector<sf::Sprite>& projectiles = object->getProjectiles();
            for (auto it = projectiles.begin(); it != projectiles.end();) {
                if (target->getBounds().intersects(it->getGlobalBounds())) {
                    target->takeDamage(10);  // Уменьшаем здоровье цели
                    it = projectiles.erase(it);  // Удаляем пулю
                } else {
                    ++it;
                }
            }
        }
    }
}

    void Component::removeDestroyedObjects() {
        for (auto it = objects.begin(); it != objects.end();) {
            if ((*it)->isDestroyed()) {  // Проверяем, уничтожен ли объект
                delete *it;              // Освобождаем память
                it = objects.erase(it);  // Удаляем объект из списка
            } else {
                ++it;
            }
        }
    }
  



    Component::Component(int number_of_plane){

    }