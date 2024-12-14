#include <SFML/Graphics.hpp>
#include "game_map/game_header.h"
#include "airplane_lib/airplane_header.h"
#include "shooting_lib/shooting_header.h"

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

    // Подключение библиотеки для стрельбы
    std::string projectile_texture_path = "../../pic/projectile.png";
    ProjectileFactory projectileFactory(projectile_texture_path);
    Shooting shooting(projectileFactory, 10.f); // Скорость снарядов: 10

    while (window.isOpen()) 
    {
        for(auto event = sf::Event(); window.pollEvent(event);){if (event.type == sf::Event::Closed) {window.close();}} // Проверяем закрытие
         // Переключение стратегии (Shift для залпа, Space для одиночного выстрела)
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                shooting.setStrategy(std::make_unique<SingleShotStrategy>());
                shooting.shoot(airplane->getPosition());
            } else if (event.key.code == sf::Keyboard::LShift) {
                shooting.setStrategy(std::make_unique<MultiShotStrategy>());
                shooting.shoot(airplane->getPosition());
            }
        }
        


        map->displayMap(window);
        airplane->display(window);
        airplane->moveSprite();
        shooting.update(window);
        window.display();
    }
    creator->remove_airplane_friend(airplane);
    return 0;
    }
}