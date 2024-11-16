#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>

int main() {
    // Создаем окно
    auto window = sf::RenderWindow({1920u, 1080u}, "CMake SFML Project");
    window.setFramerateLimit(144);

    // Создаем круг
    sf::CircleShape circle(50); // Радиус круга 50 пикселей
    circle.setFillColor(sf::Color::Green); // Цвет круга
    circle.setPosition(960 - 50, 540 - 50); // Центр экрана

    sf::Texture plane_pic;
    if (!plane_pic.loadFromFile("C:/airplane_game_cpp/pic/plane.png")){
        std::cerr << "Не удалось загрузить файл!" << std::endl;
        return -1;
    }
    sf::Sprite sprite(plane_pic);
    sprite.setPosition(160 - 50, 240 - 50);
    //plane_pic.setPosition(160 - 50, 240 - 50); // Центр экрана

    // Создаем текст
    sf::Font font;
    if (!font.loadFromFile("C:/airplane_game_cpp/font/Sansation-Regular.ttf")) {
        std::cerr << "Не удалось загрузить шрифт!" << std::endl;
        return -1;
    }

    sf::Text text("This is square", font, 30); // Текст "Это квадрат" с размером шрифта 30
    text.setFillColor(sf::Color::Black); // Цвет текста
    text.setPosition(960 - 50, 540 + 60); // Позиция текста под кругом

    while (window.isOpen()) {
        for (auto event = sf::Event(); window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White); // Очищаем экран
        window.draw(circle); // Рисуем круг
        window.draw(text); // Рисуем текст
        window.draw(sprite);
        window.display(); // Отображаем содержимое окна
    }

    return 0;
}