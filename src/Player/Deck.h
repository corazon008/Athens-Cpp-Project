#pragma once

#include <vector>
#include "../Cards/Card.h"

class Deck {
private:
    std::vector<Card> m_deck;

public:
    bool AddCard(const Card& card);
};
