#include "Game.h"

#include <algorithm>
#include <ostream>
#include <random>
#include <vector>

#include "Cards/CardType/Distance.h"
#include "Utils/Utils.h"

bool Game::SetPlayersCount(size_t nbPlayers) {
    if (nbPlayers < 2 || nbPlayers > MaxPlayers) return false;
    m_nbPlayers = nbPlayers;
    return true;
}

bool Game::GenerateCards() {
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
    for (int i = 0; i < 3; i++) {
        m_drawPile.push_back(std::make_shared<Hazards>(Hazards(HazardsType::ACCIDENT)));
        m_drawPile.push_back(std::make_shared<Hazards>(Hazards(HazardsType::OUT_OF_GAS)));
        m_drawPile.push_back(std::make_shared<Hazards>(Hazards(HazardsType::FLAT_TIRE)));
    }
    for (int i = 0; i < 4; i++) {
        m_drawPile.push_back(std::make_shared<Hazards>(Hazards(HazardsType::STOP)));
        m_drawPile.push_back(std::make_shared<Hazards>(Hazards(HazardsType::SPEED_LIMIT)));
    }
    m_drawPile.push_back(std::make_shared<Hazards>(Hazards(HazardsType::STOP))); // 5 STOP cards
    //Generate Remedies Cards
    for (int i = 0; i < 6; i++) {
        m_drawPile.push_back(std::make_shared<Remedies>(Remedies(RemediesType::REPAIRS)));
        m_drawPile.push_back(std::make_shared<Remedies>(Remedies(RemediesType::GASOLINE)));
        m_drawPile.push_back(std::make_shared<Remedies>(Remedies(RemediesType::SPARE_TIRE)));
    }
    for (int i = 0; i < 14; i++) {
        m_drawPile.push_back(std::make_shared<Remedies>(Remedies(RemediesType::GO)));
    }
    for (int i = 0; i < 6; i++) {
        m_drawPile.push_back(std::make_shared<Remedies>(Remedies(RemediesType::END_LIMIT)));
    }

    //Generate Safeties Cards
    m_drawPile.push_back(std::make_shared<Safeties>(Safeties(SafetiesType::DRIVING_ACE)));
    m_drawPile.push_back(std::make_shared<Safeties>(Safeties(SafetiesType::EXTRA_TANK)));
    m_drawPile.push_back(std::make_shared<Safeties>(Safeties(SafetiesType::PUNCTURE_PROOF)));
    m_drawPile.push_back(std::make_shared<Safeties>(Safeties(SafetiesType::RIGHT_OF_WAY)));

    //Shuffle the deck
    shuffleDeck();

    int nbCardsPerPlayer = 6;
    for (size_t i = 0; i < m_nbPlayers; i++) {
        m_players.push_back(Player(i));
        for (int j = 0; j < nbCardsPerPlayer; j++) {
            m_players[i].DrawCard(m_drawPile.back());
            m_drawPile.pop_back();
        }
    }
    return true;
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

    DrawCard();
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
            m_players[m_currentPlayer].DisplayDeck(os, row - (DeckRowBegin + 1));
        }


        os << std::endl;
    }
    os.flush();
}

void Game::boardRightPanelPlayer(std::ostream &os, const Player &player, size_t row) const {
    if (row == 0)
        os << player.GetScore();
    if (0 < row && row <= 5)
        player.DisplayHazardsNSafeties(os, row - 1);
}


void Game::boardRightPanel(std::ostream &os, size_t row) const {
    os << "│     ";
    size_t HeightNeededToDisplayPlayer = 7; // Included
    // List of players without the current player
    std::vector<size_t> playerToDisplay;
    for (size_t i = 0; i < m_nbPlayers; i++) {
        if (i == m_currentPlayer)
            continue;
        playerToDisplay.push_back(i);
    }

    size_t PlayerRow = 1;
    for (const auto &playerId: playerToDisplay) {
        Player player = m_players[playerId];
        if (HeightNeededToDisplayPlayer * (PlayerRow - 1) <= row && row < HeightNeededToDisplayPlayer * PlayerRow) {
            boardRightPanelPlayer(os, player, row - HeightNeededToDisplayPlayer * (PlayerRow - 1));
        }
        if (row == (HeightNeededToDisplayPlayer-1) * PlayerRow && PlayerRow < (m_nbPlayers -1)) {
            for (int k = 0; k < 55; k++)
                os << "─";
        }
        PlayerRow++;
    }
}

