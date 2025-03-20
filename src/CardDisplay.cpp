#include "CardDisplay.h"
#include <string>
#include <format>
#include <vector>
#include <math.h>

std::vector<std::string_view> CardDisplay::constructCardDisplay(int speed) {
    std::vector<std::string_view> display;
    display.push_back(top);
    display.push_back(empty);

    int charLength2Insert = ceil(log10(speed));
    if (charLength2Insert <= 1) {
        display.push_back("│   1   │");
    }
    float nbSpaces = (maxCharLength - charLength2Insert)/2;
    //std::string_view line = ;


    display.push_back(empty);
    display.push_back(bottom);
    return display;
}