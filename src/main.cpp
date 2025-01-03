#include <SFML/Graphics.hpp>
#include "game_map/Game_header.h"
#include "airplane_lib/Airplane_nsp.h"
#include "airplane_lib/shooting_lib/shooting_header.h"
#include "airplane_lib/Airplane_class.h"
#include "airplane_lib/Creator.h"
#include "airplane_lib/ConcreteCreator.h"
#include "airplane_lib/Component.h"
#include "airplane_lib/AirVehicle_class.h"
#include <iostream>
#include <filesystem>
#include <thread>
#include <string>
#include <chrono>
#include <random>

const unsigned int WINDOW_WIGHT = 1920;
const unsigned int WINDOW_HEIGHT = 1080;


int main() {
    while (true){
        auto window = sf::RenderWindow({WINDOW_WIGHT, WINDOW_HEIGHT}, "CMake SFML Project");
        window.setFramerateLimit(100);

        const std::string path_map = "../pic/map.png";
        const std::string path_airplane_user = "../pic/friend_fighter.png";
        const std::string path_airplane_hostile = "../pic/hostile_fighter.png";
        
        std::vector<char> mass_for_move(80, 's');
        mass_for_move.insert(mass_for_move.end(), 130, 'w');
        mass_for_move.insert(mass_for_move.end(), 50, 's');
        int mov_num = 0;
        sf::Clock shootClock;
        const float shootInterval = 0.1f;

        Creator* creator = new ConcreteCreator();
        AirVehicle* user = new Component();
        AirVehicle* enemies = new Component();
        GameMap* map = new GameMap(path_map, WINDOW_WIGHT, WINDOW_HEIGHT);
        sf::Event event;

        AirVehicle* airplane  = creator->CreatAirplane('f', 300 , 4, path_airplane_user, sf::Vector2f(960, 500), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane1 = creator->CreatAirplane('e', 1000, 4, path_airplane_hostile, sf::Vector2f(1600, 400), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane2 = creator->CreatAirplane('e', 1000, 4, path_airplane_hostile, sf::Vector2f(1500, 500), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane3 = creator->CreatAirplane('e', 1000, 4, path_airplane_hostile, sf::Vector2f(1400, 600), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane4 = creator->CreatAirplane('e', 1000, 4, path_airplane_hostile, sf::Vector2f(1500, 700), WINDOW_WIGHT, WINDOW_HEIGHT);
        AirVehicle* airplane5 = creator->CreatAirplane('e', 1000, 4, path_airplane_hostile, sf::Vector2f(1600, 800), WINDOW_WIGHT, WINDOW_HEIGHT);

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
                }
                // Смена оружия при нажатии E
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
                user->HandleInput(sf::Keyboard::E);  // Передаём событие смены оружия
                }
            }

            map->Display(window);
            user->Display(window);
            user->MoveSprite();
            user->UpdateShooting(window, enemies);

            enemies->Display(window);

            if (mov_num < static_cast<int>(mass_for_move.size())) {
                enemies->MoveSprite(mass_for_move, mov_num);
                ++mov_num;
            } else {
                mov_num = 0;
            }

            enemies->UpdateShooting(window, user );

            if (user->IsDestroyed()) {
                std::cout << "Player airplane destroyed! Game over!" << std::endl;
                window.close();
            }


            if (shootClock.getElapsedTime().asSeconds() >= shootInterval) {
                enemies->Shoots(); // Выполняем стрельбу
                shootClock.restart(); // Сбрасываем таймер
            }
            

            enemies->RemoveDestroyedObjects();
            window.display();
        }

        std::cout << "Stage of objects removal" << std::endl;
        delete creator;
        delete enemies;
        delete user;
        delete map;
        std::cout << "Close this program" << std::endl;
        return 0;
    }
}