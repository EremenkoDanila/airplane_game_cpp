#include "shooting_header.h"
#include <iostream>

// Реализация одиночного выстрела
void SingleShotStrategy::shoot(std::vector<sf::Sprite>& projectiles, const sf::Texture& texture, const sf::Vector2f& startPosition) {
    sf::Sprite projectile;
    projectile.setTexture(texture);
    projectile.setPosition(startPosition);
    projectile.scale(0.1f, 0.1f); // Масштаб снаряда
    projectiles.push_back(projectile);
}

// Реализация залповой стрельбы
void MultiShotStrategy::shoot(std::vector<sf::Sprite>& projectiles, const sf::Texture& texture, const sf::Vector2f& startPosition) {
    for (int i = -1; i <= 1; ++i) {
        sf::Sprite projectile;
        projectile.setTexture(texture);
        projectile.setPosition(startPosition.x, startPosition.y + i * 20); // Смещение снарядов по Y
        projectile.scale(0.1f, 0.1f);
        projectiles.push_back(projectile);
    }
}

// Конструктор класса Shooting
Shooting::Shooting(const std::string& texturePath, float speed)
    : projectileSpeed(speed), strategy(std::make_unique<SingleShotStrategy>()) {
    if (!projectileTexture.loadFromFile(texturePath)) {
        std::cerr << "Failed to load projectile texture from: " << texturePath << std::endl;
        throw std::runtime_error("Projectile texture loading failed");
    }
}

// Установка новой стратегии
void Shooting::setStrategy(std::unique_ptr<ShootingStrategy> newStrategy) {
    strategy = std::move(newStrategy);
}

// Выстрел с использованием текущей стратегии
void Shooting::shoot(const sf::Vector2f& startPosition) {
    if (strategy) {
        strategy->shoot(projectiles, projectileTexture, startPosition);
    }
}

// Обновление и отображение снарядов
void Shooting::update(sf::RenderWindow& window) {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->move(projectileSpeed, 0.f); // Движение вправо
        if (it->getPosition().x > window.getSize().x) {
            it = projectiles.erase(it); // Удаление снарядов за пределы экрана
        } else {
            window.draw(*it); // Рисуем снаряд
            ++it;
        }
    }
}