cmake_minimum_required(VERSION 3.9)
project(Bus_park C)

set(CMAKE_C_STANDARD 99)

add_executable(Bus_park main.c SmurfIOlib.c SmurfIOlib.h SmurfBuslib.c SmurfBuslib.h SmurfStringLib.c SmurfStringLib.h SmurfSingleLinkedListLib.c SmurfSingleLinkedListLib.h)