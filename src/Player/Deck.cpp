#include "Deck.h"

bool Deck::AddCard(const std::shared_ptr<Card> card) {
    m_deck.push_back(card);
    return true;
}

std::shared_ptr<Card> Deck::GetCard(int cardIndex) {
    return m_deck[cardIndex];
}