#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "Game.h"

void displayCard(std::vector<std::string> toDisplay) {
    for (const auto &i: toDisplay) {
        std::cout << i << std::endl;
    }
}

int main() {
    Game game = Game();
    game.SetPlayersCount(3);
    game.GenerateCards();

    std::ostream &os = std::cout;
    for (int i = 0; i <= 5; i++) {
        game.Board(os);
        game.PlayCard(0, 0);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
