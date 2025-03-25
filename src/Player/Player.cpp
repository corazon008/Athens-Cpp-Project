#include "Player.h"

int Player::GetScore() const {
  return m_score;
}

bool Player::PlayDistanceCard(int distance) {
  //TODO
}

bool Player::PlaySafetyCard(Safeties safety) {
  //TODO
}

bool Player::PlayHazardCard(Hazards hazard, Player& opponent) {
  //TODO
}

bool Player::PlayRemedyCard(Hazards hazard, Player& opponent) {
  //TODO
}

bool Player::DrawCard(Card& card) {
  m_deck.AddCard(card);
  return true;
}

bool Player::PlayCard(int cardIndex, Player& opponent) {
  //TODO
}

bool Player::ReceiveHazard(Hazards hazard) {
  //TODO
}

