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
#include <chrono> // Добавляем библиотеку для работы со временем

const unsigned int window_width = 1920;
const unsigned int window_height = 1080;


int main() {
    while (true)
    {
    

    auto window = sf::RenderWindow({window_width, window_height}, "CMake SFML Project");
    window.setFramerateLimit(60);

    std::string path_map = "../pic/map.png";
    GameMap* map = new GameMap(path_map,window_width,window_height);

    std::string path_airplane = "../pic/friend_fighter.png";
    std::string path_hostile_fighter = "../pic/hostile_fighter.png";
    Creator* creator = new ConcreteCreator();
    air_vehicles* editor = new Component();
    air_vehicles* editor2 = new Component();


    std::vector<char> mass_for_move(80,'s');
    mass_for_move.insert(mass_for_move.end(),130,'w');
    mass_for_move.insert(mass_for_move.end(),50,'s');
    int now= 0;

    air_vehicles* airplane  = creator->creat_airplane_friend('f',100, 4, path_airplane, sf::Vector2f(960, 500),window_width,window_height);


    air_vehicles* airplane1 = creator->creat_airplane_friend('e',100, 4, path_hostile_fighter, sf::Vector2f(1600, 400),window_width,window_height);
    air_vehicles* airplane2 = creator->creat_airplane_friend('e',100, 4, path_hostile_fighter, sf::Vector2f(1500, 500),window_width,window_height);
    air_vehicles* airplane3 = creator->creat_airplane_friend('e',100, 4, path_hostile_fighter, sf::Vector2f(1400, 600),window_width,window_height);
    air_vehicles* airplane4 = creator->creat_airplane_friend('e',100, 4, path_hostile_fighter, sf::Vector2f(1500, 700),window_width,window_height);
    air_vehicles* airplane5 = creator->creat_airplane_friend('e',100, 4, path_hostile_fighter, sf::Vector2f(1600, 800),window_width,window_height);



     editor2->addObject(airplane);

     editor->addObject(airplane1);
     editor->addObject(airplane2);
     editor->addObject(airplane3);
     editor->addObject(airplane4);
     editor->addObject(airplane5);


    sf::Event event;

    //const sf::Texture& texture1 = airplane->getTexture();
    //std::cout<<texture1.getSize().x<<' '<<texture1.getSize().y<<std::endl;
    std::cout<<"All objects created"<<std::endl;
    std::cout<<"Make some actions"<<std::endl;
    while (window.isOpen()) 
    {

        
        while (window.pollEvent(event))
         {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                editor2->shoot(); // Все объекты начинают стрелять при нажатии Space
                editor->shoot(); // Все объекты начинают стрелять при нажатии Space
            }
        }


        map->displayMap(window);
        
        editor2->display(window);
        editor2->moveSprite();
        editor2->updateShooting(window);


        editor->display(window);
        if (now < static_cast<int>(mass_for_move.size())){
            editor->moveSprite(mass_for_move, now);
            now++;
        }
        else
        {
            now = 0;
        }
        editor->updateShooting(window);
        

        window.display();
    }
    std:: cout<<"Stage of objects removal"<<std::endl;
    creator->remove_airplane_friend(airplane);
    delete creator;
    delete editor;
    delete editor2;
    delete map;
    std::cout <<"Close this program"<<std::endl;
    return 0;
    }
}