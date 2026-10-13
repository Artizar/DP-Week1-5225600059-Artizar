#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "HandGenerator.h"
#include "HandPlayer.h"
#include "ScoringRule.h"
#include "BlindRule.h"
#include "RewardRule.h"
#include "FlushChecker.h"
#include "StraightChecker.h"

class GameManager{
private:
    HandGenerator handGenerator;
    HandPlayer handPlayer;
    ScoringRule scoringRule;
    BlindRule blindRule;
    RewardRule rewardRule;
public:
    void runSession();
};

#endif // GAME_MANAGER_H
