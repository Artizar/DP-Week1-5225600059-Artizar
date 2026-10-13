#ifndef ROYAL_FLUSH_CHECKER_H
#define ROYAL_FLUSH_CHECKER_H
#include "PokerHandChecker.h"

class RoyalFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        if (isFlush(hand) && isStraight(hand)) {
            // Cek apakah nilai tertingginya Ace (14) dan dimulai dari 10
            int minVal = 14;
            for (const auto& c : hand.cards) if (c.value < minVal) minVal = c.value;
            if (minVal == 10) return ROYAL_FLUSH;
        }
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
