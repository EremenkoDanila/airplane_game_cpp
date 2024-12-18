#include <SFML/Graphics.hpp>
#include "game_map/game_header.h"
#include "airplane_lib/airplane_header.h"
#include "airplane_lib/shooting_lib/shooting_header.h"
#include "airplane_lib/airplane_friend.h"
#include "airplane_lib/air_vehicles.h"
#include "airplane_lib/Creator.h"
#include "airplane_lib/ConcreteCreator.h"
#include "airplane_lib/Component.h"
#include <iostream>
#include <filesystem>
#include <thread>
#include <string>
#include <chrono>

const unsigned int WINDOW_WIGHT = 1920;
const unsigned int WINDOW_HEIGHT = 1080;


int main() {
    while (true){
        auto window = sf::RenderWindow({WINDOW_WIGHT, WINDOW_HEIGHT}, "CMake SFML Project");
        window.setFramerateLimit(60);

        std::string path_map = "../pic/map.png";
        std::string path_airplane = "../pic/friend_fighter.png";
        std::string path_hostile_fighter = "../pic/hostile_fighter.png";
        
        std::vector<char> mass_for_move(80, 's');
        mass_for_move.insert(mass_for_move.end(), 130, 'w');
        mass_for_move.insert(mass_for_move.end(), 50, 's');
        int mov_num = 0;


        Creator* creator = new ConcreteCreator();
        AirVehicle* user = new Component();
        AirVehicle* enemies = new Component();
        GameMap* map = new GameMap(path_map,WINDOW_WIGHT,WINDOW_HEIGHT);
        sf::Event event;

        AirVehicle* airplane  = creator->creat_airplane_friend('f', 100, 4, path_airplane, sf::Vector2f(960, 500), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane1 = creator->creat_airplane_friend('e', 100, 4, path_hostile_fighter, sf::Vector2f(1600, 400), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane2 = creator->creat_airplane_friend('e', 100, 4, path_hostile_fighter, sf::Vector2f(1500, 500), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane3 = creator->creat_airplane_friend('e', 100, 4, path_hostile_fighter, sf::Vector2f(1400, 600), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane4 = creator->creat_airplane_friend('e', 100, 4, path_hostile_fighter, sf::Vector2f(1500, 700), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane5 = creator->creat_airplane_friend('e', 100, 4, path_hostile_fighter, sf::Vector2f(1600, 800), WINDOW_WIGHT, WINDOW_HEIGHT);

        user->addObject(airplane);
        enemies->addObject(airplane1);
        enemies->addObject(airplane2);
        enemies->addObject(airplane3);
        enemies->addObject(airplane4);
        enemies->addObject(airplane5);

        std::cout << "All objects created" << std::endl;
        std::cout << "Make some actions" << std::endl;
        
        while (window.isOpen()){
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
                    user->shoot(); 
                    enemies->shoot(); 
                }
            }

            map->displayMap(window);
            user->display(window);
            user->moveSprite();
            user->updateShooting(window);
            enemies->display(window);

            if (mov_num < static_cast<int>(mass_for_move.size())){
                enemies->moveSprite(mass_for_move, mov_num);
                mov_num++;
            } else {
                mov_num = 0;
            }

            enemies->updateShooting(window);
            window.display();
        }

        std::cout << "Stage of objects removal" << std::endl;
        creator->remove_airplane_friend(airplane);
        delete creator;
        delete enemies;
        delete user;
        delete map;
        std::cout << "Close this program" << std::endl;
        return 0;
    }
}