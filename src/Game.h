#pragma once

#include <vector>
#include "Player/Player.h"

class Game {
private:
  const size_t scoreGoal = 100;
  std::vector<Player> m_players;
  size_t m_currentPlayer = 0;
  std::vector<std::shared_ptr<Card> > m_drawPile;

  void shuffleDeck();

  void boardRightPanel(std::ostream &os, size_t row) const;

  void Clear(std::ostream &os) const;

public:
  const std::array<unsigned int, 2> DisplayFrame = {56, 180};

  Game(int nbPlayers);

  bool HaveAWinner() const;

  bool PlayCard(const size_t cardIndex, const size_t opponentIndex);

  void NextPlayer();

  void Board(std::ostream &os) const;
};

