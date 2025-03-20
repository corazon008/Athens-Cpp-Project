#include <cassert>
#include <iostream>
#include "../src/CardDisplay.h"

void displayCard(std::vector<std::string_view> toDisplay) {
    for (int i = 0; i < toDisplay.size(); i++) {
        std::cout << toDisplay[i] << std::endl;
    }
}

class CardDisplayTest {
public:
    static void constructCardDisplay() {
        std::vector<std::string_view> expected;

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