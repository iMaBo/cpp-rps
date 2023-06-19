//
//  main.cpp
//  rps
//
//  Created by Marco Boekholt on 19/06/2023.
//

#include "Logger.hpp"
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    Logger log;
    log.SetLogLevel(Logger::Level::Info);
    
    Game game;
    game.SetLogger(log);
    game.Play();
    
    return 0;
}
