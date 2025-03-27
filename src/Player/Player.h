#pragma once
#include <array>
#include <functional>

#include "Deck.h"
#include "../Game.h"
#include "../Cards/CardType/Hazards.h"
#include "../Cards/CardType/Safeties.h"
#include "../Cards/CardType/Distance.h"
#include "../Cards/CardType/Remedies.h"

class Game;

class Player {
private:
    size_t m_score;
    Deck m_deck;
    size_t m_id;
    std::array<Hazards, 2> m_hazards;
    std::array<Safeties, 4> m_safeties;

    bool PlayDistanceCard(Distance distance);

    bool PlaySafetyCard(Safeties safety);

    bool PlayHazardCard(Hazards hazard, std::shared_ptr<Player>& opponent);

    bool PlayRemedyCard(Remedies remedies);

public:
    Player(){};

    Player(const unsigned int id): m_score(0), m_id(id), m_hazards(), m_safeties() {};

    size_t GetScore() const;

    size_t GetId() const;

    bool DrawCard(const std::shared_ptr<Card> card);

    void DisplayDeck(std::ostream &os, size_t row) const;

    void DisplayHazardsNSafeties(std::ostream &os, size_t row) const;

    bool PlayCard(const size_t cardIndex, Player &opponent);

    bool PlayCard(const size_t cardIndex, Game* game);

    bool ReceiveHazard(Hazards hazard);

    Player& operator=(const Player &other) {
        if (this == &other) return *this;
        m_score = other.m_score;
        m_deck = other.m_deck;
        m_id = other.m_id;
        m_hazards = other.m_hazards;
        m_safeties = other.m_safeties;
        return *this;
    }
};


