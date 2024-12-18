cmake_minimum_required(VERSION 3.23)

set(project "airplane_lib")

project(${project})

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "../../build/_deps/sfml-src/include/SFML")

# Определяем источники и заголовочные файлы
set(${project}_SOURCES
        Airplane_nsp.cpp Airplane_class.cpp ConcreteCreator.cpp Component.cpp)
set(${project}_HEADERS
        Airplane_nsp.h AirVehicle_class.h Airplane_class.h Creator.h ConcreteCreator.h  Component.h) 
set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

# Создаём статическую библиотеку airplane_lib
add_library(${project} STATIC ${${project}_SOURCE_LIST})

# Добавляем поддиректорию для стрельбы
add_subdirectory(shooting_lib)

# Указываем зависимости для airplane_lib
target_link_libraries(${project} 
    PRIVATE 
        sfml-graphics 
        sfml-window 
        sfml-system 
        shooting_lib
)

# Указываем, где искать заголовочные файлы
target_include_directories(${project}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
           ${CMAKE_CURRENT_SOURCE_DIR}/shooting_lib
)