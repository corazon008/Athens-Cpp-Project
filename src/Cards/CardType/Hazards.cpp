#include "Hazards.h"

#include "../../Utils/Utils.h"

std::string Hazards::getLine(size_t n) const {
    return Utils::colorText(displayValue[n], Utils::Color::RED);
}
