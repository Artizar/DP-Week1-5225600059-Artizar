#ifndef RANDOM_RIVAL_STRATEGY_H
#define RANDOM_RIVAL_STRATEGY_H

#include "IRivalStrategy.h"

class RandomRivalStrategy : public IRivalStrategy {
public:
    RandomRivalStrategy();
    Move getComputerMove() override;
};

#endif
