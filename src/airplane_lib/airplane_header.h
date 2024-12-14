#ifndef airplane_lib
#define airplane_lib

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


void moveSprite_all(sf::Sprite&, int,sf::Vector2u,unsigned int window_width,unsigned int window_height);

class air_vehicles{
    public:
    virtual ~air_vehicles() {};
    virtual void set_hp(int hp_) = 0;
    virtual void set_speed(int speed_) = 0;

    virtual void setTexture(const std::string& texturePath) = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;


    virtual const sf::Texture& getTexture()=0;
    //virtual void moveSprite(int)=0;
    virtual void moveSprite()=0;
    virtual void display(sf::RenderWindow& window) = 0;
};

class airplane_friend : public air_vehicles{
    private:

    unsigned int hp;
    unsigned int speed;

    sf::Sprite sprite;    
    sf::Texture texture; 
    
     unsigned int window_width;
     unsigned int window_height;

    public:
    airplane_friend();
    ~airplane_friend() {};
    airplane_friend(
                        int hp_, int speed_, const std::string& texturePath, 
                        const sf::Vector2f& position,  unsigned int window_width,
                         unsigned int window_height
                     );

    void set_hp(int hp_) {hp = hp_;}
    void set_speed(int speed_)  { speed= speed_;} 

    void setTexture(const std::string& texturePath);
    void setPosition(const sf::Vector2f& position);

    const sf::Texture& getTexture();
    //void moveSprite(int);
    void moveSprite();
    void display(sf::RenderWindow& window);

};


class Creator{
    public:
    Creator(){};
    virtual ~Creator(){};
    virtual air_vehicles *creat_airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position, unsigned int window_width, unsigned int window_height)=0;
    virtual void remove_airplane_friend(air_vehicles *airplane)=0;
};

class ConcreteCreator : public Creator{
    public:
    ConcreteCreator();
    ~ConcreteCreator() override;
    air_vehicles *creat_airplane_friend(int hp_, int speed_, const std::string& texturePath, const sf::Vector2f& position, unsigned int window_width, unsigned int window_height) override;
    void remove_airplane_friend(air_vehicles *airplane) override;
};











class CompoundGraphic : public air_vehicles {
    private:
        std::vector<air_vehicles*> airplane_friend;
    public:
        CompoundGraphic();
        ~CompoundGraphic();
        void add(air_vehicles *airplane);
        void remove(air_vehicles *airplane);
        void display(sf::RenderWindow& window);
        
};




class ImageEditor {
    private:
    std::vector<air_vehicles*> objects; 

    public:
    ImageEditor();
    ImageEditor(int number_of_plane);
    ~ImageEditor();
    void addObject(air_vehicles* object);
    void removeObject(air_vehicles* object);
    void moveAllObjects();
    void changeSpeedOfAllObjects(int newSpeed);
    void renderAllObjects(sf::RenderWindow& window);
};





#endif