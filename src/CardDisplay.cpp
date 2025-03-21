#include "CardDisplay.h"
#include <string>
#include <format>
#include <vector>
#include <math.h>

const std::string CardDisplay::top = "┌───────┐";
const std::string CardDisplay::empty = "│       │";
const std::string CardDisplay::bottom = "└───────┘";

std::vector<std::string> CardDisplay::constructCardDisplay(int distance) {
    std::vector<std::string> display;
    display.push_back(top);
    display.push_back(empty);

    int charLength2Insert = floor(log10(distance)) + 1;
    float nbSpaces = floor((maxCharLength - charLength2Insert) / 2.0f);

    std::string leftSide = "│" + std::string(nbSpaces, ' ');
    std::string rightSide = std::string(nbSpaces, ' ') + "│";
    std::string new_line;

    switch (charLength2Insert) {
        case 1: {
            new_line = leftSide + std::to_string(distance) + rightSide;
            break;
        }
        case 2: {
            std::string number = std::to_string(distance);
            number.insert(1, " ");
            new_line = leftSide + number + rightSide;
            break;
        }
        case 3: {
            new_line = leftSide + std::to_string(distance) + rightSide;
            break;
        }
    }

    display.push_back(new_line);
    display.push_back(empty);
    display.push_back(bottom);
    return display;
}
