#include "../Card.h"
#include "../CardDisplay.h"

class Distance : public Card {
private:
    int m_distance;

public:
    Distance(int distance): m_distance(distance) {
        m_type = CardType::DISTANCE;
        displayValue = CardDisplay::constructCardDisplay(distance);
    };
};
