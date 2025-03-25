#include "Player.h"

#include "../Cards/CardType/Distance.h"

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

bool Player::PlayHazardCard(Hazards hazard, Player& opponent) {
  //TODO
  return false;
}

bool Player::PlayRemedyCard(Remedies remedies, Player& opponent) {
  //TODO
  return false;
}

bool Player::DrawCard(const std::shared_ptr<Card> card) {
  m_deck.AddCard(card);
  return true;
}

bool Player::PlayCard(int cardIndex, Player& opponent) {
  std::shared_ptr<Card> playedCard = m_deck.GetCard(cardIndex);

  if (!playedCard) return false; // Vérifier que la carte existe

  switch (playedCard->getType()) {
    case CardType::DISTANCE: {
      auto distCard = std::dynamic_pointer_cast<Distance>(playedCard);
      if (distCard) return PlayDistanceCard(*distCard);
      break;
    }
    case CardType::HAZARDS: {
      auto hazardCard = std::dynamic_pointer_cast<Hazards>(playedCard);
      if (hazardCard) return PlayHazardCard(*hazardCard, opponent);
      break;
    }
    case CardType::REMEDIES: {
      auto remedyCard = std::dynamic_pointer_cast<Remedies>(playedCard);
      if (remedyCard) return PlayRemedyCard(*remedyCard, opponent);
      break;
    }
    case CardType::SAFETIES: {
      auto safetyCard = std::dynamic_pointer_cast<Safeties>(playedCard);
      if (safetyCard) return PlaySafetyCard(*safetyCard);
      break;
    }
  }

  return false; // Si aucune carte valide n'a été jouée
}



bool Player::ReceiveHazard(Hazards hazard) {
  //TODO
  return false;
}

