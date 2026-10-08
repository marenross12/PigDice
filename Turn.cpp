#include <iostream>
#include "Turn.h"
Turn::Turn() {
     m_turnCount = 0;
     m_scoreThisTurn = 0;
     m_turnOver = false;
     m_choice ='\0' ;

}
//Turn(&);
void Turn::takeTurn() {
     m_turnCount++;
     //Turn (part) needs access to m_gameScore in PDGame (whole)
     std::cout << "\nTURN " << m_turnCount << " - " << "Game Score: "; //<< m_gameScore;
     while (!m_turnOver) {
          std::cout << "\nroll or hold? (r/h): ";
          std::cin >> m_choice;
          if (m_choice == 'r') {
               roll();

          }
          else if (m_choice == 'h') {
               m_turnOver = true;
          }
          else {
               std::cout << "Invalid Choice!";
          }
     }
     std::cout << "Score Banked This Turn: " << m_scoreThisTurn << std::endl;

}

int Turn::getScoreThisTurn() const {
     return m_scoreThisTurn;
}

void Turn::resetTurnOver() {
     m_turnOver = false;
}

int Turn::getTurnCount() const {
     return m_turnCount;
}

void Turn::resetScoreThisTurn() {
     m_scoreThisTurn = 0;
}

void Turn::roll() {
     m_myDie.rollDie();
     std::cout << "Die: " << m_myDie.getDieValue();
     if (m_myDie.getDieValue() == 1) {
          std::cout << "\nTurn over. No score.\n";
          m_scoreThisTurn = 0;
          m_turnOver = true;
     }
     else {
          m_scoreThisTurn += m_myDie.getDieValue();
          std::cout << " - Running score this turn: " << m_scoreThisTurn;
     }
}