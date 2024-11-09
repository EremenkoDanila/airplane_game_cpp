#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(){


//std::string filename = "test.txt";
std::string filename = "test.txt";

std::ifstream file(filename);

  if (!file.is_open()) {
        std::cerr << "Erorr to openb " << filename << std::endl;
        return 1;
    }

    std::string word;
    file >> word;
    
    file.close();
    
    std::cout << "Ecsample  " << word << std::endl;
}