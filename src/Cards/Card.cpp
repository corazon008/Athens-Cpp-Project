#include "Card.h"
#include <string>
#include <format>
#include <vector>
#include <math.h>

std::vector<std::string> Card::EmptyCard = {
    "┌───────┐",
    "│       │",
    "│       │",
    "│       │",
    "└───────┘"
};

std::string Card::getLine(size_t n) const {
    if (n >= displayValue.size()) return "";

    return displayValue[n];
}