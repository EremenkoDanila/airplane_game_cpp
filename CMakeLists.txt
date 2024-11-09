cmake_minimum_required(VERSION 3.5.0)
project(Airplane_game_main VERSION 0.1.0 LANGUAGES C CXX)


#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.txt
 #       ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)


# Копируем файл test.txt в директорию сборки

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.txt
               ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)



add_executable(main main.cpp)	