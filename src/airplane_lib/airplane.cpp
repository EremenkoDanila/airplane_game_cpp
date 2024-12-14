#include "airplane_header.h"

void moveSprite_all(sf::Sprite& sprite, int speed, sf::Vector2u size,unsigned int window_width,unsigned int window_height) {
    int width = size.x;
    int height = size.y;
    //переделать под длину 
    sf::Vector2f position = sprite.getPosition();
    // Получаем состояние клавиш
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and (position.y > 0 )) {
        // Перемещаем спрайт вверх
        sprite.move(0.f, -speed);  // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and (position.y < (window_height-(window_height*0.01))-(height/2))) 
    {
        // Перемещаем спрайт вниз
        sprite.move(0.f,speed);   // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and (position.x > (width/2) )) {
        // Перемещаем спрайт влево
        sprite.move(-speed, 0.f);  // Изменение координаты X
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and (position.x < (window_width-(window_width*0.01)) )) {
        // Перемещаем спрайт вправо
        sprite.move(speed, 0.f);   // Изменение координаты X
    }
    
}

airplane_friend::airplane_friend(){
    std::cout<<"the airplane_friend was created without some parametrs"<<std::endl;
}

    // Конструктор с параметрами
airplane_friend::airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position, unsigned int window_width, unsigned int window_height){
    this->hp = hp_;
    this->speed = speed_;
    this->window_width=window_width;
    this->window_height=window_height;
    setTexture(texturePath);
    setPosition(position);
    sprite.rotate(90);
    sprite.scale(0.5f, 0.5f);
    std::cout<<"the airplane_friend was created"<<std::endl;
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


air_vehicles* ConcreteCreator::creat_airplane_friend(int hp_, int speed_, const std::string& texturePath,const sf::Vector2f& position,unsigned int window_width, unsigned int window_height) {
    std::cout<<"the ConcreteCreator is trying to  created a airplane_friend"<<std::endl;
     return new airplane_friend(hp_, speed_, texturePath, position, window_width,window_height);
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



    ImageEditor::ImageEditor() {}
    ImageEditor::~ImageEditor() {
        for (auto object : objects) {
            delete object;
        }
    }

    // Метод для добавления нового объекта
    void ImageEditor::addObject(air_vehicles* object) {
        objects.push_back(object);
    }

    // Метод для удаления объекта
    void ImageEditor::removeObject(air_vehicles* object) {
        auto it = std::find(objects.begin(), objects.end(), object);
        if (it != objects.end()) {
            delete *it;
            objects.erase(it);
        }
    }

    // Метод для перемещения всех объектов
    void ImageEditor::moveAllObjects() {
        for (auto object : objects) {
            object->moveSprite();
        }
    }

    // Метод для изменения скорости всех объектов
    void ImageEditor::changeSpeedOfAllObjects(int newSpeed) {
        for (auto object : objects) {
            object->set_speed(newSpeed);
        }
    }

    // Метод для отображения всех объектов
    void ImageEditor::renderAllObjects(sf::RenderWindow& window) {
        for (auto object : objects) {
            object->display(window);
        }
    }



    ImageEditor::ImageEditor(int number_of_plane){
        
    }