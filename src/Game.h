#pragma once

#include "Player/Player.h"

class Player;

class Game {
private:
  const size_t scoreGoal = 1000;
  std::vector<std::shared_ptr<Player> > m_players;
  size_t m_currentPlayer = 0;
  size_t m_nbPlayers = 0;
  size_t MaxPlayers = 3;
  std::vector<std::shared_ptr<Card> > m_drawPile;

  void ShuffleCards();

  // Print the other players' decks
  void BoardRightPanel(std::ostream &os, size_t row) const;

  // Clear the console
  void Clear(std::ostream &os) const;

  void DrawCard();

  // Print a player deck
  void BoardRightPanelPlayer(std::ostream &os, const Player &player, size_t row) const;

  size_t AskCardToPlay() const;

public:
  const std::array<unsigned int, 2> DisplayFrame = {56, 140};

  Game() = default;

  bool SetPlayersCount(size_t nbPlayers);

  //Generate Distance Cards
  bool GenerateCards();

  bool HaveAWinner() const;

  bool PlayCard();

  // Ask the player to choose an opponent to target with his hazard card
  bool AskOpponent(std::shared_ptr<Player> &opponent) const;

  void NextPlayer();

  void DisplayBoard(std::ostream &os) const;
};

