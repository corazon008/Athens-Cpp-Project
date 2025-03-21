#include <cassert>
#include <iostream>
#include "../src/CardDisplay.h"

void displayCard(std::vector<std::string> toDisplay) {
    for (int i = 0; i < toDisplay.size(); i++) {
        std::cout << toDisplay[i] << std::endl;
    }
}

class CardDisplayTest {
public:
    static void constructCardDisplay() {
        std::vector<std::string> expected;

        expected = {
            "┌───────┐",
            "│       │",
            "│   1   │",
            "│       │",
            "└───────┘"
        };
        displayCard(CardDisplay::constructCardDisplay(1));
        assert(CardDisplay::constructCardDisplay(1) == expected);

        expected = {
            "┌───────┐",
            "│       │",
            "│   5   │",
            "│       │",
            "└───────┘"
        };
        displayCard(CardDisplay::constructCardDisplay(5));
        assert(CardDisplay::constructCardDisplay(5) == expected);

        expected = {
            "┌───────┐",
            "│       │",
            "│  2 5  │",
            "│       │",
            "└───────┘"
        };
        assert(CardDisplay::constructCardDisplay(25) == expected);

        expected = {
            "┌───────┐",
            "│       │",
            "│  100  │",
            "│       │",
            "└───────┘"
        };
        assert(CardDisplay::constructCardDisplay(100) == expected);
    }
};