#include "Remedies.h"

#include "../../Utils/Utils.h"

std::string Remedies::getLine(size_t n) const {
    return Utils::colorText(displayValue[n], Utils::Color::GREEN);
}
