//
//  Game.cpp
//  rps
//
//  Created by Marco Boekholt on 19/06/2023.
//

#include "Game.hpp"
#include <cstdlib>
#include <ctime>
#include <algorithm>

void Game::SetLogger(Logger& logger) {
    m_Logger = &logger;
}

Game::Choice Game::GetUserChoice() {
    m_Logger->Log(Logger::Level::Info, "Enter a choice (rock, paper, scissors): ");
    std::string userInput;
    m_Logger->Input(userInput);
    
    std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
    
    if (userInput == "rock") {
        return Choice::Rock;
    } else if (userInput == "paper") {
        return Choice::Paper;
    } else if (userInput == "scissors") {
        return Choice::Scissors;
    } else {
        return Choice::Rock;
    }
}

Game::Choice Game::GetComputerChoice() {
    srand(static_cast<unsigned int>(time(0)));
    int randomValue = rand() % 3;

    switch (randomValue) {
        case 0:
            return Choice::Rock;
        case 1:
            return Choice::Paper;
        case 2:
            return Choice::Scissors;
        default:
            return Choice::Rock;
    }
}

void Game::PrintResult(const std::string &result) {
    m_Logger->Log(Logger::Level::Info, result);
}

std::string Game::GetChoiceName(Choice choice) {
    switch (choice) {
        case Choice::Rock:
            return "Rock";
        case Choice::Paper:
            return "Paper";
        case Choice::Scissors:
            return "Scissors";
        default:
            return "Unknown";
    }
}

std::string Game::GetGameResult(Choice userChoice, Choice compChoice) {
    if (userChoice == compChoice) {
        return "Both players had the same choice, it's a tie!";
    } else if ((userChoice == Choice::Rock && compChoice == Choice::Scissors) ||
               (userChoice == Choice::Paper && compChoice == Choice::Rock) ||
               (userChoice == Choice::Scissors && compChoice == Choice::Paper)) {
        return "You win!";
    } else {
        return "You lose.";
    }
}

void Game::Play() {
    Choice userChoice = GetUserChoice();
    Choice compChoice = GetComputerChoice();

    std::string userChoiceName = GetChoiceName(userChoice);
    std::string compChoiceName = GetChoiceName(compChoice);

    m_Logger->Log(Logger::Level::Info, "You chose: " + userChoiceName);
    m_Logger->Log(Logger::Level::Info, "Computer chose: " + compChoiceName);

    std::string gameResult = GetGameResult(userChoice, compChoice);
    PrintResult(gameResult);
    
    m_Logger->Log(Logger::Level::Info, "Do you want to play again? (y/n): ");
    std::string again;
    m_Logger->Input(again);
    
    if (again == "y" || again == "Y")
        Game::Play();
}
