cmake_minimum_required(VERSION 3.23)

# Указываем название проекта
set(project "shooting_lib")
project(${project})

set(SFML_DIR "../../build/_deps/sfml-src/include/SFML")
# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Определяем исходные файлы и заголовки
set(${project}_SOURCES
    shooting.cpp)

set(${project}_HEADERS
    shooting_header.h)

# Создаём статическую библиотеку shooting_lib
add_library(${project} STATIC ${${project}_SOURCES} ${${project}_HEADERS})

# Связываем библиотеку с SFML
target_link_libraries(${project} PRIVATE sfml-graphics sfml-window sfml-system)

# Указываем, где искать заголовочные файлы
target_include_directories(${project}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)