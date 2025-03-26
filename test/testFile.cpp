#include <iostream>
#include <thread>
#include <chrono>


#include <iostream>
#include <chrono>
#include <thread>

enum class Color {
    RESET = 0, BLACK = 30, RED = 31, GREEN = 32, YELLOW = 33,
    BLUE = 34, MAGENTA = 35, CYAN = 36, WHITE = 37
};

std::string colorText(const std::string &text, Color color = Color::RESET) {
    return "\033[" + std::to_string(static_cast<int>(color)) + "m" + text + "\033[0m";
}

int main() {
    // Affiche du texte initial
    std::cout << colorText("Hello World", Color::RED) << std::endl;

    return 0;
}

