#include "Airplane_class.h"
#include "AirVehicle_class.h"
#include "ConcreteCreator.h"


AirVehicle* ConcreteCreator::CreatAirplane(char flg, int hp, int speed, const std::string& texturePath,
                                           const sf::Vector2f& position, const unsigned int KWINDOW_WIDTH,
                                           const unsigned int KWINDOW_HEIGHT){
    std::cout << "the ConcreteCreator is trying to  created a airplane" << std::endl;
     return new Airplane(flg, hp, speed, texturePath, position, KWINDOW_WIDTH, KWINDOW_HEIGHT);
}

void ConcreteCreator::RemoveAirplane(AirVehicle* airplane){
    delete airplane;
    std::cout << "the airplane was deleted" << std::endl;
}

ConcreteCreator::ConcreteCreator(){
    std::cout << "the ConcreteCreator was created" << std::endl;
}

ConcreteCreator::~ConcreteCreator(){
    std::cout << "the ConcreteCreator was deleted" << std::endl;
}
