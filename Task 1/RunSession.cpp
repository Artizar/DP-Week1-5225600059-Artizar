#include "RunSession.h"
#include <iostream>

using namespace std;

RunSession::RunSession(IInputGenerator* inputGen, IScoringRule* scoreRule, IRewardRule* rewardR)
    : money(0), currentRound(1), inputGenerator(inputGen), scoringRule(scoreRule), rewardRule(rewardR) {}

void RunSession::startRun() {
    cout << "=== RUN START ===\n";

    while (currentRound <= 3) {
        cout << "\nRound " << currentRound << "\n";

        // Phase 1: Generate input
        TurnInput input = inputGenerator->generateInput();
        cout << "[PLAY] input generated: " << input.value << "\n";

        // Phase 2: Compute base score
        int baseScore = scoringRule->calculateScore(input);
        cout << "[SCORE] base score: " << baseScore << "\n";

        // Phase 3: Compute reward
        int reward = rewardRule->calculateReward(baseScore, currentRound);

        // Phase 4: Update money
        money += reward;
        cout << "[REWARD] gain: " << reward << "  money: " << money << "\n";

        // Phase 5: Shop phase
        shop.showShop();

        // Phase 6: Advance round
        currentRound++;
    }

    cout << "\n=== RUN END ===\n";
    cout << "Final money: " << money << "\n";
}