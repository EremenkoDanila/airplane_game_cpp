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

  // Стрелять в указанном направлении
  virtual void Shoot(std::vector<sf::Sprite>& projectiles,
                     const sf::Texture& texture,
                     const sf::Vector2f& start_position,
                     float direction) = 0;
};

// Одиночный выстрел
class SingleShotStrategy : public ShootingStrategy {
 public:
  void Shoot(std::vector<sf::Sprite>& projectiles,
             const sf::Texture& texture,
             const sf::Vector2f& start_position,
             float direction) override;  
};

// Залповая стрельба (3 снаряда)
class MultiShotStrategy : public ShootingStrategy {
 public:
  void Shoot(std::vector<sf::Sprite>& projectiles,
             const sf::Texture& texture,
             const sf::Vector2f& start_position,
             float direction) override;
};

// Основной класс для стрельбы
class Shooting {
 private:
  sf::Texture projectile_texture_;  // Текстура для снарядов
  std::vector<sf::Sprite> projectiles_;  // Список активных снарядов
  float projectile_speed_;  // Скорость движения снарядов
  float direction_;  // Направление стрельбы
  std::unique_ptr<ShootingStrategy> strategy_;  // Текущая стратегия стрельбы

 public:
  // Конструктор
  Shooting(const std::string& texture_path, float speed);  // Новый перегруженный конструктор
  Shooting(const std::string& texture_path, float speed, float direction);

  // Установить стратегию стрельбы
  void SetStrategy(std::unique_ptr<ShootingStrategy> new_strategy);

  // Установить направление стрельбы
  void SetDirection(float new_direction);

  // Выстрелить с использованием текущей стратегии
  void Shoot(const sf::Vector2f& start_position);

  // Обновить и отобразить снаряды
  void Update(sf::RenderWindow& window);

  // Обработать ввод пользователя
  void HandleInput(sf::Keyboard::Key key);

  float GetDirection() const { return direction_;}
  std::vector<sf::Sprite>& getProjectiles() {return projectiles_;}

};

#endif