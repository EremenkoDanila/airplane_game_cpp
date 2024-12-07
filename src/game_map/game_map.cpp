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
            static_cast<float>(800) / backgroundTexture.getSize().x,
            static_cast<float>(600) / backgroundTexture.getSize().y
        );
    }
/*
    // Загружаем текстуру карты
    if (!texture.loadFromFile(mapFilePath)) {
        std::cerr << "Error: Could not load map image." << std::endl;
    } else {
        sprite.setTexture(texture);
    }
*/
}

void GameMap::displayMap(sf::RenderWindow& window) {
    // Отображаем фон
    window.draw(backgroundSprite);
    // Отображаем карту поверх фона
   // window.draw(sprite);
}