#pragma once

#include "../Card.h"
#include "../CardDisplay.h"

class Distance : public Card {
private:
    int m_distance;

public:
    Distance(int distance): m_distance(distance) {
        displayValue = CardDisplay::constructCardDisplay(distance);
    };

    ~Distance() override = default;


    int GetDistance() const {
        return m_distance;
    }

    CardType getType() const override {
        return CardType::DISTANCE;
    }
};
