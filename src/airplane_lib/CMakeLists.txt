cmake_minimum_required(VERSION 3.23)

set(project "airplane_lib")
project(${project})

set(CMAKE_CXX_STANDARD 17)

# Ищем установленную библиотеку SFML
#set(SFML_DIR ".*SFMLConfig\.cmake$"

set(SFML_DIR "../../build/_deps/sfml-src/include/SFML")

# Определяем источники и заголовочные файлы
set(${project}_SOURCES
        airplane.cpp)

set(${project}_HEADERS
        airplane_header.h)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

# Создаем статическую библиотеку
add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})

# Связываем библиотеку с SFML
target_link_libraries(${project} PRIVATE sfml-graphics sfml-window sfml-system)
