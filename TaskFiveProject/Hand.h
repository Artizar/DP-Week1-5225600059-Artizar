#ifndef HAND_H
#define HAND_H

#include <vector>

enum HandRank {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH,
    FIVE_OF_A_KIND,
    FLUSH_HOUSE,
    UNKNOWN
};

struct Card {
    int value;
    char suit; // 'H', 'D', 'C', 'S'
};

struct Hand {
    std::vector<Card> cards;
};

#endif
