#pragma once

#include <string>
#include <vector>

namespace Utils {
    enum class Color {
        RESET = 0, BLACK = 30, RED = 31, GREEN = 32, YELLOW = 33,
        BLUE = 34, MAGENTA = 35, CYAN = 36, WHITE = 37
    };

    std::string colorText(const std::string& text, Color color);

    // Return a list of string representing the digit with characters (5 lines height)
    std::vector<std::string> DigitToStringList(const unsigned int d);

    // Use DigitToStringList and return a specific row
    std::string DigitToStringListRow(const unsigned int d, const size_t row);

    // Get the length of an integer (number of digits)
    unsigned int GetIntLength(const unsigned int n);

    unsigned int GetNthDigit(const unsigned int n, const unsigned int digit);

    std::vector<std::string> NumberToStringList(const unsigned int n);

    // Ask the user for an integer input with a message
    int AskInt(const std::string& message);

    // Ask the user for a boolean input with a message
    bool AskYesNo(const std::string& question, bool defaultValue = false);
}
