#ifndef TWO_PAIR_CHECKER_H
#define TWO_PAIR_CHECKER_H
#include "PokerHandChecker.h"

class TwoPairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        auto counts = getvalueCounts(hand);
        int pairCount = 0;
        for (auto const& [val, count] : counts) {
            if (count == 2) pairCount++;
        }
        if (pairCount >= 2) return TWO_PAIR;
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
