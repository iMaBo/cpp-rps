//
//  Logger.hpp
//  rps
//
//  Created by Marco Boekholt on 19/06/2023.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <string>

class Logger {
public:
    enum class Level {
        Error, Warning, Info, None
    };
    
    void SetLogLevel(Level logLevel);
    void Log(Level level, const std::string& message);
    void Input(std::string& variable);
    
private:
    Level m_level = Level::Error;
    
};
#endif /* Logger_hpp */
