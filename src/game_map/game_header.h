#ifndef game_map
#define game_map

#include <SFML/Graphics.hpp>
#include <string>

class GameMap {
public:
    GameMap(const std::string& backgroundFilePath);
    void displayMap(sf::RenderWindow& window);

private:
    sf::View border;

    sf::Texture backgroundTexture; // Текстура фона
    sf::Sprite backgroundSprite;   // Спрайт фона
};

#endif 
