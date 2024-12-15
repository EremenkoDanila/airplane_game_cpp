Нужно исправить: 

1) Реализацию функций : Нужно сделать так чтобы они возвращяли массив объектов 

const sf::Texture& Component::getTexture() {
    if (!objects.empty()) {
        return objects.front()->getTexture(); // Возвращаем текстуру первого объекта
    }
    static const sf::Texture emptyTexture; // Для случая, когда коллекция пустая
    return emptyTexture;
}


sf::Vector2f Component::getPosition(){
    if (!objects.empty()) {
        return objects.front()->getPosition(); // Возвращаем текстуру первого объекта
    }
    static const sf::Vector2f emptyTexture; // Для случая, когда коллекция пустая
    return emptyTexture;
}

2) Разобраться в реализации функций в классе airplane_friend, чтобы он не был виртуальным 
    void addObject(air_vehicles* object){};
    void removeObject(air_vehicles* object){};
