cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(PROJECT_NAME Skalleper)
project(${PROJECT_NAME})

set(ARDUINO_DEFAULT_BOARD uno)
set(ARDUINO_DEFAULT_PORT /dev/ttyACM0)

include_directories(/home/jarl/Arduino/libraries)
link_directories(/home/jarl/Arduino/libraries)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-threadsafe-statics -fno-exceptions -ffunction-sections -fdata-sections")

set(Servo_RECURSE True)

# Workaround for incorrect arch
add_definitions(-DARDUINO_ARCH_AVR)

generate_arduino_firmware(Skalleper
        SKETCH Skalleper.ino
        SRCS Eye.cpp Skalleper.cpp Skalleper.ino
        HDRS Eye.h Skalleper.h
        BOARD uno)
