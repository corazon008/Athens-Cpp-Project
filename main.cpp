#include <iostream>
#include "src/CardType/Distance.cpp"
#include <vector>


using namespace std;
int main() {

    //create deck
    std:vector<Card> cards;
    for (int i = 0; i < 10; i++) {
        cards.push_back(Distance(25));
        cards.push_back(Distance(50));
        cards.push_back(Distance(75));
    }
    for (int i = 0; i < 12; i++) {
        cards.push_back(Distance(100));
    }
    for (int i = 0; i < 4; i++) {
        cards.push_back(Distance(200));
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < cards.size(); j++) {
            cout << cards[j].getLine(i) << "\t";
        }
        cout << endl;
    }

    return 0;
}