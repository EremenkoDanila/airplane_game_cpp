
cmake_minimum_required(VERSION 3.28)
project(AirplaneGame)

set(CMAKE_CXX_STANDARD 17)

# Подключаем текст 
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/font/Sansation-Regular.ttf
               ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

# Подключаем картинки                
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pic/plane.png
               ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)




# Путь в exe
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Скачиваем SFML
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Подключаем директорию с библиотекой game_map
add_subdirectory(src/game_map)
add_subdirectory(src/airplane_lib)

# Указываем список исходных файлов проекта
set(PROJECT_SOURCE_LIST
    src/main.cpp
)

# Создаем исполняемый файл проекта
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_LIST})

# Подключаем библиотеки
target_link_libraries(${PROJECT_NAME} PRIVATE game_map airplane_lib sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)


