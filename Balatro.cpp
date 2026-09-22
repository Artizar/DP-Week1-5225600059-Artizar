#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ==========================================
// 1. INTERFACES & DATA TYPES
// ==========================================

struct TurnInput {
    int value;
};

// Interface for generating input
class IInputGenerator {
public:
    virtual ~IInputGenerator() {}
    virtual TurnInput generateInput() = 0;
};

// Interface for scoring
class IScoringRule {
public:
    virtual ~IScoringRule() {}
    virtual int calculateScore(const TurnInput& input) = 0;
};

// Interface for rewards
class IRewardRule {
public:
    virtual ~IRewardRule() {}
    virtual int calculateReward(int baseScore, int currentRound) = 0;
};

// ==========================================
// 2. CONCRETE IMPLEMENTATIONS (MUTABLE PARTS)
// ==========================================

// Initial Input Generator (Fixed/Simple)
class FixedInputGenerator : public IInputGenerator {
public:
    TurnInput generateInput() override {
        return TurnInput{ 3 }; // Always returns 3 for simplicity
    }
};

// Modification 1: Random Input Generator
class RandomInputGenerator : public IInputGenerator {
public:
    RandomInputGenerator() {
        srand(time(0)); // Seed random number generator
    }
    TurnInput generateInput() override {
        return TurnInput{ (rand() % 5) + 1 }; // Random number between 1 and 5
    }
};

// Simple Scoring Rule
class SimpleScoringRule : public IScoringRule {
public:
    int calculateScore(const TurnInput& input) override {
        return input.value; // Base score equals input value
    }
};

// Modification 2: Custom Reward Rule
class ModifiedRewardRule : public IRewardRule {
public:
    int calculateReward(int baseScore, int currentRound) override {
        // Example logic: Base score + 2 bonus money
        return baseScore + 2;
    }
};

// Shop System
class ShopSystem {
public:
    void showShop() {
        cout << "[SHOP] offered: Bonus (+2) cost 2\n";
        cout << "[SHOP] skipped\n";
    }
};

// ==========================================
// 3. RUN SESSION (INVARIANT CORE LOOP)
// ==========================================

class RunSession {
private:
    int money;
    int currentRound;
    IInputGenerator* inputGenerator;
    IScoringRule* scoringRule;
    IRewardRule* rewardRule;
    ShopSystem shop;

public:
    RunSession(IInputGenerator* inputGen, IScoringRule* scoreRule, IRewardRule* rewardR)
        : money(0), currentRound(1), inputGenerator(inputGen), scoringRule(scoreRule), rewardRule(rewardR) {}

    void startRun() {
        cout << "=== RUN START ===\n";

        while (currentRound <= 3) { // Run exactly 3 rounds
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
};

// ==========================================
// 4. MAIN FUNCTION
// ==========================================

int main() {
    // 1. Instantiate concrete implementations
    RandomInputGenerator inputGen;   // Modification 1 applied here
    SimpleScoringRule scoreRule;
    ModifiedRewardRule rewardRule;   // Modification 2 applied here

    // 2. Inject dependencies into RunSession
    RunSession run(&inputGen, &scoreRule, &rewardRule);

    // 3. Start the run
    run.startRun();

    return 0;
}
