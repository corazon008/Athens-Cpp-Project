#pragma once
#include <unordered_map>

#include "../Card.h"

enum class RemediesType {
    REPAIRS,
    GASOLINE,
    SPARE_TIRE,
    GO,
    END_LIMIT,
  };

inline std::unordered_map<RemediesType, std::string> remedySymbols = {
    {RemediesType::REPAIRS, "🔧"},
    {RemediesType::GASOLINE, "⛽"},
    {RemediesType::SPARE_TIRE, "🛞"},
    {RemediesType::GO, "🏁"},
    {RemediesType::END_LIMIT, "🚀"}
};

inline std::unordered_map<RemediesType, std::string> remedySymbolsLetter = {
    {RemediesType::REPAIRS, "[FIX]"},
    {RemediesType::GASOLINE, "[FUEL]"},
    {RemediesType::SPARE_TIRE, "[TIRE]"},
    {RemediesType::GO, "[GO!]"},
    {RemediesType::END_LIMIT, "[FAST]"}
};

class Remedies : public Card {
private:
    RemediesType m_remediesType;
public:
    Remedies(){};

    Remedies(RemediesType remediesType) {
        displayValue = CardDisplay::constructCardDisplay(remedySymbols[m_remediesType], remedySymbolsLetter[m_remediesType]);
    }

    CardType getType() const override {
        return CardType::REMEDIES;
    }

    std::string getLine(size_t n) const override;

};
