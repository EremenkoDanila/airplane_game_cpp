#include "game_header.h"
#include <iostream>
//const std::string& mapFilePath,
GameMap::GameMap( const std::string& backgroundFilePath) {
    // Загружаем текстуру фона
    if (!backgroundTexture.loadFromFile(backgroundFilePath)) {
        std::cerr << "Error: Could not load background image." << std::endl;
    } else {
        backgroundSprite.setTexture(backgroundTexture);
        // Устанавливаем размер фона по размеру окна
        backgroundSprite.setScale(
            static_cast<float>(1920u) / backgroundTexture.getSize().x,
            static_cast<float>(1080) / backgroundTexture.getSize().y
        );
    }
}

void GameMap::displayMap(sf::RenderWindow& window) {
    window.clear(sf::Color::Green);
    window.draw(backgroundSprite);
}