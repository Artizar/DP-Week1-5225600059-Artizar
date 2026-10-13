#include "StandardRPSRules.h"

Outcome StandardRPSRules::evaluate(Move player, Move computer) {
    if (player == computer) return DRAW;
    if ((player == ROCK && computer == SCISSORS) ||
        (player == PAPER && computer == ROCK) ||
        (player == SCISSORS && computer == PAPER)) {
        return PLAYER_WIN;
    }
    return COMPUTER_WIN;
}
