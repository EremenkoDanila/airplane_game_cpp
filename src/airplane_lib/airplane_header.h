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
    virtual void set_border();
    virtual void set_background();
    virtual void set_backgroundTexture();
    virtual void set_backgroundSprite();
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
    void set_hp(int hp_) override {hp = hp_;};
    void set_speed(int speed_) : speed(speed_){} ;
    void set_border() override;
    void set_background() override;
    void set_backgroundTexture() override;
    void set_backgroundSprite() override;




};
#endif