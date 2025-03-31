#pragma once

#include <string>
#include <vector>

enum class CardType {
  DISTANCE,
  HAZARDS,
  REMEDIES,
  SAFETIES
};

// Card base class
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

  // Return the value of the n-th line of a card to print a whole deck easier
  virtual std::string GetLine(size_t n) const;

  virtual CardType GetType() const = 0;
};


