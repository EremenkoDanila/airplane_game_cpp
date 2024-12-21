#include "shooting_header.h"
#include <iostream>

// Реализация одиночного выстрела
void SingleShotStrategy::Shoot(std::vector<sf::Sprite>& projectiles,
                               const sf::Texture& texture,
                               const sf::Vector2f& start_position,
                               float direction) {
    sf::Sprite projectile;
    projectile.setTexture(texture);
    projectile.setPosition(start_position);
    projectile.scale(0.1f, 0.1f);  // Масштаб снаряда
    projectiles.push_back(projectile);
}

// Реализация залповой стрельбы
void MultiShotStrategy::Shoot(std::vector<sf::Sprite>& projectiles, const sf::Texture& texture, const sf::Vector2f& start_position, float direction) {
    for (int i = -1; i <= 1; ++i) {
        sf::Sprite projectile;
        projectile.setTexture(texture);
        projectile.setPosition(start_position.x, start_position.y + i * 20);  // Смещение снарядов по Y
        projectile.scale(0.1f, 0.1f);
        projectiles.push_back(projectile);
    }
}

Shooting::Shooting(const std::string& texture_path, float speed)
    : Shooting(texture_path, speed, 1.f) {}  // Вызываем основной конструктор с direction по умолчанию

// Конструктор класса Shooting
Shooting::Shooting(const std::string& texture_path, float speed, float direction)
    : projectile_speed_(speed), direction_(direction), strategy_(std::make_unique<SingleShotStrategy>()) {
    if (!projectile_texture_.loadFromFile(texture_path)) {
        std::cerr << "Failed to load projectile texture from: " << texture_path << std::endl;
        throw std::runtime_error("Projectile texture loading failed");
    }
}

// Установка новой стратегии
void Shooting::SetStrategy(std::unique_ptr<ShootingStrategy> new_strategy) {
    strategy_ = std::move(new_strategy);
}

// Установка направления стрельбы
void Shooting::SetDirection(float new_direction) {
    direction_ = new_direction;
}

void Shooting::Shoot(const sf::Vector2f& start_position) {
    if (strategy_) {
        strategy_->Shoot(projectiles_, projectile_texture_, start_position, direction_);
    }
}

void Shooting::Update(sf::RenderWindow& window) {
    for (auto it = projectiles_.begin(); it != projectiles_.end();) {
        it->move(projectile_speed_ * direction_, 0.f);  // Движение в заданном направлении
        if ((direction_ > 0 && it->getPosition().x > window.getSize().x) || 
            (direction_ < 0 && it->getPosition().x < 0)) {
            it = projectiles_.erase(it);  // Удаление снарядов за пределы экрана
        } else {
            window.draw(*it);  // Рисуем снаряд
            ++it;
        }
    }
}

// Обработка смены оружия
void Shooting::HandleInput(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Key::E) {
        if (dynamic_cast<SingleShotStrategy*>(strategy_.get())) {
            SetStrategy(std::make_unique<MultiShotStrategy>());
        } else {
            SetStrategy(std::make_unique<SingleShotStrategy>());
        }
    }
}
