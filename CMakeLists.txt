cmake_minimum_required(VERSION 3.12)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 14)

add_executable(MineSweeper main.cpp core/Case.cpp core/Case.h core/Plate.cpp core/Plate.h gui/console.cpp gui/console.h core/game.cpp core/game.h)