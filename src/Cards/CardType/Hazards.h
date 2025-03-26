#pragma once

#include "../Card.h"

class Hazards : public Card {
public:

    Hazards() {
        displayValue = {
            "┌───────┐",
            "│       │",
            "│ Hazard│",
            "│       │",
            "└───────┘"
        };
    };

    CardType getType() const override {
        return CardType::HAZARDS;
    }
};
