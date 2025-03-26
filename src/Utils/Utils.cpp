#include "Utils.h"
#include <stdexcept>
#include <cmath>
#include <vector>

namespace Number {
    const std::vector<std::string> ONE = {
        "   ┐   ",
        "   │   ",
        "   │   ",
        "   │   ",
        "   ┴   ",
    };

    const std::vector<std::string> TWO = {
        "────┐  ",
        "    │  ",
        "┌───┘  ",
        "│      ",
        "└────  ",
    };

    const std::vector<std::string> THREE = {
        "────┐  ",
        "    │  ",
        "────┤  ",
        "    │  ",
        "────┘  ",
    };

    const std::vector<std::string> FOUR = {
        "┬   ┬  ",
        "│   │  ",
        "└───┤  ",
        "    │  ",
        "    ┴  ",
    };

    const std::vector<std::string> FIVE = {
        "┌────  ",
        "│      ",
        "└───┐  ",
        "    │  ",
        "────┘  ",
    };

    const std::vector<std::string> SIX = {
        "┌─────  ",
        "│       ",
        "├────┐  ",
        "│    │  ",
        "└────┘  ",
    };

    const std::vector<std::string> SEVEN = {
        "────┐  ",
        "    │  ",
        "    │  ",
        "    │  ",
        "    ┴  ",
    };

    const std::vector<std::string> EIGHT = {
        "┌────┐  ",
        "│    │  ",
        "├────┤  ",
        "│    │  ",
        "└────┘  ",
    };

    const std::vector<std::string> NINE = {
        "┌────┐  ",
        "│    │  ",
        "└────┤  ",
        "     │  ",
        "─────┘  ",
    };

    const std::vector<std::string> ZERO = {
        "┌────┐ ",
        "│    │ ",
        "│    │ ",
        "│    │ ",
        "└────┘ ",
    };
}

namespace Utils {
    std::string colorText(const std::string text, Color color = Color::RESET) {
        return "\033[" + std::to_string(static_cast<int>(color)) + "m" + text + "\033[0m";
    }

    std::vector<std::string> DigitToStringList(const unsigned int d) {
        if (d > 9)
            throw std::invalid_argument("score out of range");
        switch (d) {
            case 0:
                return Number::ZERO;
            case 1:
                return Number::ONE;
            case 2:
                return Number::TWO;
            case 3:
                return Number::THREE;
            case 4:
                return Number::FOUR;
            case 5:
                return Number::FIVE;
            case 6:
                return Number::SIX;
            case 7:
                return Number::SEVEN;
            case 8:
                return Number::EIGHT;
            case 9:
                return Number::NINE;
        }
    };

    std::string DigitToStringListRow(const unsigned int d, const size_t row) {
        return DigitToStringList(d)[row];
    };

    unsigned int GetIntLength(const unsigned int n) {
        if (n == 0)
            return 1;
        return floor(log10(n)) + 1;
    };

    unsigned int GetNthDigit(const unsigned int n, const unsigned int digit) {
        if (digit >= GetIntLength(n))
            throw std::invalid_argument("digit out of range");
        auto t_digit = GetIntLength(n) - digit - 1;
        auto f = static_cast<unsigned int>(pow(10, t_digit));
        auto temp = (n / f) % 10;
        return temp;
    };

    std::vector<std::string> NumberToStringList(const unsigned int n) {
        std::vector<std::string> result = {
            "",
            "",
            "",
            "",
            "",
        };
        for (size_t j = 0; j < 5; j++) {
            for (size_t i = 0; i < GetIntLength(n); i++) {
                auto current_digit = GetNthDigit(n, i);
                result[j] += DigitToStringListRow(current_digit, j);
            }
        }
        return result;
    };
}
