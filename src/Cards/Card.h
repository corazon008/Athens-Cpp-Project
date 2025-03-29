#pragma once

#include <string>
#include <vector>

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
  virtual std::string GetLine(size_t n) const;

  virtual CardType GetType() const = 0;
};


