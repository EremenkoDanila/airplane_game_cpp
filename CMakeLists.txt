#cmake_minimum_required(VERSION 3.10)

# Название проекта
#project(AirplaneGame)

# Установите стандарт C++
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем путь к заголовочным файлам SFML
#include_directories("C:/airplane_game_cpp/SFML-2.6.2/include")

# Укажите путь к SFML
#set(SFML_DIR "C:\\airplane_game_cpp\\SFML-2.6.2\\lib\\cmake")

#set(CMAKE_PREFIX_PATH "C:/airplane_game_cpp")

# Подключение SFML
#find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Укажите исполняемый файл
#add_executable(${PROJECT_NAME} src/main.cpp)

# Подключение библиотек SFML
#target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
# Линкуем с библиотеками SFML
#target_link_libraries(${PROJECT_NAME} PRIVATE libsfml-graphics.a libsfml-window.a libsfml-system.a)
#target_link_libraries(${PROJECT_NAME} PRIVATE
#    "C:/airplane_game_cpp/libsfml-graphics.a.lib"
#    "C:/airplane_game_cpp/libsfml-window.a.lib"
#    "C:/airplane_game_cpp/libsfml-system.a.lib"
#)

cmake_minimum_required(VERSION 3.28)
project(AirplaneGame)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/font/Sansation-Regular.ttf
               ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

