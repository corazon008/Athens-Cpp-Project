#include "Deck.h"

bool Deck::AddCard(const Card& card) {
    m_deck.push_back(card);
    return true;
}