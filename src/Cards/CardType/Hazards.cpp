#include "Hazards.h"

#include "../../Utils/Utils.h"

std::string Hazards::GetLine(const size_t n) const {
    return Utils::colorText(displayValue[n], Utils::Color::RED);
}
