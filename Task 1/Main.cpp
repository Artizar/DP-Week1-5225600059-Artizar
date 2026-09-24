#include "RandomInputGenerator.h"
#include "SimpleScoringRule.h"
#include "ModifiedRewardRule.h"
#include "RunSession.h"

int main() {
    // 1. Instantiate concrete implementations
    RandomInputGenerator inputGen;
    SimpleScoringRule scoreRule;
    ModifiedRewardRule rewardRule;

    // 2. Inject dependencies into RunSession
    RunSession run(&inputGen, &scoreRule, &rewardRule);

    // 3. Start the run
    run.startRun();

    return 0;
}
