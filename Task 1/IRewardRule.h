#ifndef I_REWARD_RULE_H
#define I_REWARD_RULE_H

class IRewardRule {
public:
    virtual ~IRewardRule() {}
    virtual int calculateReward(int baseScore, int currentRound) = 0;
};

#endif