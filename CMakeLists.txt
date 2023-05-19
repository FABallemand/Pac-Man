cmake_minimum_required(VERSION 3.12)

## PROJECT ##

project(pacman
        VERSION 1.0
        DESCRIPTION "Advanced Programming in C++ Project"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME})

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Werror -Wextra -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -O3 -g")

## FILES ##

target_sources(${PROJECT_NAME}
               PRIVATE
               # Project
               src/${PROJECT_NAME}.cpp
               # SDL
               src/SDL_utils/SDL_utils.cpp
               # Utils
               src/utils/logger.cpp
               # Application
               src/app/application.cpp
               # Game
               src/game/game.cpp
               src/game/pac_string.cpp
               src/game/path_finder.cpp
               src/game/object/object.cpp
               src/game/object/cell.cpp
               src/game/object/moveable/moveable.cpp
               src/game/object/moveable/pac_man.cpp
               src/game/object/moveable/ghosts/ghost.cpp
               src/game/object/moveable/ghosts/blinky.cpp
               src/game/object/moveable/ghosts/clyde.cpp
               src/game/object/moveable/ghosts/inky.cpp
               src/game/object/moveable/ghosts/pinky.cpp
               src/game/object/eatable/eatable.cpp
               src/game/object/eatable/gomme.cpp
               src/game/object/eatable/super_gomme.cpp
               src/game/object/eatable/fruit.cpp
               )

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${SDL2_INCLUDE_DIRS}
                           include
                           include/SDL_utils
                           include/utils
                           include/app
                           include/game
                           include/game/object
                           include/game/object/moveable
                           include/game/object/moveable/ghosts
                           include/game/object/eatable
                           )

target_compile_definitions(${PROJECT_NAME}
                           PRIVATE
                           "SDL_MAIN_HANDLED")

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      ${SDL2_LIBRARIES})

## DOCUMENTATION ##

option(BUILD_DOC "Build documentation" ON)
file(MAKE_DIRECTORY doc)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ../Doxyfile)

    message("Doxygen build started")

    add_custom_target(doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ../doc
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)