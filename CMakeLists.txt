cmake_minimum_required(VERSION 3.5)
project(Projet)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)

FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 20)

add_executable(Projet main.cpp)

target_link_libraries(Projet sfml-graphics sfml-window sfml-system)