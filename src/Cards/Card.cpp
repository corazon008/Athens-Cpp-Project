#include "Card.h"
#include <string>
#include <format>
#include <vector>
#include <math.h>

std::string Card::getLine(size_t n) const {
    if (n >= displayValue.size()) return "";

    return displayValue[n];
}

CardType Card::getType() const {
    return m_type;
}



