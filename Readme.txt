Организация классов:
Класс map - создание карты 

Шаблон "Компановщик" - Организация основных действий 
Класс air_vehicles - основной класс (виртуальный класс) 
            |\ Класс Component переопределяет air_vehicles, хранит группу элементов airplane_friend и позволяет обращяться ко всем элементам сразу 
            |\ Класс airplane_friend переопределяет air_vehicles и является конкретной реализацией объекта                                 
               

Шаблон "Фабрика" - создание конкретных объектов 
Класс Creator -  виртуальным классов 
            |\ Класс ConcreteCreator переопределяет Creator и позволяет создавать airplane_friend 


Шаблон "Стратегия" - управление логикой стрельбы
Класс ShootingStrategy — основной класс (виртуальный класс), определяет интерфейс для стратегий стрельбы:
            |\Класс SingleShotStrategy переопределяет ShootingStrategy и реализует стрельбу одиночными снарядами.
            |\Класс MultiShotStrategy переопределяет ShootingStrategy и реализует залповую стрельбу (несколько снарядов, вылетающих в ряд).


Шаюлон "Стратегия"

Заполнить 

--------------------------------------

Нужно исправить: 

4) Airplane::Airplane() : shooting("../pic/bullet.png", 10.f) сделать ссылку на пулю из main


Можно спросить про:

Как скрывать методы функций 

Когда писать const и privet 

Что еще посоветывать сделать 

