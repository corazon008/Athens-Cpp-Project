#include <iostream>
#include <cassert>
#include "CardDisplayTest.cpp"
#include "../src/const.h"

using namespace std;
int main() {

    assert(GetIntLength(1) == 1);
    assert(GetIntLength(0) == 1);
    assert(GetIntLength(5) == 1);
    assert(GetIntLength(25) == 2);
    assert(GetIntLength(100) == 3);
    assert(GetIntLength(999) == 3);

    assert(GetNthDigit(1, 0) == 1);
    try {
        assert(GetNthDigit(1, 1) == 0);
    }catch (std::invalid_argument& e) {}
    assert(GetNthDigit(25, 0) == 2);
    assert(GetNthDigit(25, 1) == 5);
    try {
        assert(GetNthDigit(25, 2) == 0);
    }catch (std::invalid_argument& e) {}
    CardDisplayTest::constructCardDisplay();

    displayCard(NumberToStringList(1234567890));

    return 0;
}