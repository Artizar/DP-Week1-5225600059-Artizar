#ifndef FLUSH_CHECKER_H
#define FLUSH_CHECKER_H
#include "PokerHandChecker.h"

class FlushChecker : public PokerHandChecker {
public:
    HandRank check(const Hand& hand) override {
        if (isFlush(hand)) return FLUSH;
        if (nextChecker != nullptr) return nextChecker->check(hand);
        return HIGH_CARD;
    }
};
#endif
//anak dari pokerhandchecker
