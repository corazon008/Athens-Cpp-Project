#include "Game.h"

#include <algorithm>
#include <ostream>
#include <random>
#include <vector>

#include "Cards/CardType/Distance.h"
#include "const.h"

Game::Game(int nbPlayers) {
    //Generate Distance Cards
    for (int i = 0; i < 10; i++) {
        m_drawPile.push_back(std::make_shared<Distance>(Distance(25)));
        m_drawPile.push_back(std::make_shared<Distance>(Distance(50)));
        m_drawPile.push_back(std::make_shared<Distance>(Distance(75)));
    }
    for (int i = 0; i < 12; i++) {
        m_drawPile.push_back(std::make_shared<Distance>(Distance(100)));
    }
    for (int i = 0; i < 4; i++) {
        m_drawPile.push_back(std::make_shared<Distance>(Distance(200)));
    }

    //Generate Hazards Cards
    //Generate Remedies Cards
    //Generate Safeties Cards

    //Shuffle the deck
    shuffleDeck();

    int nbCardsPerPlayer = 6;
    for (int i = 0; i < nbPlayers; i++) {
        m_players.push_back(Player(i));
        for (int j = 0; j < nbCardsPerPlayer; j++) {
            m_players[i].DrawCard(m_drawPile.back());
            m_drawPile.pop_back();
        }
    }
}

void Game::shuffleDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_drawPile.begin(), m_drawPile.end(), g);
}

void Game::board(std::ostream &os) const {
    for (const auto & player : m_players) {
        os << "Player " << player.GetScore() << std::endl;
    }

    for (size_t j=0; j < 5; j++) {
        for (size_t i = 0; i < GetIntLength(m_players[m_currentPlayer].GetScore()); i++) {
            auto current_digit = GetNthDigit(m_players[m_currentPlayer].GetScore(), i);
            os << DigitToStringListRow(current_digit, j);
        }
        os << std::endl;
    }




}

bool Game::HaveAWinner() const {
    for (const auto & player : m_players) {
        if (player.GetScore() >= scoreGoal) {
            return true;
        }
    }
    return false;
}

void Game::nextPlayer() {
    m_currentPlayer = (m_currentPlayer + 1) % m_players.size();
}


