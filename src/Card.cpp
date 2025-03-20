#include "Card.h"
#include <string>
#include <format>
#include <vector>
#include <math.h>

std::string_view Card::getLine(int n) const {
    if (n >= displayValue.size()) return "";

    return displayValue[n];
}



