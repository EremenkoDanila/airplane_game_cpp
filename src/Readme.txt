Организация классов:
Класс map - создание карты 

Шаблон "Компановщик" - Организация основных действий 
Класс air_vehicles - основной класс (виртуальный класс) 
            |\ Класс Component переопределяет air_vehicles, хранит группу элементов airplane_friend и позволяет обращяться ко всем элементам сразу 
            |\ Класс airplane_friend переопределяет air_vehicles и является конкретной реализацией объекта                                 
               

Шаблон "Фабрика" - создание конкретных объектов 
Класс Creator -  виртуальным классов 
            |\ Класс ConcreteCreator переопределяет Creator и позволяет создавать airplane_friend 



Шаюлон "Стратегия"

Заполнить 

--------------------------------------

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


3) проверить на пеп8 и посмотреть нужно где то наисать const или privit, проверить код 