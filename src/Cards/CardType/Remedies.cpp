#include "Remedies.h"

#include "../../Utils/Utils.h"

std::string Remedies::getLine(size_t n) const {
    return Utils::colorText(displayValue[n], Utils::Color::GREEN);
}

bool Remedies::canCounterHazards(Hazards hazard) const {
    switch (m_remediesType) {
        case RemediesType::REPAIRS:
            return hazard.getHazardsType() == HazardsType::ACCIDENT;
        case RemediesType::GASOLINE:
            return hazard.getHazardsType() == HazardsType::OUT_OF_GAS;
        case RemediesType::SPARE_TIRE:
            return hazard.getHazardsType() == HazardsType::FLAT_TIRE;
        case RemediesType::GO:
            return hazard.getHazardsType() == HazardsType::STOP;
        case RemediesType::END_LIMIT:
            return hazard.getHazardsType() == HazardsType::SPEED_LIMIT;
    }
    return false;
}
