#include <chrono>
#include <iostream>
#include <thread>

#include "Cards/CardType/Distance.cpp"
#include <vector>

#include "Game.h"

void displayCard(std::vector<std::string> toDisplay) {
    for (const auto &i: toDisplay) {
        std::cout << i << std::endl;
    }
}

int main() {
    Game game = Game(1);

    std::ostream &os = std::cout;
    for (int i = 0; i <= 5; i++) {
        game.Board(os);
        game.PlayCard(0, 0);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
