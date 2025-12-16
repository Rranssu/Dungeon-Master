cmake_minimum_required(VERSION 3.15)

project(DungeonMaster
    VERSION 0.1.0
    DESCRIPTION "2D D&D Game Master Engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(DungeonMaster
    src/main.cpp
)

target_link_libraries(DungeonMaster PRIVATE raylib)

if(UNIX AND NOT APPLE)
    target_link_libraries(DungeonMaster PRIVATE m pthread dl rt X11)
endif()
