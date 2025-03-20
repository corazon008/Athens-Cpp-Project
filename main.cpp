#include <iostream>
#include "src/Card.h"

using namespace std;
int main() {

    Card card = {100};

    for (int i = 0; i <= 4; i++) {
        cout << card.getLine(i) << endl;
    }

    return 0;
}