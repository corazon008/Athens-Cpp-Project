#pragma once

#include <memory>
#include <vector>
#include "../Cards/Card.h"

// Deck class to manage a collection of cards
class Deck {
private:
    std::vector<std::shared_ptr<Card> > m_deck;

public:
    bool AddCard(const std::shared_ptr<Card> &card);

    // Return a card at the specified index
    std::shared_ptr<Card> GetCard(size_t cardIndex) const;

    bool RemoveCard(size_t cardIndex);

    // Print in the stram the cards in the deck given the row
    void DisplayCards(std::ostream &os, size_t row) const;
};
