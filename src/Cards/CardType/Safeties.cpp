#include "Safeties.h"

#include "../../Utils/Utils.h"

std::string Safeties::getLine(size_t n) const {
    return Utils::colorText(displayValue[n], Utils::Color::BLUE);
}

bool Safeties::CanCounterHazards(Hazards hazard) const {
    switch (m_SafetiesType) {
        case SafetiesType::None:
            return false;
        case SafetiesType::DRIVING_ACE:
            return hazard.getHazardsType() == HazardsType::ACCIDENT;
        case SafetiesType::EXTRA_TANK:
            return hazard.getHazardsType() == HazardsType::OUT_OF_GAS;
        case SafetiesType::PUNCTURE_PROOF:
            return hazard.getHazardsType() == HazardsType::FLAT_TIRE;
        case SafetiesType::RIGHT_OF_WAY:
            return hazard.getHazardsType() == HazardsType::SPEED_LIMIT || hazard.getHazardsType() == HazardsType::STOP;
    }
    return false;
}