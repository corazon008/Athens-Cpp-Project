#pragma once
#include <unordered_map>

#include "../Card.h"
#include "Hazards.h"

enum class RemediesType {
    REPAIRS,
    GASOLINE,
    SPARE_TIRE,
    GO,
    END_LIMIT,
};

inline std::unordered_map<RemediesType, std::string> remedySymbols = {
    {RemediesType::REPAIRS, "   🔧  "},
    {RemediesType::GASOLINE, "   ⛽   "},
    {RemediesType::SPARE_TIRE, "   🛞  "},
    {RemediesType::GO, "   🏁  "},
    {RemediesType::END_LIMIT, "   🚀  "}
};

inline std::unordered_map<RemediesType, std::string> remedySymbolsLetter = {
    {RemediesType::REPAIRS, "[FIX]"},
    {RemediesType::GASOLINE, "[FUEL]"},
    {RemediesType::SPARE_TIRE, "[TIRE]"},
    {RemediesType::GO, "[GO!]"},
    {RemediesType::END_LIMIT, "[FAST]"}
};

// Remedies class represents a remedies card in the game
class Remedies : public Card {
private:
    RemediesType m_remediesType;

public:
    Remedies() = default;

    Remedies(RemediesType remediesType): m_remediesType(remediesType) {
        displayValue = CardDisplay::constructCardDisplay(remedySymbols[m_remediesType],
                                                         remedySymbolsLetter[m_remediesType]);
    }

    CardType GetType() const override {
        return CardType::REMEDIES;
    }

    RemediesType GetRemediesType() const {
        return m_remediesType;
    }

    std::string GetLine(size_t n) const override;

    bool canCounterHazards(const Hazards &hazard) const;
};
