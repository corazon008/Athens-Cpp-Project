#pragma once

#include "Player/Player.h"

class Player;

class Game {
private:
  const size_t scoreGoal = 300;
  std::vector<Player> m_players;
  size_t m_currentPlayer = 0;
  size_t m_nbPlayers = 0;
  size_t MaxPlayers = 4;
  std::vector<std::shared_ptr<Card> > m_drawPile;

  void shuffleDeck();

  void boardRightPanel(std::ostream &os, size_t row) const;

  void Clear(std::ostream &os) const;

  void DrawCard();

  void boardRightPanelPlayer(std::ostream &os, const Player &player, size_t row) const;

  size_t AskCardToPlay() const;



public:
  const std::array<unsigned int, 2> DisplayFrame = {56, 140};

  Game() {
  };

  bool SetPlayersCount(size_t nbPlayers);

  bool GenerateCards();

  bool HaveAWinner() const;

  bool PlayCard();

  bool AskOpponent(Player& opponent) const ;

  void NextPlayer();

  void Board(std::ostream &os) const;
};

