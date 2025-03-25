#include <iostream>
#include "Cards/CardType/Distance.cpp"
#include <vector>

#include "Game.h"

void displayCard(std::vector<std::string> toDisplay) {
    for (const auto & i : toDisplay) {
        std::cout << i << std::endl;
    }
}

using namespace std;
int main() {

    Game game = Game(1);

    std::ostream &os = std::cout;
    game.board(os);


    return 0;
}