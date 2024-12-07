#include <SFML/Graphics.hpp>
#include "game_map/game_header.h"
#include <iostream>
#include <filesystem>
#include <thread>
#include <string>

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


    std::string path_map = "C:/airplane_game_cpp/pic/map.png";
    GameMap* map = new GameMap(path_map);


    while (window.isOpen()) 
    {
        for (auto event = sf::Event(); window.pollEvent(event);) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }
        map->displayMap(window);
    }
    return 0;
    }
}