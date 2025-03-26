#pragma once
#include "../Card.h"

class Safeties : public Card {
public:
    Safeties() {
        displayValue = {
            "┌───────┐",
            "│       │",
            "│Safety │",
            "│       │",
            "└───────┘"
        };
    }

    CardType getType() const override {
        return CardType::SAFETIES;
    }
};
