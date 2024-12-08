#include "airplane_header.h"

void moveSprite(sf::Sprite& sprite) {
    // Получаем состояние клавиш
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        // Перемещаем спрайт вверх
        sprite.rotate(-45.f);
        sprite.move(0.f, -5.f);  // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        // Перемещаем спрайт вниз
         sprite.rotate(45.f);
        sprite.move(0.f, 5.f);   // Изменение координаты Y
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        // Перемещаем спрайт влево
         sprite.rotate(-90.f);
        sprite.move(-5.f, 0.f);  // Изменение координаты X
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        // Перемещаем спрайт вправо
         sprite.rotate(90.f);
        sprite.move(5.f, 0.f);   // Изменение координаты X
    }
}


