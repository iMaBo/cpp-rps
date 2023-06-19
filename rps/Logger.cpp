//
//  Logger.cpp
//  rps
//
//  Created by Marco Boekholt on 19/06/2023.
//

#include <iostream>
#include "Logger.hpp"

void Logger::SetLogLevel(Level logLevel) {
    m_level = logLevel;
}

void Logger::Log(Level level, const std::string& message) {
    switch (level) {
        case Level::Error:
            std::cout << "[error] " << message << std::endl;
            break;
        case Level::Warning:
            std::cout << "[Warning] " << message << std::endl;
            break;
        case Level::Info:
            std::cout << "[INFO] " << message << std::endl;
            break;
        default:
            std::cout << message << std::endl;
            break;
    }
}

void Logger::Input(std::string& variable) {
    std::cin >> variable;
}
