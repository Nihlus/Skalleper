cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Skalleper)
project(${PROJECT_NAME})

set(ARDUINO_DEFAULT_BOARD uno)
set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0)

link_directories(/home/jarl/Arduino/libraries/Chrono)
link_directories(/home/jarl/Arduino/libraries/StandardCplusplus)

generate_arduino_firmware(Skalleper
		SRCS Eye.cpp Skalleper.cpp Skalleper.ino
		HDRS Eye.h Skalleper.h
		BOARD uno)