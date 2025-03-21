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
protected:
  CardType m_type;
  std::vector<std::string> displayValue;

public:

  // Return the value of the n-th line in order to print a whole deck easily
  std::string getLine(int n) const;
};


