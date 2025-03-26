#include "Player.h"

#include "../Cards/CardType/Distance.h"
#include "../Utils/Utils.h"

size_t Player::GetScore() const {
  return m_score;
}

bool Player::PlayDistanceCard(Distance card) {
  m_score += card.GetDistance();
  return true;
}

bool Player::PlaySafetyCard(Safeties safety) {
  //TODO
  return false;
}

bool Player::PlayHazardCard(Hazards hazard, Player &opponent) {
  //TODO
  return false;
}

bool Player::PlayRemedyCard(Remedies remedies, Player &opponent) {
  //TODO
  return false;
}

bool Player::DrawCard(const std::shared_ptr<Card> card) {
  m_deck.AddCard(card);
  return true;
}

bool Player::PlayCard(const size_t cardIndex, Player &opponent) {
  std::shared_ptr<Card> playedCard = m_deck.GetCard(cardIndex);

  if (!playedCard) return false; // Vérifier que la carte existe

  switch (playedCard->getType()) {
    case CardType::DISTANCE: {
      if (const auto distCard = std::dynamic_pointer_cast<Distance>(playedCard))
        return PlayDistanceCard(*distCard);
      break;
    }
    case CardType::HAZARDS: {
      if (const auto hazardCard = std::dynamic_pointer_cast<Hazards>(playedCard))
        return PlayHazardCard(*hazardCard, opponent);
      break;
    }
    case CardType::REMEDIES: {
      if (const auto remedyCard = std::dynamic_pointer_cast<Remedies>(playedCard))
        return PlayRemedyCard(*remedyCard, opponent);
      break;
    }
    case CardType::SAFETIES: {
      if (const auto safetyCard = std::dynamic_pointer_cast<Safeties>(playedCard))
        return PlaySafetyCard(*safetyCard);
      break;
    }
  }

  return false; // Si aucune carte valide n'a été jouée
}

bool Player::ReceiveHazard(Hazards hazard) {
  //TODO
  return false;
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
