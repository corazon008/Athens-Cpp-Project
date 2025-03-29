#include "Safeties.h"

#include "../../Utils/Utils.h"

std::string Safeties::GetLine(size_t n) const {
    return Utils::colorText(displayValue[n], Utils::Color::BLUE);
}

bool Safeties::CanCounterHazards(const Hazards &hazard) const {
    switch (m_SafetiesType) {
        case SafetiesType::None:
            return false;
        case SafetiesType::DRIVING_ACE:
            return hazard.GetHazardsType() == HazardsType::ACCIDENT;
        case SafetiesType::EXTRA_TANK:
            return hazard.GetHazardsType() == HazardsType::OUT_OF_GAS;
        case SafetiesType::PUNCTURE_PROOF:
            return hazard.GetHazardsType() == HazardsType::FLAT_TIRE;
        case SafetiesType::RIGHT_OF_WAY:
            return hazard.GetHazardsType() == HazardsType::SPEED_LIMIT || hazard.GetHazardsType() == HazardsType::STOP;
    }
    return false;
}
