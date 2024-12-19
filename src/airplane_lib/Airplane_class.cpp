#include "Airplane_nsp.h"
#include "Airplane_class.h"

sf::Vector2f Airplane::GetPosition(){
    return sprite_.getPosition();
}  

Airplane::Airplane() : shooting("../pic/bullet.png", 10.f){
    std::cout << "the airplane_friend was created without some parametrs" << std::endl;
}

Airplane::~Airplane(){
    std::cout << "the airplane was deleted" << std::endl;
}

Airplane::Airplane(char flg, int hp, int speed, 
                   const std::string& texturePath,
                   const sf::Vector2f& position, 
                   unsigned int KWINDOW_WIDTH, 
                   unsigned int KWINDOW_HEIGHT) : shooting("../pic/bullet.png", 10.f){
    this->hp_ = hp;
    this->speed_ = speed;
    this->window_width_= KWINDOW_WIDTH;
    this->window_height_= KWINDOW_HEIGHT;
    SetTexture(texturePath);
    SetPosition(position);
    if (flg == 'f') {
        sprite_.rotate(90);
        sprite_.scale(0.5f, 0.5f);
        std::cout << "the airplane_friend was created" << std::endl;
    }
    if(flg == 'e') {
        sprite_.rotate(-90);
        sprite_.scale(0.2f, 0.2f);
        std::cout << "the airplane_enemy was created" << std::endl;
    }
}


void Airplane::SetTexture(const std::string& ktexturePath){
    if (!texture_.loadFromFile(ktexturePath)) {
        std::cerr << "Failed to load airplane texture from: " << ktexturePath << std::endl;
        throw std::runtime_error("Texture loading failed");
    }
    sprite_.setTexture(texture_);
}

void Airplane::SetPosition(const sf::Vector2f& kposition){
    sprite_.setPosition(kposition);
}



void Airplane:: Display(sf::RenderWindow& window){;
    window.draw(sprite_);
}


const sf::Texture& Airplane::GetTexture(){
    return texture_;
}


void Airplane::MoveSprite(std::vector<char> mass_for_move, int mov_num){
    int speed_tmp = this->speed_;
    if (static_cast<int>(mass_for_move.size()) > mov_num)
    {
        char tmp = mass_for_move[mov_num];
         switch(tmp) {
            case 'w':
                sprite_.move(0.f, -speed_tmp);  // Изменение координаты Y вверх
                break;
            case 's':
                sprite_.move(0.f, speed_tmp);   // Изменение координаты Y вниз
                break;
            case 'a':
                sprite_.move(-speed_tmp, 0.f);  // Изменение координаты X влево
                break;
            case 'd':
                sprite_.move(speed_tmp, 0.f);   // Изменение координаты X вправо
                break;
            default:
                break;
        }
    }
}

void Airplane::MoveSprite() {
    airplane::MoveSpriteUserControl(sprite_, speed_, texture_.getSize(), window_width_, window_height_);
    bool isSpeedUp = true; 
    bool isSlowDown = true; 

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
        // Перемещаем спрайт вправо
        speed_ = 15;
        isSpeedUp = false; 
    }
    if (speed_ > 5){
        speed_ -=0.01;
    }
}

void Airplane::Shoot(){
    shooting.shoot(GetPosition()); // Стрельба из текущей позиции самолёта
}

void Airplane::UpdateShooting(sf::RenderWindow& window){
    shooting.update(window); // Обновление и отрисовка снарядов
}

void Airplane::SetHp(int hp){
    hp_ = hp;
}

void Airplane::SetSpeed(int speed){
     speed_= speed;
}

void Airplane::AddObject(AirVehicle* object){
}

void Airplane::RemoveObject(AirVehicle* object){
    delete object;
}