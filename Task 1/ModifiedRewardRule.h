#ifndef MODIFIED_REWARD_RULE_H
#define MODIFIED_REWARD_RULE_H

#include "IRewardRule.h"

class ModifiedRewardRule : public IRewardRule {
public:
    int calculateReward(int baseScore, int currentRound) override {
        return baseScore + 2;
    }
};

#endif