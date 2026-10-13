#ifndef FIVE_OF_A_KIND_CHECKER_H
#define FIVE_OF_A_KIND_CHECKER_H
#include "PokerHandChecker.h"

class FiveOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        auto counts = getvalueCounts(hand);
        for (auto const& [val, count] : counts) {
            if (count >= 5) return FIVE_OF_A_KIND;
        }
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
