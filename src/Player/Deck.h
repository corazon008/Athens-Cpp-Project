#pragma once

#include <memory>
#include <vector>
#include "../Cards/Card.h"

class Deck {
private:
    std::vector<std::shared_ptr<Card>> m_deck;

public:
    bool AddCard(const std::shared_ptr<Card> card);

    std::shared_ptr<Card> GetCard(int cardIndex);
};
