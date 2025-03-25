#pragma once

#include <vector>
#include "Player/Player.h"

class Game {
private:
  const size_t scoreGoal = 100;
  std::vector<Player> m_players;
  size_t m_currentPlayer = 0;
  std::vector<std::shared_ptr<Card>> m_drawPile;

  void shuffleDeck();

  void boardRightPanel(std::ostream &os) const;

public:
  const std::array<int, 2> DisplayFrame = {8, 20};

  Game(int nbPlayers);

  bool HaveAWinner() const;

  void nextPlayer();

  void board(std::ostream &os) const;

};

