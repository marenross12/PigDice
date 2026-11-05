
#ifndef PIGDICE_PDGAMEV2_H
#define PIGDICE_PDGAMEV2_H

#include <string>
#include <iostream>
#include "PDGame.h"

class PDGameV2 : public PDGame {
private:
    std::string m_playerName;
public:
    PDGameV2(const std::string &playerName) {
        m_playerName=playerName;
    }
    std::string getPlayerName() {
        return m_playerName;
    };
    void playGame() override {
        m_myTurn.takeTurn();
        m_gameScore += m_myTurn.getScoreThisTurn();
        if(m_myTurn.getScoreThisTurn() < 50) {
            m_myTurn.resetScore();
            m_myTurn.resetScoreThisTurn();
        }

    }
    void displayRules() {
        std::cout << "Lets play PIG dice!\n";
        std::cout << "\n* See which player will reach 50 points in the fewest turns.\n";
        std::cout << "* Turn ends when you hold or roll a 1.\n";
        std::cout << "* If you roll a 1, you lose all points for the turn.\n";
        std::cout << "* If you hold, you save all points for the turn.\n";
    }
};

#endif //PIGDICE_PDGAMEV2_H
