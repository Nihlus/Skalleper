cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Skalleper)
project(${PROJECT_NAME})

set(${CMAKE_PROJECT_NAME}_SKETCH Skalleper.ino)
set(ARDUINO_DEFAULT_BOARD uno)
set(ARDUINO_DEFAULT_PORT /dev/ttyUSB0)

add_definitions(-DARDUINO_ARCH_AVR)

link_directories(/home/jarl/Arduino/libraries/Chrono)
link_directories(/home/jarl/Arduino/libraries/StandardCplusplus)

generate_arduino_firmware(Skalleper
		SRCS Eye.cpp Skalleper.cpp Skalleper.ino /opt/arduino-1.8.0/libraries/Servo/src/avr/Servo.cpp
		HDRS Eye.h Skalleper.h
		BOARD uno)