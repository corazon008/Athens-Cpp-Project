#include <iostream>
#include "src/Cards/CardType/Distance.cpp"
#include <vector>

#include "src/Game.h"


using namespace std;
int main() {

    Game game = Game(1);

    std::ostream &os = std::cout;
    game.board(os);

    return 0;
}