#ifndef STRAIGHT_FLUSH_CHECKER_H
#define STRAIGHT_FLUSH_CHECKER_H
#include "PokerHandChecker.h"

class StraightFlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        if (isFlush(hand) && isStraight(hand)) {
            return STRAIGHT_FLUSH;
        }
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
