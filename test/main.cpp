#include <iostream>
#include <cassert>
#include "CardDisplayTest.cpp"
#include "../src/Utils/Utils.h"

using namespace std;
int main() {

    assert(Utils::GetIntLength(1) == 1);
    assert(Utils::GetIntLength(0) == 1);
    assert(Utils::GetIntLength(5) == 1);
    assert(Utils::GetIntLength(25) == 2);
    assert(Utils::GetIntLength(100) == 3);
    assert(Utils::GetIntLength(999) == 3);

    assert(Utils::GetNthDigit(1, 0) == 1);
    try {
        assert(Utils::GetNthDigit(1, 1) == 0);
    }catch (std::invalid_argument& e) {}
    assert(Utils::GetNthDigit(25, 0) == 2);
    assert(Utils::GetNthDigit(25, 1) == 5);
    try {
        assert(Utils::GetNthDigit(25, 2) == 0);
    }catch (std::invalid_argument& e) {}
    CardDisplayTest::constructCardDisplay();

    displayCard(Utils::NumberToStringList(1234567890));

    return 0;
}