#include "Game.h"

#include <algorithm>
#include <ostream>
#include <random>
#include <vector>

#include "Cards/CardType/Distance.h"
#include "Utils/Utils.h"

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

bool Game::HaveAWinner() const {
    for (const auto &player: m_players) {
        if (player.GetScore() >= scoreGoal) {
            return true;
        }
    }
    return false;
}

void Game::NextPlayer() {
    m_currentPlayer = (m_currentPlayer + 1) % m_players.size();
}

bool Game::PlayCard(const size_t cardIndex, const size_t opponentIndex) {
    if (m_currentPlayer >= m_players.size() || opponentIndex >= m_players.size()) return false;

    return m_players[m_currentPlayer].PlayCard(cardIndex, m_players[opponentIndex]);
}

void Game::DrawCard() {
    if (m_drawPile.empty()) return;
    m_players[m_currentPlayer].DrawCard(m_drawPile.back());
    m_drawPile.pop_back();
}

void Game::Clear(std::ostream &os) const {
    os.flush();
    //os << "\033[2J\033[H"; // Efface et replace le curseur en haut
    os << "\033[H\033[J";
    os.flush();
}

void Game::Board(std::ostream &os) const {
    Clear(os);
    const size_t RightPanelWidth = DisplayFrame[1] / 2;
    const size_t DeckRowBegin = 5;

    for (size_t row = 0; row < 16; row++) {
        for (size_t column = 0; column < RightPanelWidth; column++) {
            os << " "; // populate the current line with spaces so that no calculation needed for the right panel
        }
        boardRightPanel(os, row);

        if (row < 5) {
            os << "\r";
            for (size_t i = 0; i < Utils::GetIntLength(m_players[m_currentPlayer].GetScore()); i++) {
                auto current_digit = Utils::GetNthDigit(m_players[m_currentPlayer].GetScore(), i);
                os << Utils::DigitToStringListRow(current_digit, row % 5);
            }
        } else if (DeckRowBegin < row && row < DeckRowBegin + 11) {
            os << "\r";
            m_players[m_currentPlayer].DisplayCards(os, row - (DeckRowBegin + 1));
        }


        os << std::endl;
    }
    os.flush();
}

void Game::boardRightPanel(std::ostream &os, size_t row) const {
    os << "│";
}

