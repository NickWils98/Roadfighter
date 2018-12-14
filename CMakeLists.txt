cmake_minimum_required(VERSION 3.9)
project(Roadfighter)

set(CMAKE_CXX_STANDARD 11)

add_executable(Roadfighter main.cpp)
# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC main.cpp Game.cpp Game.h Entity.cpp Entity.h World.cpp World.h Car.cpp Car.h PlayerCar.cpp PlayerCar.h PlayerCarSFML.cpp PlayerCarSFML.h Transformation.cpp Transformation.h Collider.cpp Collider.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(Roadfighter_sfml ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(Roadfighter_sfml ${SFML_LIBRARIES})

INSTALL(TARGETS Roadfighter_sfml DESTINATION ${PROJECT_SOURCE_DIR}/bin)