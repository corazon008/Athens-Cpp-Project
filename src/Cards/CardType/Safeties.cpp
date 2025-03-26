#include "Safeties.h"

#include "../../Utils/Utils.h"

std::string Safeties::getLine(size_t n) const {
    return Utils::colorText(displayValue[n], Utils::Color::BLUE);
}
