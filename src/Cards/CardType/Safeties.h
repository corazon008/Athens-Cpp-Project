#pragma once
#include <unordered_map>

#include "../Card.h"

enum class SafetiesType {
    DRIVING_ACE,
    EXTRA_TANK,
    PUNCTURE_PROOF,
    RIGHT_OF_WAY,
  };

inline std::unordered_map<SafetiesType, std::string> safetySymbols = {
    {SafetiesType::DRIVING_ACE, "🏆"},
    {SafetiesType::EXTRA_TANK, "⛽"},
    {SafetiesType::PUNCTURE_PROOF, "🛞"},
    {SafetiesType::RIGHT_OF_WAY, "🚦"}
};

inline std::unordered_map<SafetiesType, std::string> safetySymbolsLetter = {
    {SafetiesType::DRIVING_ACE, "[ACE]"},
    {SafetiesType::EXTRA_TANK, "[TANK]"},
    {SafetiesType::PUNCTURE_PROOF, "[PROOF]"},
    {SafetiesType::RIGHT_OF_WAY, "[→]"}
};


class Safeties : public Card {
private:
    SafetiesType m_SafetiesType;
public:
    Safeties(){};

    Safeties(SafetiesType safetiesType): m_SafetiesType(safetiesType) {
        displayValue = CardDisplay::constructCardDisplay(safetySymbols[m_SafetiesType], safetySymbolsLetter[m_SafetiesType]);
    }

    CardType getType() const override {
        return CardType::SAFETIES;
    }

    std::string getLine(size_t n) const override;

};
