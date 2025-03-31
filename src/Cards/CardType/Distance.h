#pragma once

#include "../Card.h"
#include "../CardDisplay.h"

// Distance class represents a distance card in the game
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

    CardType GetType() const override {
        return CardType::DISTANCE;
    }
};
