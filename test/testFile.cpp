#include <iostream>
#include <string>

int main() {
    std::string letter = "[→]";  // UTF-8 encoded
    for (char c : letter) {
        std::cout << c << ' ';
    }
    return 0;
}
