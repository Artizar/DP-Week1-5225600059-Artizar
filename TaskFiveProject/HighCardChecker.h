#ifndef HIGH_CARD_CHECKER_H
#define HIGH_CARD_CHECKER_H
#include "PokerHandChecker.h"

class HighCardChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        // Karena ini paling akhir dan tidak ada kombinasi lain, pasti High Card
        if (!hand.cards.empty()) return HIGH_CARD;

        if (nextChecker != nullptr) return nextChecker->check(hand);
        return UNKNOWN;
    }
};
#endif
