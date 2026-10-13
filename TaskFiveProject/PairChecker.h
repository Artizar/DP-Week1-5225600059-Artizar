#ifndef PAIR_CHECKER_H
#define PAIR_CHECKER_H
#include "PokerHandChecker.h"

class PairChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        auto counts = getvalueCounts(hand);
        for (auto const& [val, count] : counts) {
            if (count == 2) return PAIR;
        }
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
