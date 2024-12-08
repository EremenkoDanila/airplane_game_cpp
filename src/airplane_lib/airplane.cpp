#include "airplane_header.h"

void moveSprite(sf::Sprite& sprite) {
    // Получаем состояние клавиш
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        // Перемещаем спрайт вверх
        sprite.rotate(-45.f);
        sprite.move(0.f, -5.f);  // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        // Перемещаем спрайт вниз
         sprite.rotate(45.f);
        sprite.move(0.f, 5.f);   // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        // Перемещаем спрайт влево
         sprite.rotate(-90.f);
        sprite.move(-5.f, 0.f);  // Изменение координаты X
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        // Перемещаем спрайт вправо
         sprite.rotate(90.f);
        sprite.move(5.f, 0.f);   // Изменение координаты X
    }
}

class Airplane {
private:
    sf::Sprite sprite;    // Спрайт самолета
    sf::Texture texture;  // Текстура самолета

public:
    // Конструктор по умолчанию
    Airplane() = default;

    // Конструктор с параметрами
    Airplane(const std::string& texturePath, const sf::Vector2f& position) {
        if (!texture.loadFromFile(texturePath)) {
            std::cerr << "Failed to load airplane texture from: " << texturePath << std::endl;
            throw std::runtime_error("Texture loading failed");
        }
        sprite.setTexture(texture);
        sprite.setPosition(position);
    }

    // Установка текстуры и позиции
    void setTexture(const std::string& texturePath) {
        if (!texture.loadFromFile(texturePath)) {
            std::cerr << "Failed to load airplane texture from: " << texturePath << std::endl;
            throw std::runtime_error("Texture loading failed");
        }
        sprite.setTexture(texture);
    }

    void setPosition(const sf::Vector2f& position) {
        sprite.setPosition(position);
    }

    // Метод для получения спрайта самолета (для рисования)
    sf::Sprite& getSprite() {
        return sprite;
    }

    // Метод для обновления самолета (например, движение)
    void update(float deltaX, float deltaY) {
        sprite.move(deltaX, deltaY);
    }
};


