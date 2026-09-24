#ifndef RUN_SESSION_H
#define RUN_SESSION_H

#include "IInputGenerator.h"
#include "IScoringRule.h"
#include "IRewardRule.h"
#include "ShopSystem.h"

class RunSession {
private:
    int money;
    int currentRound;
    IInputGenerator* inputGenerator;
    IScoringRule* scoringRule;
    IRewardRule* rewardRule;
    ShopSystem shop;

public:
    RunSession(IInputGenerator* inputGen, IScoringRule* scoreRule, IRewardRule* rewardR);
    void startRun();
};

#endif