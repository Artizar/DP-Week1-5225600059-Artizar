#ifndef FLUSH_HOUSE_CHECKER_H
#define FLUSH_HOUSE_CHECKER_H
#include "PokerHandChecker.h"

class FlushHouseChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        if (isFlush(hand)) {
            auto counts = getvalueCounts(hand);
            bool hasThree = false, hasPair = false;
            for (auto const& [val, count] : counts) {
                if (count == 3) hasThree = true;
                if (count == 2) hasPair = true;
            }
            if (hasThree && hasPair) return FLUSH_HOUSE;
        }
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
