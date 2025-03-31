#pragma once
#include <array>

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
    bool ShouldPlayGoCard = true;
    bool HasStarted = false;

    bool PlayDistanceCard(Distance &distance);

    bool PlaySafetyCard(const Safeties &safety);

    bool PlayHazardCard(const Hazards &hazard, const std::shared_ptr<Player> &opponent);

    bool PlayRemedyCard(const Remedies &remedies);

    bool HaveRightOfWay() const;

    bool DropCard(const size_t cardIndex);

    bool PlayCard(const size_t cardIndex, const Game *game);

public:
    Player() = default;

    Player(const size_t id): m_score(0), m_id(id), m_hazards(), m_safeties() {
    };

    size_t GetScore() const;

    size_t GetId() const;

    // Add a card to the player's deck
    bool DrawCard(const std::shared_ptr<Card> &card);

    // Print player's deck to the console
    void DisplayDeck(std::ostream &os, size_t row) const;

    void DisplayHazardsAndSafeties(std::ostream &os, size_t row) const;

    bool Play(const Game *game);

    bool ReceiveHazard(const Hazards &hazard);
};


