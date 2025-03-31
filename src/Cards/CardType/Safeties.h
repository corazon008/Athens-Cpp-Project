#pragma once
#include <unordered_map>

#include "../Card.h"
#include "Hazards.h"

enum class SafetiesType {
    None,
    DRIVING_ACE,
    EXTRA_TANK,
    PUNCTURE_PROOF,
    RIGHT_OF_WAY,
};

inline std::unordered_map<SafetiesType, std::string> safetySymbols = {
    {SafetiesType::DRIVING_ACE, "   🏆  "},
    {SafetiesType::EXTRA_TANK, "   ⛽   "},
    {SafetiesType::PUNCTURE_PROOF, "   🛞  "},
    {SafetiesType::RIGHT_OF_WAY, " 🚒 🚦 "}
};

inline std::unordered_map<SafetiesType, std::string> safetySymbolsLetter = {
    {SafetiesType::DRIVING_ACE, "[ACE]"},
    {SafetiesType::EXTRA_TANK, "[TANK]"},
    {SafetiesType::PUNCTURE_PROOF, "[PROOF]"},
    {SafetiesType::RIGHT_OF_WAY, "[->]"}
};


// Safeties class represents a safety cards in the game
class Safeties : public Card {
private:
    SafetiesType m_SafetiesType;

public:
    Safeties() {
        m_SafetiesType = SafetiesType::None;
    };

    Safeties(SafetiesType safetiesType): m_SafetiesType(safetiesType) {
        displayValue = CardDisplay::constructCardDisplay(safetySymbols[m_SafetiesType],
                                                         safetySymbolsLetter[m_SafetiesType]);
    }

    CardType GetType() const override {
        return CardType::SAFETIES;
    }

    SafetiesType GetSafetiesType() const {
        return m_SafetiesType;
    }

    std::string GetLine(size_t n) const override;

    bool CanCounterHazards(const Hazards &hazard) const;
};
