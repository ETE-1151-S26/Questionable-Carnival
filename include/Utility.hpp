#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
constexpr bool testing = true;// Global variable to control whether to skip delays for testing purposes
inline void slowPrint(const std::string& text, int speed = 30) {
    for (char c : text) {
        std::cout << c << std::flush;
        if constexpr(!testing){
            std::this_thread::sleep_for(std::chrono::milliseconds(speed));
        }
        else{
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    std::cout << std::endl;
}

inline void pause(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}