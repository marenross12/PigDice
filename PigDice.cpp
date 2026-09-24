#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

class Die {
private:
    int m_value;
    int m_numSides;
public:
    Die() {
        m_value = 0;
        m_numSides = 6;
    }
    void setNumSides(int numSides) {
        switch (numSides) {
            case 4: m_numSides = 4; break;
            case 6: m_numSides = 6; break;
            case 8: m_numSides = 8; break;
            default: m_numSides = 6; break;
        }
       // m_numSides = numSides;
    }
    int getNumSides() {
        return m_numSides;
    }
    void setValue() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, m_numSides);
        m_value = dis(gen);
    }
    int getValue() {
        return m_value;
    }
};


void take_turn(GameState &g);
void play_game(GameState &g);
void roll(GameState &g);
void hold(GameState &g);
void display_rules();
int main() {
    GameState my_game; // instantiate a GameState object
    display_rules(); // call the display_rules function
    play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}

void display_rules() {
    std::cout << "Lets play PIG dice!\n";
    std::cout << "\n* See how many turn it takes you to get to 20 points.\n";
    std::cout << "* Turn ends when you hold or roll a 1.\n";
    std::cout << "* If you roll a 1, you lose all points for the turn.\n";
    std::cout << "* If you hold, you bank all points for the turn to the game score.\n";


}

void take_turn(GameState &g) {
    g.turn_count++;
    std::cout << "\nTURN " << g.turn_count << " - " << "Game Score: " << g.game_score;
    while (!g.turn_over) {
        std::cout << "\nroll or hold? (r/h): ";
        std::cin >> g.choice;
        if (g.choice == 'r') {
            roll(g);
        }
        else if (g.choice == 'h') {
            hold(g);
        }
        else {
            std::cout << "Invalid Choice!";
        }
    }
    std::cout << "Score Banked This Turn: " << g.score_this_turn << std::endl;

}

void play_game(GameState &g) {
    while (!g.game_over) {
        take_turn(g);
        g.game_score += g.score_this_turn;
        if (g.game_score >= 20) {
            g.game_over = true;
        }
        else {
            g.turn_over = false;
            g.score_this_turn = 0;
        }
    }
    std::cout << "\nYou finished with a final score of: " << g.game_score;
    std::cout << " in " << g.turn_count << " turns!" << std::endl;
    std::cout << "Thanks for playing PIG Dice!";

}
void roll(GameState &g) {
    // srand(time(NULL));
    // int die = rand() % 6 +1;
    Die myDie; //calls default constructor
    myDie.setValue(); //call public method to roll die
    std::cout << "Die: " << myDie.getValue();
    if (myDie.getValue() == 1) {
        std::cout << "\nTurn over. No score.\n";
        g.score_this_turn = 0;
        g.turn_over = true;
    }
    else {
        g.score_this_turn += myDie.getValue();
        std::cout << " - Running score this turn: " << g.score_this_turn;
    }


}
void hold(GameState &g) {
    g.turn_over = true;

}