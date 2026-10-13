#ifndef I_RIVAL_STRATEGY_H
#define I_RIVAL_STRATEGY_H

#include "GameEnums.h"

class IRivalStrategy {
public:
    virtual ~IRivalStrategy() {}
    virtual Move getComputerMove() = 0;
};

#endif
