#pragma once

#include <format>
#include <string>
#include <vector>

// static class with just two functions to create the appearance of cards
class CardDisplay {
private:
    static constexpr std::string_view top    = "┌───────┐";
    static constexpr std::string_view empty  = "│       │";
    static constexpr std::string_view bottom = "└───────┘";
    static const int maxCharLength = 7;
public:
    static std::vector<std::string_view> constructCardDisplay(int speed);

    static std::vector<std::string_view> constructCardDisplay(std::string logo);
};
