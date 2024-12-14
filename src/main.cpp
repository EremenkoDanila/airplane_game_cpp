#include <SFML/Graphics.hpp>
#include "game_map/game_header.h"
#include "airplane_lib/airplane_header.h"

#include <iostream>
#include <filesystem>
#include <thread>
#include <string>

const unsigned int window_width = 1920;
const unsigned int window_height = 1080;

int main() {
    while (true)
    {
    

    auto window = sf::RenderWindow({window_width, window_height}, "CMake SFML Project");
    window.setFramerateLimit(144);

    std::string path_map = "../../pic/map.png";
    GameMap* map = new GameMap(path_map,window_width,window_height);

    std::string path_airplane = "../../pic/friend_fighter.png";
    Creator* creator = new ConcreteCreator();
    air_vehicles* airplane =  creator->creat_airplane_friend(100, 7, path_airplane, sf::Vector2f(960, 540),window_width,window_height);
    air_vehicles* airplane1 = creator->creat_airplane_friend(100, 7, path_airplane, sf::Vector2f(900, 500),window_width,window_height);
    air_vehicles* airplane2 = creator->creat_airplane_friend(100, 7, path_airplane, sf::Vector2f(850, 450),window_width,window_height);
    air_vehicles* airplane3=  creator->creat_airplane_friend(100, 7, path_airplane, sf::Vector2f(800, 400),window_width,window_height);
    air_vehicles* airplane4 = creator->creat_airplane_friend(100, 7, path_airplane, sf::Vector2f(750, 350),window_width,window_height);
    air_vehicles* airplane5 = creator->creat_airplane_friend(100, 7, path_airplane, sf::Vector2f(700, 300),window_width,window_height);

     ImageEditor editor;

     editor.addObject(airplane1);
     editor.addObject(airplane);
     editor.addObject(airplane2);
     editor.addObject(airplane3);
     editor.addObject(airplane4);
     editor.addObject(airplane5);


    //const sf::Texture& texture1 = airplane->getTexture();
    //std::cout<<texture1.getSize().x<<' '<<texture1.getSize().y<<std::endl;
    std::cout<<"All objects created"<<std::endl;
    std::cout<<"Make some actions"<<std::endl;
    while (window.isOpen()) 
    {
        for(auto event = sf::Event(); window.pollEvent(event);){if (event.type == sf::Event::Closed) {window.close();}} // Проверяем закрытие

        map->displayMap(window);
        //airplane->display(window);
        //airplane->moveSprite();
        

        editor.renderAllObjects(window);
        editor.moveAllObjects();


        window.display();
    }
    std:: cout<<"Stage of objects removal"<<std::endl;
    creator->remove_airplane_friend(airplane);
    delete creator;
    delete map;
    std::cout <<"Close this program"<<std::endl;
    return 0;
    }
}