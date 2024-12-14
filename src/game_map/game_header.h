#ifndef game_map
#define game_map

#include <SFML/Graphics.hpp>
#include <string>

class GameMap {
public:
    GameMap(const std::string& backgroundFilePath,unsigned int window_width,unsigned int window_height);
    void displayMap(sf::RenderWindow& window);
    ~GameMap();

private:
    sf::View border;
    sf::Texture backgroundTexture; // Текстура фона
    sf::Sprite backgroundSprite;   // Спрайт фона
};

#endif 
