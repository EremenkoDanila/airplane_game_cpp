#include "Game_header.h"
#include <iostream>

GameMap::GameMap( const std::string& kBackgroundFilePath, const unsigned int KWINDOW_WIGHT, const unsigned int KWINDOW_HEIGHT) {
    if (!backgroundTexture_.loadFromFile(kBackgroundFilePath)) {
        std::cerr << "Error: Could not load background image." << std::endl;
    } else {
        backgroundSprite_.setTexture(backgroundTexture_);
        backgroundSprite_.setScale(
            static_cast<float>(KWINDOW_WIGHT) / backgroundTexture_.getSize().x,
            static_cast<float>(KWINDOW_HEIGHT) / backgroundTexture_.getSize().y
        );
    }

    border_.setSize(sf::Vector2f(KWINDOW_WIGHT, KWINDOW_HEIGHT)); 
    border_.setCenter(KWINDOW_WIGHT / 2, KWINDOW_HEIGHT / 2);    
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