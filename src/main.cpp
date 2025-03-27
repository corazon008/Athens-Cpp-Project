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
        while (!game.PlayCard()) {
            std::cout << "Invalid card" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        game.NextPlayer();
    }

    return 0;
}
