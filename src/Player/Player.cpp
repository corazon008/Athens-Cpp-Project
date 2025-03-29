#include "Player.h"

#include <iostream>

#include "../Cards/CardType/Distance.h"
#include "../Utils/Utils.h"

size_t Player::GetScore() const {
  return m_score;
}

size_t Player::GetId() const {
  return m_id;
}

bool Player::HaveRightOfWay() const {
  for (const auto &safeties: m_safeties)
    if (safeties.GetSafetiesType() == SafetiesType::RIGHT_OF_WAY)
      return true;
  return false;
}

bool Player::Play(const Game *game) {
  size_t cardIndex = Utils::AskInt("Which card do you want to play? [1-6]: ") - 1;
  if (cardIndex > 6)
    return false;

  bool wantToDropCard = Utils::AskYesNo("Do you want to drop this card? (yes/no) [No]: ", false);
  if (wantToDropCard)
    return DropCard(cardIndex);

  return PlayCard(cardIndex, game);
}

bool Player::DropCard(const size_t cardIndex) {
  return m_deck.RemoveCard(cardIndex);
}

bool Player::PlayDistanceCard(Distance &card) {
  for (const auto &hazard: m_hazards) {
    if (hazard.GetHazardsType() == HazardsType::SPEED_LIMIT && card.GetDistance() > 50)
      return false;
    if (hazard.GetHazardsType() != HazardsType::None && hazard.GetHazardsType() != HazardsType::SPEED_LIMIT)
      // All other hazards block the card
      return false;
  }
  m_score += card.GetDistance();
  return true;
}

bool Player::PlaySafetyCard(const Safeties &safety) {
  for (size_t i = 0; i < m_hazards.size(); i++)
    if (safety.CanCounterHazards(m_hazards[i]))
      m_hazards[i] = Hazards();

  for (size_t i = 0; i < m_safeties.size(); i++) {
    if (m_safeties[i].GetSafetiesType() == SafetiesType::None) {
      m_safeties[i] = safety;
      return true;
    }
  }
  return false;
}

bool Player::PlayHazardCard(const Hazards &hazard, const std::shared_ptr<Player> &opponent) {
  return opponent->ReceiveHazard(hazard);
}

bool Player::ReceiveHazard(const Hazards &hazard) {
  //TODO
  for (const auto &safeties: m_safeties) {
    if (safeties.CanCounterHazards(hazard))
      return false;
  }
  for (auto &h: m_hazards) {
    if (h.GetHazardsType() != HazardsType::None)
      continue;
    h = hazard;
    return true;
  }
  return false;
}

bool Player::PlayRemedyCard(const Remedies &remedies) {
  for (auto &hazard: m_hazards) {
    if (remedies.canCounterHazards(hazard)) {
      hazard = Hazards();
      ShouldPlayGoCard = true && !HaveRightOfWay();
      return true;
    }
  }
  return false;
}

bool Player::DrawCard(const std::shared_ptr<Card> &card) {
  m_deck.AddCard(card);
  return true;
}

bool Player::PlayCard(const size_t cardIndex, const Game *game) {
  std::shared_ptr<Card> playedCard = m_deck.GetCard(cardIndex);

  if (!playedCard) return false;

  if (ShouldPlayGoCard) {
    if (const auto remedyCard = std::dynamic_pointer_cast<Remedies>(playedCard)) {
      if (remedyCard->GetRemediesType() == RemediesType::GO) {
        ShouldPlayGoCard = false;
        return m_deck.RemoveCard(cardIndex);
      }
    } else {
      std::cout << Utils::colorText("You need to play a GO Card to begin or after countering hazard",
                                    Utils::Color::GREEN) << std::endl;
      return false;
    }
  }

  switch (playedCard->GetType()) {
    case CardType::DISTANCE: {
      if (const auto distCard = std::dynamic_pointer_cast<Distance>(playedCard))
        if (PlayDistanceCard(*distCard))
          return m_deck.RemoveCard(cardIndex);
    }
    case CardType::HAZARDS: {
      if (const auto hazardCard = std::dynamic_pointer_cast<Hazards>(playedCard)) {
        std::shared_ptr<Player> opponent;
        if (!game->AskOpponent(opponent))
          return false;
        if (PlayHazardCard(*hazardCard, opponent))
          return m_deck.RemoveCard(cardIndex);
      }
    }
    case CardType::REMEDIES: {
      if (const auto remedyCard = std::dynamic_pointer_cast<Remedies>(playedCard))
        if (PlayRemedyCard(*remedyCard))
          return m_deck.RemoveCard(cardIndex);
    }
    case CardType::SAFETIES: {
      if (const auto safetyCard = std::dynamic_pointer_cast<Safeties>(playedCard))
        if (PlaySafetyCard(*safetyCard))
          return m_deck.RemoveCard(cardIndex);
    }
  }

  return false;
}

void Player::DisplayDeck(std::ostream &os, const size_t row) const {
  if (row < 5) {
    DisplayHazardsAndSafeties(os, row);
  } else {
    m_deck.DisplayCards(os, row - 5);
  }
}

void Player::DisplayHazardsAndSafeties(std::ostream &os, const size_t row) const {
  for (const auto &card: m_hazards)
    os << Utils::colorText(card.GetLine(row), Utils::Color::RED);
  for (const auto &card: m_safeties)
    os << Utils::colorText(card.GetLine(row), Utils::Color::BLUE);
}
