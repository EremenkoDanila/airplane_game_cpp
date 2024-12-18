#include "Game_header.h"
#include <iostream>

GameMap::GameMap( const std::string& kBackgroundFilePath, const unsigned int WINDOW_WIGHT, const unsigned int WINDOW_HEIGHT) {
    if (!backgroundTexture_.loadFromFile(kBackgroundFilePath)) {
        std::cerr << "Error: Could not load background image." << std::endl;
    } else {
        backgroundSprite_.setTexture(backgroundTexture_);
        backgroundSprite_.setScale(
            static_cast<float>(WINDOW_WIGHT) / backgroundTexture_.getSize().x,
            static_cast<float>(WINDOW_HEIGHT) / backgroundTexture_.getSize().y
        );
    }

    border_.setSize(sf::Vector2f(WINDOW_WIGHT, WINDOW_HEIGHT)); 
    border_.setCenter(WINDOW_WIGHT / 2, WINDOW_HEIGHT / 2);    
    std::cout << "Map loaded." << std::endl;
}

void GameMap::Display(sf::RenderWindow& window) {
    window.clear(sf::Color::Green);
    window.setView(border_);
    window.draw(backgroundSprite_);
}

GameMap::~GameMap(){
    std::cout << "Map destroyed." << std::endl;
}