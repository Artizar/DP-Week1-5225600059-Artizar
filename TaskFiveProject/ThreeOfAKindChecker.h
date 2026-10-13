#ifndef THREE_OF_A_KIND_CHECKER_H
#define THREE_OF_A_KIND_CHECKER_H
#include "PokerHandChecker.h"

class ThreeOfAKindChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        auto counts = getvalueCounts(hand);
        for (auto const& [val, count] : counts) {
            if (count == 3) return THREE_OF_A_KIND;
        }
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
