cmake_minimum_required(VERSION 3.0.0)
project(SimpleNeuralNetwork VERSION 1.0.0)

find_package(SDL2 REQUIRED)

add_executable(SimpleNeuralNetwork src/main.cpp src/config.h lib/node.cpp)


target_link_libraries(SimpleNeuralNetwork SDL2 SDL2_ttf)
