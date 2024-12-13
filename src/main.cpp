#include <SFML/Graphics.hpp>
#include "game_map/game_header.h"
#include "airplane_lib/airplane_header.h"

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

    std::string path_airplane = "../../pic/friend_fighter.png";
    Creator* creator = new ConcreteCreator();
    air_vehicles* airplane = creator->creat_airplane_friend(100, 7, path_airplane, sf::Vector2f(960, 540));
    //const sf::Texture& texture1 = airplane->getTexture();
    //std::cout<<texture1.getSize().x<<' '<<texture1.getSize().y<<std::endl;
    while (window.isOpen()) 
    {
        for(auto event = sf::Event(); window.pollEvent(event);){if (event.type == sf::Event::Closed) {window.close();}} // Проверяем закрытие

        map->displayMap(window);
        airplane->display(window);
        airplane->moveSprite();
        window.display();
    }
    creator->remove_airplane_friend(airplane);
    return 0;
    }
}