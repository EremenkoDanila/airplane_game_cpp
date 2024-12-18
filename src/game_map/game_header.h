#ifndef game_map
#define game_map

#include <SFML/Graphics.hpp>
#include <string>

class GameMap {
 public:
    GameMap(const std::string& kBackgroundFilePath, const unsigned int WINDOW_WIGHT, const unsigned int WINDOW_HEIGHT);
    void Display(sf::RenderWindow& window);
    ~GameMap();

 private:
    sf::View border_;
    sf::Texture backgroundTexture_; 
    sf::Sprite backgroundSprite_;  
};

#endif 
