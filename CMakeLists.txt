cmake_minimum_required(VERSION 3.7)

## PROJECT ##

project(pacman
        VERSION 1.0
        DESCRIPTION "Advanced Programming in C++ Project"
        LANGUAGES CXX)

add_executable(${PROJECT_NAME})

find_package(SDL2 REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## FILES ##

target_sources(${PROJECT_NAME}
               PRIVATE
               # Project
               src/${PROJECT_NAME}.cpp
               # SDL
               src/SDL_utils/SDL_utils.cpp
               src/SDL_utils/window.cpp
               src/SDL_utils/texture.cpp
               src/SDL_utils/timer.cpp
               # Utils
               # Game
               src/game/game.cpp
               src/game/object.cpp
               src/game/pac_man.cpp
               src/game/ghosts/ghost.cpp
               src/game/ghosts/blinky.cpp
               src/game/ghosts/clyde.cpp
               src/game/ghosts/inky.cpp
               src/game/ghosts/pinky.cpp
               src/game/eatable/gomme.cpp
               src/game/eatable/fruit.cpp)

target_include_directories(${PROJECT_NAME}
                           PRIVATE
                           ${SDL2_INCLUDE_DIRS}
                           include
                           include/SDL_utils
                           include/utils
                           include/game
                           include/game/ghosts
                           include/game/eatable)

target_compile_definitions(${PROJECT_NAME}
                           PRIVATE
                           "SDL_MAIN_HANDLED")

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      ${SDL2_LIBRARIES})

## DOCUMENTATION ##

# option(BUILD_DOC "Build documentation" ON)

# find_package(Doxygen)
# if (DOXYGEN_FOUND)
#     set(DOXYGEN_IN ../Doxyfile)

#     message("Doxygen build started")

#     add_custom_target(doc_doxygen ALL
#         COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
#         WORKING_DIRECTORY ../doc
#         COMMENT "Generating API documentation with Doxygen"
#         VERBATIM)
# else (DOXYGEN_FOUND)
#   message("Doxygen need to be installed to generate the doxygen documentation")
# endif (DOXYGEN_FOUND)