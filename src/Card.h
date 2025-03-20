#pragma once

#include <format>
#include <string>
#include <vector>
#include "CardDisplay.h"

enum class CardType {
  DISTANCE,
  HAZARDS,
  REMEDIES,
  SAFETIES
};

class Card {
private:
  static const CardType m_type;
  const std::vector<std::string_view> displayValue;

public:

  // Return the value of the n-th line in order to print a whole deck easily
  std::string_view getLine(int n) const;
};


