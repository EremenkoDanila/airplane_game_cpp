#ifndef game_map
#define game_map

#include <SFML/Graphics.hpp>
#include <string>

void moveSprite(sf::Sprite& sprite);
class air_vehicles{
    public:
    virtual ~air_vehicles();
    virtual void set_hp() = 0;
    virtual void set_speed() = 0;
    virtual void set_border()= 0;
    virtual void set_background() = 0;
    virtual void set_backgroundTexture()= 0;
    virtual void set_backgroundSprite()= 0;
    virtual void moveSprite(sf::Sprite& sprite) = 0;
};

class airplane_friend : public air_vehicles{
    private:

    unsigned int hp;
    unsigned int speed;
    sf::View border;
    sf::Texture backgroundTexture; // Текстура фона
    sf::Sprite backgroundSprite;   // Спрайт фона

    public:
    ~airplane_friend();
    airplane_friend(int hp_, int speed_, );
    void set_hp(int hp_) {hp = hp_;}
    void set_speed(int speed_)  { speed= speed_;} 
    void set_border() ;
    void set_background() ;
    void set_backgroundTexture() ;
    void set_backgroundSprite() ;
    void moveSprite(sf::Sprite& sprite);

};
#endif