#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <thread>

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




int main() {
    while (true)
    {
        //help
    // Создаем окно
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen()) {
        for (auto event = sf::Event(); window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}