#pragma once

#include <format>
#include <string>
#include <vector>

// static class with just two functions to create the appearance of cards
class CardDisplay {
private:
    static const std::string top;
    static const std::string empty;
    static const std::string bottom;
    static const int maxCharLength = 7;
public:
    static std::vector<std::string> constructCardDisplay(int distance);

    static std::vector<std::string_view> constructCardDisplay(std::string logo);
};
