#ifndef FOUR_OF_A_KIND_CHECKER_H
#define FOUR_OF_A_KIND_CHECKER_H
#include "PokerHandChecker.h"

class FourOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        auto counts = getvalueCounts(hand);
        for (auto const& [val, count] : counts) {
            if (count == 4) return FOUR_OF_A_KIND;
        }
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
