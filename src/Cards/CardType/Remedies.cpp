#include "Remedies.h"

#include "../../Utils/Utils.h"

std::string Remedies::GetLine(const size_t n) const {
    return Utils::colorText(displayValue[n], Utils::Color::GREEN);
}

bool Remedies::canCounterHazards(const Hazards &hazard) const {
    switch (m_remediesType) {
        case RemediesType::REPAIRS:
            return hazard.GetHazardsType() == HazardsType::ACCIDENT;
        case RemediesType::GASOLINE:
            return hazard.GetHazardsType() == HazardsType::OUT_OF_GAS;
        case RemediesType::SPARE_TIRE:
            return hazard.GetHazardsType() == HazardsType::FLAT_TIRE;
        case RemediesType::GO:
            return hazard.GetHazardsType() == HazardsType::STOP;
        case RemediesType::END_LIMIT:
            return hazard.GetHazardsType() == HazardsType::SPEED_LIMIT;
    }
    return false;
}
