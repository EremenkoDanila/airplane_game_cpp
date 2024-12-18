#ifndef shooting_lib
#define shooting_lib
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
   


// Интерфейс стратегии стрельбы
class ShootingStrategy {
public:
    virtual ~ShootingStrategy() = default;
    virtual void shoot(std::vector<sf::Sprite>& projectiles, const sf::Texture& texture, const sf::Vector2f& startPosition) = 0;
};

// Одиночный выстрел
class SingleShotStrategy : public ShootingStrategy {
public:
    void shoot(std::vector<sf::Sprite>& projectiles, const sf::Texture& texture, const sf::Vector2f& startPosition) override;
};

// Залповая стрельба (3 снаряда)
class MultiShotStrategy : public ShootingStrategy {
public:
    void shoot(std::vector<sf::Sprite>& projectiles, const sf::Texture& texture, const sf::Vector2f& startPosition) override;
};

// Основной класс для стрельбы
class Shooting {
private:
    sf::Texture projectileTexture;          // Текстура для снарядов
    std::vector<sf::Sprite> projectiles;    // Список активных снарядов
    float projectileSpeed;                  // Скорость движения снарядов
    std::unique_ptr<ShootingStrategy> strategy; // Текущая стратегия стрельбы

public:
    Shooting(const std::string& texturePath, float speed);

    // Установить стратегию стрельбы
    void setStrategy(std::unique_ptr<ShootingStrategy> newStrategy);

    // Выстрелить с использованием текущей стратегии
    void shoot(const sf::Vector2f& startPosition);

    // Обновить и отобразить снаряды
    void update(sf::RenderWindow& window);
};

#endif