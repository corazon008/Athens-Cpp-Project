#include "Utils.h"

#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <iostream>
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
            throw std::invalid_argument("digit out of range");
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
        throw std::invalid_argument("digit out of range");
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

    int AskInt(const std::string &message) {
        int nombre;

        while (true) {
            std::cout << message;
            std::cin >> nombre;

            if (std::cin.fail()) {
                std::cin.clear(); // Réinitialise l'état d'erreur
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Vide le buffer d'entrée
                std::cout << "Error. Please enter an integer !\n";
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Nettoie l'entrée
                return nombre;
            }
        }
    }

    bool AskYesNo(const std::string& question, bool defaultValue) {
        std::string response;

        while (true) {
            std::cout << question;
            std::getline(std::cin, response);

            // Convert to lowercase
            std::transform(response.begin(), response.end(), response.begin(), tolower);

            if (response == std::string(""))
                return defaultValue;
            if (response == "yes" || response == "y")
                return true;
            if (response == "no" || response == "n")
                return false;

            std::cout << "Invalid input. Please answer 'yes' or 'no'."  << std::endl;
        }
    }
}
