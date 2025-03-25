#pragma once

#include "../Card.h"

class Hazards : public Card {
public:

    CardType getType() const override {
        return CardType::HAZARDS;
    }
};
