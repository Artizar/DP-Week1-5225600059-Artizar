#ifndef I_EVALUATION_RULE_H
#define I_EVALUATION_RULE_H

#include "GameEnums.h"

class IEvaluationRule {
public:
    virtual ~IEvaluationRule() {}
    virtual Outcome evaluate(Move player, Move computer) = 0;
};

#endif
