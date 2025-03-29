#include "Card.h"
#include <string>
#include <vector>

std::vector<std::string> Card::EmptyCard = {
    "┌───────┐",
    "│       │",
    "│       │",
    "│       │",
    "└───────┘"
};

std::string Card::GetLine(const size_t n) const {
    if (n >= displayValue.size()) return "";

    return displayValue[n];
}
