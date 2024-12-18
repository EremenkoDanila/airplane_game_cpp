#include "Component.h"
#include "air_vehicles.h"
#include "Creator.h"

Component::Component(){}
Component::~Component(){
    int i = 1;
    for (auto object : objects_){
        delete object;
         std::cout << i << ") delete object (enemy)" << std::endl;
         i++;
    }
}

void Component::AddObject(AirVehicle* object){
    objects_.push_back(object);
    object->SetParent(this);
}

void Component::RemoveObject(AirVehicle* object){
    int i = 1;
    auto it = std::find(objects_.begin(), objects_.end(), object);
    if (it != objects_.end()) {
        delete *it;
        objects_.erase(it);
        std::cout << i << ") delete object (enemy)" << std::endl;
        i++;
    }
}


void Component::Set_hp(int hp){
        for (auto object : objects_){
        object->Set_hp(hp);
    }
}
void Component::Set_speed(int speed){
    for (auto object : objects_){
        object->Set_speed(speed);
    }
}

void Component::SetTexture(const std::string& texturePath){
    for (auto object : objects_){
        object->SetTexture(texturePath);
    }
}


void Component::SetPosition(const sf::Vector2f& position){
    for (auto object : objects_){
        object->SetPosition(position);
    }
    
}

const sf::Texture& Component::GetTexture(){
    if (!objects_.empty()){
        return objects_.front()->GetTexture(); // Возвращаем текстуру первого объекта
    }
    static const sf::Texture emptyTexture; // Для случая, когда коллекция пустая
    return emptyTexture;
}


sf::Vector2f Component::GetPosition(){
    if (!objects_.empty()){
        return objects_.front()->GetPosition(); // Возвращаем текстуру первого объекта
    }
    static const sf::Vector2f emptyTexture; // Для случая, когда коллекция пустая
    return emptyTexture;
}

void Component::MoveSprite(){
    for (auto object : objects_){
        object->MoveSprite();
    }
}


void Component::MoveSprite(std::vector<char> mass_for_move, int mov_num )
{
    for (auto object : objects_){
        object->MoveSprite(mass_for_move, mov_num);
    }
    
}

void Component::Display(sf::RenderWindow& window){
    for (auto object : objects_){
        object->Display(window);
    }
}
void Component::Shoot(){
    for (auto object : objects_){
        object->Shoot();
    }
    
}

void Component::UpdateShooting(sf::RenderWindow& window){
    for (auto object : objects_){
        object->UpdateShooting(window);
    }
    
}