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
  std::vector<std::string> displayValue = {
    "┌───────┐",
    "│       │",
    "│       │",
    "│       │",
    "└───────┘"
  };

public:
  static std::vector<std::string> EmptyCard;

  virtual ~Card() = default;

  // Return the value of the n-th line in order to print a whole deck easily
  virtual std::string getLine(size_t n) const;

  virtual CardType getType() const = 0;
};


