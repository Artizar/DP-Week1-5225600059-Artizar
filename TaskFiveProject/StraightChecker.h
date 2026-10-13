#ifndef STRAIGHT_CHECKER_H
#define STRAIGHT_CHECKER_H
#include "PokerHandChecker.h"

class StraightChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        if (isStraight(hand)) return STRAIGHT;
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
//anak dari pokerhandchecker
