#ifndef I_SCORING_RULE_H
#define I_SCORING_RULE_H

#include "TurnInput.h"

class IScoringRule {
public:
    virtual ~IScoringRule() {}
    virtual int calculateScore(const TurnInput& input) = 0;
};

#endif