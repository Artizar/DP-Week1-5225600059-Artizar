#include "RandomRivalStrategy.h"
#include "StandardRPSRules.h"
#include "GameSession.h"

int main() {
    RandomRivalStrategy randomRival;
    StandardRPSRules standardRules;

    // Inject dependencies into GameSession
    GameSession session(&randomRival, &standardRules, 3);
    session.startGame();

    return 0;
}
