#pragma once

#include <memory>
#include <vector>
#include "../Cards/Card.h"

class Deck {
private:
    std::vector<std::shared_ptr<Card> > m_deck;

public:
    bool AddCard(const std::shared_ptr<Card> &card);

    std::shared_ptr<Card> GetCard(size_t cardIndex);

    bool RemoveCard(size_t cardIndex);

    void DisplayCards(std::ostream &os, size_t row) const;
};
