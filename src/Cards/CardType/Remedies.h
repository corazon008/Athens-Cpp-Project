#pragma once
#include "../Card.h"

class Remedies : public Card {
public:

    CardType getType() const override {
        return CardType::REMEDIES;
    }
};
