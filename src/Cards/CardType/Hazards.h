#pragma once

#include <unordered_map>

#include "../Card.h"

enum class HazardsType {
    ACCIDENT,
    OUT_OF_GAS,
    FLAT_TIRE, // 🚒🚦🔴
    STOP,
    SPEED_LIMIT
  };

inline std::unordered_map<HazardsType, std::string> hazardSymbols = {
    {HazardsType::ACCIDENT, "⚠️"},
    {HazardsType::OUT_OF_GAS, "⛽"},
    {HazardsType::FLAT_TIRE, "🛞"},
    {HazardsType::STOP, "🛑"},
    {HazardsType::SPEED_LIMIT, "🚧"}
};

inline std::unordered_map<HazardsType, std::string> hazardSymbolsLetter = {
    {HazardsType::ACCIDENT, "[!]" },
    {HazardsType::OUT_OF_GAS, "[GAS]" },
    {HazardsType::FLAT_TIRE, "[TIRE]" },
    {HazardsType::STOP, "[STOP]" },
    {HazardsType::SPEED_LIMIT, "[SLOW]" }
};

class Hazards : public Card {
private:
    HazardsType m_hazardsType;
public:

    Hazards(){};

    Hazards(HazardsType hazardsType): m_hazardsType(hazardsType) {
        displayValue = CardDisplay::constructCardDisplay(hazardSymbols[hazardsType], hazardSymbolsLetter[hazardsType]);
    };

    CardType getType() const override {
        return CardType::HAZARDS;
    }

    std::string getLine(size_t n) const override;
};
