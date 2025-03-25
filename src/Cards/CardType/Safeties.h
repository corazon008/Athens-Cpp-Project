#pragma once
#include "../Card.h"

class Safeties : public Card {
public:

    CardType getType() const override {
        return CardType::SAFETIES;
    }
};
