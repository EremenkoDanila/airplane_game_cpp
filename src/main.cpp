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
        std::string path_airplane_user = "../pic/friend_fighter.png";
        std::string path_airplane_hostile = "../pic/hostile_fighter.png";
        
        std::vector<char> mass_for_move(80, 's');
        mass_for_move.insert(mass_for_move.end(), 130, 'w');
        mass_for_move.insert(mass_for_move.end(), 50, 's');
        int mov_num = 0;


        Creator* creator = new ConcreteCreator();
        AirVehicle* user = new Component();
        AirVehicle* enemies = new Component();
        GameMap* map = new GameMap(path_map,WINDOW_WIGHT,WINDOW_HEIGHT);
        sf::Event event;

        AirVehicle* airplane  = creator->CreatAirplaneFriend('f', 100, 4, path_airplane_user, sf::Vector2f(960, 500), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane1 = creator->CreatAirplaneFriend('e', 100, 4, path_airplane_hostile, sf::Vector2f(1600, 400), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane2 = creator->CreatAirplaneFriend('e', 100, 4, path_airplane_hostile, sf::Vector2f(1500, 500), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane3 = creator->CreatAirplaneFriend('e', 100, 4, path_airplane_hostile, sf::Vector2f(1400, 600), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane4 = creator->CreatAirplaneFriend('e', 100, 4, path_airplane_hostile, sf::Vector2f(1500, 700), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane5 = creator->CreatAirplaneFriend('e', 100, 4, path_airplane_hostile, sf::Vector2f(1600, 800), WINDOW_WIGHT, WINDOW_HEIGHT);

        user->AddObject(airplane);
        enemies->AddObject(airplane1);
        enemies->AddObject(airplane2);
        enemies->AddObject(airplane3);
        enemies->AddObject(airplane4);
        enemies->AddObject(airplane5);

        std::cout << "All objects created" << std::endl;
        std::cout << "Make some actions" << std::endl;
        
        while (window.isOpen()){
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
                    user->Shoot(); 
                    enemies->Shoot(); 
                }
            }

            map->Display(window);
            user->Display(window);
            user->MoveSprite();
            user->UpdateShooting(window);
            enemies->Display(window);

            if (mov_num < static_cast<int>(mass_for_move.size())){
                enemies->MoveSprite(mass_for_move, mov_num);
                mov_num++;
            } else {
                mov_num = 0;
            }

            enemies->UpdateShooting(window);
            window.display();
        }

        std::cout << "Stage of objects removal" << std::endl;
        creator->RemoveAirplane(airplane);
        delete creator;
        delete enemies;
        delete user;
        delete map;
        std::cout << "Close this program" << std::endl;
        return 0;
    }
}