#include "airplane_friend.h"
#include "air_vehicles.h"
#include "ConcreteCreator.h"


air_vehicles* ConcreteCreator::creat_airplane_friend(char flg, int hp_, int speed_, const std::string& texturePath,
                                                    const sf::Vector2f& position,unsigned int window_width, unsigned int window_height) 
                                                    {
    std::cout<<"the ConcreteCreator is trying to  created a airplane_friend"<<std::endl;
     return new airplane_friend(flg, hp_, speed_, texturePath, position, window_width,window_height);
}


void ConcreteCreator::remove_airplane_friend(air_vehicles* airplane) {
    delete airplane;
    std::cout<<"the airplane_friend was deleted"<<std::endl;
}

ConcreteCreator::ConcreteCreator(){
    std::cout<<"the ConcreteCreator was created"<<std::endl;
}

ConcreteCreator::~ConcreteCreator(){
    std::cout<<"the ConcreteCreator was deleted"<<std::endl;
}
