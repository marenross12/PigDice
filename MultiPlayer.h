
#ifndef PIGDICE_MULTIPLAYER_H
#define PIGDICE_MULTIPLAYER_H
#include <algorithm>

#include "PDGameV2.h"
#include <vector>

class MultiPlayer {
    private:
    std::vector<PDGameV2> m_players;
    bool m_gameOver;
    public:
    MultiPlayer() {
        int count;
        std::string tempName;
        std::cout << "How many people are playing?";
        std::cin >> count;
        std::cin.ignore();
        for (int i = 0; i < count; i++) {
            std::cout << "Enter player " << i << "'s name: ";
            std::getline(std::cin, tempName);
            m_players.emplace_back(tempName);
        }

    }
    void mpPlayGame() {
        m_players[0].displayRules();
        while (!m_gameOver) {
            for (int i = 0; i < m_players.size(); i++) {
                std::cout << "\n\n" << m_players[i].getPlayerName() << "";
                m_players.at(i).playGame();
                displayScoreBoard();
            }
        }
    };
    private:
    void checkForWinner() {
        int max;
        std::string winner;
        for (PDGameV2 x : m_players) {
            if (x.getGameScore() > max) {
                max = x.getGameScore();
                winner = x.getPlayerName();
            }
        }
        std::cout << "Congratulations! " << winner << " you win with a score of " << max << "." << std::endl;
    }
    void displayScoreBoard() {
        for (int i = 0; i < m_players.size(); i++) {
            std::cout << m_players.at(i).getPlayerName() << "(Score: " << m_players.at(i).getGameScore() << ")" << " | ";
        }
    }
};

#endif //PIGDICE_MULTIPLAYER_H
