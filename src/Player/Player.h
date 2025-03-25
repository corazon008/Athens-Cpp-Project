#pragma once
#include <array>

#include "Deck.h"
#include "../Cards/CardType/Hazards.h"
#include "../Cards/CardType/Safeties.h"
#include "../Cards/CardType/Distance.h"
#include "../Cards/CardType/Remedies.h"

class Player {
private:
    size_t m_score;
    Deck m_deck;
    const unsigned int m_id;
    std::array<Hazards, 2> m_hazards;
    std::array<Safeties, 4> m_safeties;

    bool PlayDistanceCard(Distance distance);

    bool PlaySafetyCard(Safeties safety);

    bool PlayHazardCard(Hazards hazard, Player& opponent);

    bool PlayRemedyCard(Remedies remedies, Player& opponent);

public:
    Player(const unsigned int id): m_score(0), m_id(id), m_hazards(), m_safeties() {};

    size_t GetScore() const;

    bool DrawCard(const std::shared_ptr<Card> card);

    bool PlayCard(int cardIndex, Player& opponent);

    bool ReceiveHazard(Hazards hazard);

};


