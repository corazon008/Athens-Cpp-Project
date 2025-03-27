#include "Player.h"

#include "../Cards/CardType/Distance.h"
#include "../Utils/Utils.h"

size_t Player::GetScore() const {
  return m_score;
}

size_t Player::GetId() const {
  return m_id;
}

bool Player::PlayDistanceCard(Distance& card) {
  for (const auto &hazard: m_hazards) {
    if (hazard.getHazardsType() == HazardsType::SPEED_LIMIT && card.GetDistance() > 50)
      return false;
    else if (hazard.getHazardsType() != HazardsType::None &&hazard.getHazardsType() != HazardsType::SPEED_LIMIT ) // All other hazards block the card
      return false;
  }
  m_score += card.GetDistance();
  return true;
}

bool Player::PlaySafetyCard(Safeties safety) {
  for (size_t i = 0; i < m_hazards.size(); i++)
    if (safety.CanCounterHazards(m_hazards[i]))
      m_hazards[i] = Hazards();

  for (size_t i = 0; i < m_safeties.size(); i++) {
    if (m_safeties[i].getSafetiesType() == SafetiesType::None) {
      m_safeties[i] = safety;
      return true;
    }
  }
  return false;
}

bool Player::PlayHazardCard(Hazards hazard, std::shared_ptr<Player>& opponent) {
  return opponent->ReceiveHazard(hazard);
}

bool Player::ReceiveHazard(Hazards hazard) {
  //TODO
  for (auto &f_hazard: m_hazards) {
    if (f_hazard.getHazardsType() != HazardsType::None)
      continue;
    f_hazard = hazard;
    return true;
  }
  return false;
}

bool Player::PlayRemedyCard(Remedies remedies) {
  //TODO
  for (auto &hazard: m_hazards) {
    if (remedies.canCounterHazards(hazard)) {
      hazard = Hazards();
      return true;
    }
  }
  return false;
}

bool Player::DrawCard(const std::shared_ptr<Card> card) {
  m_deck.AddCard(card);
  return true;
}

bool Player::PlayCard(const size_t cardIndex, Game *game) {
  std::shared_ptr<Card> playedCard = m_deck.GetCard(cardIndex);

  if (!playedCard) return false; // Vérifier que la carte existe

  switch (playedCard->getType()) {
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

  return false; // Si aucune carte valide n'a été jouée
}


void Player::DisplayDeck(std::ostream &os, const size_t row) const {
  if (row < 5) {
    DisplayHazardsNSafeties(os, row);
  } else {
    m_deck.DisplayCards(os, row - 5);
  }
}

void Player::DisplayHazardsNSafeties(std::ostream &os, const size_t row) const {
  for (const auto &card: m_hazards)
    os << Utils::colorText(card.getLine(row), Utils::Color::RED);
  for (const auto &card: m_safeties)
    os << Utils::colorText(card.getLine(row), Utils::Color::BLUE);
}
