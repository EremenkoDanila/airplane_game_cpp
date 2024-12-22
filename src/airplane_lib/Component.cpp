#include "Component.h"
#include "AirVehicle_class.h"
#include "Creator.h"
#include <random>

Component::Component(){std::cout << "Component was created" << std::endl;}
Component::~Component(){
    int i = 1;
    for (auto object : objects_){
         std::cout << i << ") delete object (enemy)" << std::endl;
         delete object;
         i++;
    }
    std::cout << "Component was deleted" << std::endl;
}

void Component::AddObject(AirVehicle* object){
    objects_.push_back(object);
    object->SetParent(this);
}

void Component::RemoveObject(AirVehicle* object){
    int i = 1;
    auto it = std::find(objects_.begin(), objects_.end(), object);
    if (it != objects_.end()) {
        std::cout << i << ") delete object (enemy)" << std::endl;
        delete *it;
        objects_.erase(it);
        i++;
    }
}


void Component::SetHp(int hp){
        for (auto object : objects_){
        object->SetHp(hp);
    }
}
void Component::SetSpeed(int speed){
    for (auto object : objects_){
        object->SetSpeed(speed);
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

sf::FloatRect Component::GetBounds() const {
    if (!objects_.empty()) {
        return objects_.front()->GetBounds();  // Возвращаем границы первого объекта в списке
    }
    return sf::FloatRect();  // Возвращаем пустой прямоугольник, если объектов нет
}

std::vector<sf::Sprite>& Component::getProjectiles() {
    static std::vector<sf::Sprite> all_projectiles;  // Хранилище для всех снарядов
    all_projectiles.clear();

    for (auto* object : objects_) {
        auto& projectiles = object->getProjectiles();  // Получаем снаряды каждого объекта
        all_projectiles.insert(all_projectiles.end(), projectiles.begin(), projectiles.end());
    }

    return all_projectiles;
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

void Component::HandleInput(sf::Keyboard::Key key) {
    // Передаём обработку ввода всем вложенным объектам
    for (auto* object : objects_) {
        if (object) {
            object->HandleInput(key);  // Вызываем HandleInput для каждого объекта
        }
    }
}

void Component::TakeDamage(int damage) {
    for (auto object : objects_) {
        object->TakeDamage(damage);  // Вызываем TakeDamage для каждого объекта
    }
}

bool Component::IsDestroyed() const {
    for (const auto* object : objects_) {
        if (!object->IsDestroyed()) {
            return false;  // Если хотя бы один объект не уничтожен, возвращаем false
        }
    }
    return true;  // Если все объекты уничтожены, возвращаем true
}

void Component::UpdateShooting(sf::RenderWindow& window) {
    for (auto object : objects_) {
        object->UpdateShooting(window);  // Обновляем снаряды объекта

        // Проверяем столкновения с другими объектами
        for (auto target : objects_) {
            if (object == target) continue;  // Пропускаем проверку с самим собой

            // Получаем пули объекта
            std::vector<sf::Sprite>& projectiles = object->getProjectiles();
            for (auto it = projectiles.begin(); it != projectiles.end();) {
                if (target->GetBounds().intersects(it->getGlobalBounds())) {
                    target->TakeDamage(10);  // Уменьшаем здоровье цели
                    it = projectiles.erase(it);  // Удаляем пулю
                } else {
                    ++it;
                }
            }
        }
    }
}

void Component::RemoveDestroyedObjects() {
        for (auto it = objects_.begin(); it != objects_.end();) {
            if ((*it)->IsDestroyed()) {  // Проверяем, уничтожен ли объект
                delete *it;              // Освобождаем память
                it = objects_.erase(it);  // Удаляем объект из списка
            } else {
                ++it;
            }
        }
}







void Component::UpdateShooting(sf::RenderWindow& window, AirVehicle* user) {
    // Обновляем снаряды всех объектов
    for (auto object : objects_) {
        object->UpdateShooting(window);  // Обновляем снаряды объекта

        // Проверяем столкновения с другими объектами
        for (auto target : objects_) {
            if (object == target) continue;  // Пропускаем проверку с самим собой

            // Получаем пули объекта
            std::vector<sf::Sprite>& projectiles = object->getProjectiles();
            for (auto it = projectiles.begin(); it != projectiles.end();) {
                // Проверяем, попала ли пуля в цель
                if (target->GetBounds().intersects(it->getGlobalBounds())) {
                    target->TakeDamage(10);  // Уменьшаем здоровье цели
                    it = projectiles.erase(it);  // Удаляем пулю
                } else {
                    ++it;
                }
            }
        }
    }

    // Проверяем снаряды пользователя
    std::vector<sf::Sprite>& userProjectiles = user->getProjectiles();
    for (auto it = userProjectiles.begin(); it != userProjectiles.end();) {
        for (auto enemy : objects_) {
            if (enemy == user) continue;  // Пропускаем проверку с самим собой

            // Проверяем столкновения с врагами
            if (enemy->GetBounds().intersects(it->getGlobalBounds())) {
                enemy->TakeDamage(10);  // Уменьшаем здоровье врага
                it = userProjectiles.erase(it);  // Удаляем пулю
                break;  // Выходим из цикла, чтобы не проверять другие враги
            }
        }
        if (it != userProjectiles.end()) ++it;  // Увеличиваем итератор только если не удалили элемент
    }
}




 void Component::Shoots(){
    if(!objects_.empty())
    {
        srand(time(NULL));
        auto object_num = rand() % objects_.size();
        objects_[object_num]->Shoot();
    }  
}
