#include <iostream>

// Build your solution starting from this code.

struct GameState {
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};
void addScore(GameState &gs) {
    gs.game_score += 10;
}

int main() {
    GameState my_game; // instantiate a GameState object
    addScore(my_game);
    std::cout << "Game score is: " << my_game.game_score << std::endl;
    //display_rules(); // call the display_rules function
    //play_game(my_game); // call the play_game function and pass the GameState object
    return 0;
}
