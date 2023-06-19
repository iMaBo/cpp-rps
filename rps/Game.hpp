//
//  Game.hpp
//  rps
//
//  Created by Marco Boekholt on 19/06/2023.
//

#ifndef Game_hpp
#define Game_hpp

#include "Logger.hpp"



class Game {
public:
    enum class Choice {
        Rock,
        Paper,
        Scissors
    };
    
    void SetLogger(Logger& logger);
    void Play();
    
private:
    Logger* m_Logger;
    Choice GetUserChoice();
    Choice GetComputerChoice();
    std::string GetChoiceName(Choice choice);
    std::string GetGameResult(Choice userChoice, Choice computerChoice);
    void PrintResult(const std::string& result);
};
#endif /* Game_hpp */
