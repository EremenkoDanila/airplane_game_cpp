

#include "Component.h"

#include "air_vehicles.h"
#include "Creator.h"



Component::Component() {}
Component::~Component() {
    int i = 1;
    for (auto object : objects) {
        delete object;
         std::cout <<i<< ") delete object (enemy)" << std::endl;
         i++;
    }
}


void Component::AddObject(AirVehicle* object) {
    objects.push_back(object);
    object->SetParent(this);
}


void Component::RemoveObject(AirVehicle* object) {
    int i = 1;
    auto it = std::find(objects.begin(), objects.end(), object);
    if (it != objects.end()) {
        delete *it;
        objects.erase(it);
        std::cout <<i<< ") delete object (enemy)" << std::endl;
        i++;
    }
}


void Component::Set_hp(int hp_){
        for (auto object : objects) {
        object->Set_hp(hp_);
    }
}
void Component::Set_speed(int speed_){
    for (auto object : objects) {
        object->Set_speed(speed_);
    }
}

void Component::SetTexture(const std::string& texturePath){
    for (auto object : objects) {
        object->SetTexture(texturePath);
    }
}


void Component::SetPosition(const sf::Vector2f& position){
    for (auto object : objects) {
        object->SetPosition(position);
    }
    
}

const sf::Texture& Component::GetTexture() {
    if (!objects.empty()) {
        return objects.front()->GetTexture(); // Возвращаем текстуру первого объекта
    }
    static const sf::Texture emptyTexture; // Для случая, когда коллекция пустая
    return emptyTexture;
}


sf::Vector2f Component::GetPosition(){
    if (!objects.empty()) {
        return objects.front()->GetPosition(); // Возвращаем текстуру первого объекта
    }
    static const sf::Vector2f emptyTexture; // Для случая, когда коллекция пустая
    return emptyTexture;
}

void Component::MoveSprite(){
    for (auto object : objects) {
        object->MoveSprite();
    }
}


void Component::MoveSprite(std::vector<char> mass_for_move, int now )
{
    for (auto object : objects) {
        object->MoveSprite(mass_for_move, now);
    }
    
}

void Component::Display(sf::RenderWindow& window){
    for (auto object : objects) {
        object->Display(window);
    }
}
void Component::Shoot(){
    for (auto object : objects) {
        object->Shoot();
    }
    
}
void Component::UpdateShooting(sf::RenderWindow& window){
    for (auto object : objects) {
        object->UpdateShooting(window);
    }
    
}