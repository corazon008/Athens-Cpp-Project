#include <iostream>
#include <cassert>
#include "CardDisplayTest.cpp"
#include "../src/Utils/Utils.h"
#include "../src/Cards/CardType/Hazards.h"
#include "../src/Cards/CardType/Safeties.h"
#include "../src/Cards/CardType/Distance.h"
#include "../src/Cards/CardType/Remedies.h"
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
    for (const auto type : {HazardsType::ACCIDENT, HazardsType::OUT_OF_GAS,HazardsType::FLAT_TIRE, HazardsType::STOP, HazardsType::SPEED_LIMIT}) {
        displayCard(CardDisplay::constructCardDisplay(hazardSymbols[type], hazardSymbolsLetter[type]), Utils::Color::RED);
    }

    for (const auto type : {SafetiesType::DRIVING_ACE, SafetiesType::EXTRA_TANK, SafetiesType::PUNCTURE_PROOF, SafetiesType::RIGHT_OF_WAY}) {
        displayCard(CardDisplay::constructCardDisplay(safetySymbols[type], safetySymbolsLetter[type]), Utils::Color::BLUE);
    }

    for (const auto type : {RemediesType::REPAIRS, RemediesType::GASOLINE, RemediesType::SPARE_TIRE, RemediesType::GO, RemediesType::END_LIMIT}) {
        displayCard(CardDisplay::constructCardDisplay(remedySymbols[type], remedySymbolsLetter[type]), Utils::Color::GREEN);
    }

    return 0;
}