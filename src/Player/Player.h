#pragma once
#include <array>

#include "Deck.h"
#include "../Cards/CardType/Hazards.h"
#include "../Cards/CardType/Safeties.h"

class Player {
private:
    int m_score;
    Deck m_deck;
    std::array<Hazards, 2> m_hazards;
    std::array<Safeties, 4> m_safeties;

    bool PlayDistanceCard(int distance);

    bool PlaySafetyCard(Safeties safety);

    bool PlayHazardCard(Hazards hazard, Player& opponent);

    bool PlayRemedyCard(Hazards hazard, Player& opponent);

public:
    int GetScore() const;

    bool DrawCard(Card& card);

    bool PlayCard(int cardIndex, Player& opponent);

    bool ReceiveHazard(Hazards hazard);

};


