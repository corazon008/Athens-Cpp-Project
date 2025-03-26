#include "Deck.h"

bool Deck::AddCard(const std::shared_ptr<Card>& card) {
    m_deck.push_back(card);
    return true;
}

std::shared_ptr<Card> Deck::GetCard(const size_t cardIndex) {
    std::shared_ptr<Card> card = m_deck[cardIndex];
    m_deck.erase(m_deck.begin() + cardIndex);
    return card;
}

void Deck::DisplayCards(std::ostream &os, const size_t row) const {
    for (const auto &card: m_deck) {
        os << card->getLine(row);
    }
}
