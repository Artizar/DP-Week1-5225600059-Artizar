#ifndef SCORING_RULE_H
#define SCORING_RULE_H

#include "Hand.h"

class ScoringRule {
public:
    ScoringRule() {}

    int convertRankToScore(HandRank rank) {
        switch (rank) {
            case FLUSH: return 50;
            case STRAIGHT: return 40;
            case HIGH_CARD: return 10;
            case ROYAL_FLUSH: return 100;
            case STRAIGHT_FLUSH: return 90;
            case FOUR_OF_A_KIND: return 85;
            case FULL_HOUSE: return 80;
            case THREE_OF_A_KIND: return 70;
            case TWO_PAIR: return 30;
            case PAIR: return 20;
            case FLUSH_HOUSE: return 80;
            case FIVE_OF_A_KIND: return 80;
            default: return 5;
        }
    }
};

#endif
//menentukan score dari rank

