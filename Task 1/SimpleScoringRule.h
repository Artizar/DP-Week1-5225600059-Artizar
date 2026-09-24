#ifndef SIMPLE_SCORING_RULE_H
#define SIMPLE_SCORING_RULE_H

#include "IScoringRule.h"

class SimpleScoringRule : public IScoringRule {
public:
    int calculateScore(const TurnInput& input) override {
        return input.value;
    }
};

#endif