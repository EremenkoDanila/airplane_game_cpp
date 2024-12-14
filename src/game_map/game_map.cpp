#include "game_header.h"
#include <iostream>
//const std::string& mapFilePath,

GameMap::GameMap( const std::string& backgroundFilePath, unsigned int window_width, unsigned intwindow_height) {
    // Загружаем текстуру фона
    if (!backgroundTexture.loadFromFile(backgroundFilePath)) {
        std::cerr << "Error: Could not load background image." << std::endl;
    } else {
        backgroundSprite.setTexture(backgroundTexture);
        // Устанавливаем размер фона по размеру окна
        backgroundSprite.setScale(
            static_cast<float>(window_width) / backgroundTexture.getSize().x,
            static_cast<float>(intwindow_height) / backgroundTexture.getSize().y
        );
    }
    border.setSize(sf::Vector2f(window_width, intwindow_height)); // Устанавливаем размер области
    border.setCenter(window_width / 2, intwindow_height / 2);     // Устанавливаем центр области
    std::cout << "Map loaded." << std::endl;
}

void GameMap::displayMap(sf::RenderWindow& window) {
    window.clear(sf::Color::Green);
    window.setView(border);
    window.draw(backgroundSprite);
}

GameMap::~GameMap(){
    std::cout<<"Map destroyed." << std::endl;
}