#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <thread>

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




int main() {
    while (true)
    {
        //help
    // Создаем окно
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(144);

    // Создаем круг
    sf::CircleShape circle(50); // Радиус круга 50 пикселей
    circle.setFillColor(sf::Color::Green); // Цвет круга
    circle.setPosition(960 - 150, 540 - 100); // Центр экрана

    sf::Texture plane_pic;
    if (!plane_pic.loadFromFile("C:/airplane_game_cpp/pic/plane.png")){
        std::cerr << "Не удалось загрузить файл!" << std::endl;
        return -1;
    }
    sf::Sprite sprite(plane_pic);
    sprite.setPosition(60, 540 - 50);
    sprite.setScale(0.2f, 0.2f);
    sprite.setRotation(-45.f);
    //plane_pic.setPosition(160 - 50, 240 - 50); // Центр экрана

    sf::RectangleShape square(sf::Vector2f(500, 500));
    square.setFillColor(sf::Color::Blue);
    square.setPosition(800, 540-250);


    // Создаем текст
    sf::Font font;
    if (!font.loadFromFile("C:/airplane_game_cpp/font/Sansation-Regular.ttf")) {
        std::cerr << "Не удалось загрузить шрифт!" << std::endl;
        return -1;
    }


    sf::Text font_lose("You are a very bad persone!!!!", font, 100); // Текст "Это квадрат" с размером шрифта 30
    font_lose.setFillColor(sf::Color::White); // Цвет текста
    font_lose.setPosition(300, 500); // Позиция текста под кругом


    sf::Text font_win("You are a very good persone!!!!", font, 100); // Текст "Это квадрат" с размером шрифта 30
    font_win.setFillColor(sf::Color::Black); // Цвет текста
    font_win.setPosition(300, 500); // Позиция текста под кругом

    sf::Text text("What will be happened next?", font, 50); // Текст "Это квадрат" с размером шрифта 30
    text.setFillColor(sf::Color::Black); // Цвет текста
    text.setPosition(700, 540+250); // Позиция текста под кругом
          int flg_x =0 ;
            int flg_y =0 ;



    while (window.isOpen()) {
        for (auto event = sf::Event(); window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White); // Очищаем экран
        window.draw(square); // Рисуем круг
        window.draw(text); // Рисуем текст
        window.draw(sprite);
        moveSprite(sprite);

        sf::Vector2f position = sprite.getPosition();
        if((position.x > 450 && position.x < 1200 ) && (position.y > 200 && position.y < 790))
        {
            int flg_x =1 ;
            int flg_y =1 ;
            for (int i = 0; i < 2; ++i) {
                window.clear(sf::Color::Red);  
                window.draw(font_lose);
                window.display();
                auto event = sf::Event(); window.pollEvent(event);
                std::this_thread::sleep_for(std::chrono::seconds(1)); 
            }
            //window.close();
            break;
        }

        if (position.x > 1800 && flg_x!=1 && flg_y!=1)
         {
            for (int i = 0; i < 2; ++i) {
                window.clear(sf::Color::Green);  
                window.draw(font_win);
                window.display();
                auto event = sf::Event(); window.pollEvent(event);
                std::this_thread::sleep_for(std::chrono::seconds(1)); 
            }
            //window.close();
            break;
        }
        window.display(); // Отображаем содержимое окна

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                // Завершаем программу, если нажата клавиша ESC
                return 0;
            }
    }
    }
    return 0;
}