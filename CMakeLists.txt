cmake_minimum_required(VERSION 3.7)

# General informations about the project
project(pacman
        VERSION 1.0
        DESCRIPTION "Advanced Programming in C++ Project"
        LANGUAGES CXX)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME})

# Use c++20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

target_sources(${PROJECT_NAME}
               PRIVATE
               src/${PROJECT_NAME}.cpp
               src/SDL_utils/SDL_utils.cpp
               src/SDL_utils/window.cpp
               src/SDL_utils/texture.cpp
               src/SDL_utils/timer.cpp
               src/utils/display_utils.cpp
               src/game/object.cpp
               src/game/pac_man.cpp
               src/game/ghost.cpp
               src/game/pac_gomme.cpp
               src/game/super_pac_gomme.cpp)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${SDL2_INCLUDE_DIRS}
                           include
                           include/SDL_utils
                           include/utils
                           include/game)

target_compile_definitions(${PROJECT_NAME}
                           PRIVATE
                           "SDL_MAIN_HANDLED")

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      ${SDL2_LIBRARIES})