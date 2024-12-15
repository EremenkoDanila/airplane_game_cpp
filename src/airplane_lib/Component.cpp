

#include "Component.h"

#include "air_vehicles.h"
#include "Creator.h"
#include "Composite.h"


Component::Component() {}
Component::~Component() {
    for (auto object : objects) {
        delete object;
    }
}


void Component::addObject(air_vehicles* object) {
    objects.push_back(object);
}


void Component::removeObject(air_vehicles* object) {
    auto it = std::find(objects.begin(), objects.end(), object);
    if (it != objects.end()) {
        delete *it;
        objects.erase(it);
    }
}


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


void Component::changeSpeedOfAllObjects(int newSpeed) {
    for (auto object : objects) {
        object->set_speed(newSpeed);
    }
}


void Component::renderAllObjects(sf::RenderWindow& window) {
    for (auto object : objects) {
        object->display(window);
    }
}


Component::Component(int number_of_plane){

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





void Component::set_hp(int hp_){
        for (auto object : objects) {
        object->set_hp(hp_);
    }
}
void Component::set_speed(int speed_){
    for (auto object : objects) {
        object->set_speed(speed_);
    }
}

void Component::setTexture(const std::string& texturePath){
    for (auto object : objects) {
        object->setTexture(texturePath);
    }
}


void Component::setPosition(const sf::Vector2f& position){
    for (auto object : objects) {
        object->setPosition(position);
    }
    
}

const sf::Texture& Component::getTexture() {
    if (!objects.empty()) {
        return objects.front()->getTexture(); // Возвращаем текстуру первого объекта
    }
    static const sf::Texture emptyTexture; // Для случая, когда коллекция пустая
    return emptyTexture;
}


sf::Vector2f Component::getPosition(){
    if (!objects.empty()) {
        return objects.front()->getPosition(); // Возвращаем текстуру первого объекта
    }
    static const sf::Vector2f emptyTexture; // Для случая, когда коллекция пустая
    return emptyTexture;
}

void Component::moveSprite(){
    for (auto object : objects) {
        object->moveSprite();
    }
}


void Component::moveSprite(std::vector<char> mass_for_move, int now )
{
    for (auto object : objects) {
        object->moveSprite(mass_for_move, now);
    }
    
}

void Component::display(sf::RenderWindow& window){
    for (auto object : objects) {
        object->display(window);
    }
}
void Component::shoot(){
    for (auto object : objects) {
        object->shoot();
    }
    
}
void Component::updateShooting(sf::RenderWindow& window){
    for (auto object : objects) {
        object->updateShooting(window);
    }
    
}