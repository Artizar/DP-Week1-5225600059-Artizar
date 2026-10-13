#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <string>
#include "IRivalStrategy.h"
#include "IEvaluationRule.h"

class GameSession {
private:
    int playerScore;
    int computerScore;
    int currentRound;
    int maxRounds;
    IRivalStrategy* rival;
    IEvaluationRule* rules;

    std::string moveToString(Move m);

public:
    GameSession(IRivalStrategy* r, IEvaluationRule* e, int rounds = 3);
    void startGame();
};

#endif
