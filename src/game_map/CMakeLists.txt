cmake_minimum_required(VERSION 3.23)

set(project "game_map")

project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "../../build/_deps/sfml-src/include/SFML")

# Определяем источники и заголовочные файлы
set(${project}_SOURCES
        game_map.cpp)

set(${project}_HEADERS
        game_header.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

# Создаем статическую библиотеку
add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})

# Связываем библиотеку с SFML
target_link_libraries(${project} PRIVATE sfml-graphics sfml-window sfml-system)
