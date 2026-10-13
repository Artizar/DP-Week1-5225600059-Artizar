#ifndef STANDARD_RPS_RULES_H
#define STANDARD_RPS_RULES_H

#include "IEvaluationRule.h"

class StandardRPSRules : public IEvaluationRule {
public:
    Outcome evaluate(Move player, Move computer) override;
};

#endif
