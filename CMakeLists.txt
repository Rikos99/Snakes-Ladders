cmake_minimum_required(VERSION 3.24)
project(Snakes_Ladders C)

set(CMAKE_C_STANDARD 11)

add_executable(Snakes_Ladders main.c kostka.c kostka.h snakes-and-ladders.c snakes-and-ladders.h)
