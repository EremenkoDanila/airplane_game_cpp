#include <SFML/Graphics.hpp>
#include "game_map/game_header.h"
#include <iostream>
#include <filesystem>
#include <thread>
#include <string>


int main() {
    while (true)
    {

    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(144);

    std::string path_map = "../../pic/map.png";
    GameMap* map = new GameMap(path_map);


    while (window.isOpen()) 
    {
        for(auto event = sf::Event(); window.pollEvent(event);){if (event.type == sf::Event::Closed) {window.close();}} // Проверяем закрытие

        map->displayMap(window);
        window.display();
    }
    return 0;
    }
}