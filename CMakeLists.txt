cmake_minimum_required(VERSION 4.1)
project(SS01)

set(CMAKE_CXX_STANDARD 20)

add_executable(SS01 main.cpp
        UsingReferences/DiceRoller.cpp
        UsingReferences/DiceRoller.h
        SimpleDiceGame/Player.cpp
        SimpleDiceGame/Player.h
        SimpleDiceGame/PlayerQueue.cpp
        SimpleDiceGame/PlayerQueue.h
        SimpleDiceGame/SimpleDiceGame.cpp
        SimpleDiceGame/SimpleDiceGame.h
        HiddenTreasure/HiddenTreasure.cpp
        HiddenTreasure/HiddenTreasure.h)
