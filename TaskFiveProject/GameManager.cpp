#include "GameManager.h"
#include <iostream>

#include "RoyalFlushChecker.h"
#include "StraightFlushChecker.h"
#include "FlushHouseChecker.h"
#include "FiveOfAKindChecker.h"
#include "FourOfAKindChecker.h"
#include "FullHouseChecker.h"
#include "FlushChecker.h"
#include "StraightChecker.h"
#include "ThreeOfAKindChecker.h"
#include "TwoPairChecker.h"
#include "PairChecker.h"
#include "HighCardChecker.h"

using namespace std;

void GameManager::runSession() {
    cout << "=== BALATRO RUN START ===\n";

    // 1. Generate & Play Hand
    Hand myHand = handPlayer.playHand();
    cout << "[HAND] Cards dealt and played.\n";

    // 2. Setup Chain of Responsibility for Hand Checking
    RoyalFlushChecker royalFlush;
    StraightFlushChecker straightFlush;
    FlushHouseChecker flushHouse;
    FiveOfAKindChecker fiveOfAKind;
    FourOfAKindChecker fourOfAKind;
    FullHouseChecker fullHouse;
    FlushChecker flush;
    StraightChecker straight;
    ThreeOfAKindChecker threeOfAKind;
    TwoPairChecker twoPair;
    PairChecker pair;
    HighCardChecker highCard;

    royalFlush.setNext(&straightFlush);
    straightFlush.setNext(&flushHouse);
    flushHouse.setNext(&fiveOfAKind);
    fiveOfAKind.setNext(&fourOfAKind);
    fourOfAKind.setNext(&fullHouse);
    fullHouse.setNext(&flush);
    flush.setNext(&straight);
    straight.setNext(&threeOfAKind);
    threeOfAKind.setNext(&twoPair);
    twoPair.setNext(&pair);
    pair.setNext(&highCard);

    HandRank rank = royalFlush.check(myHand);
    string rankType;
    switch (rank) {
        case 9:
            rankType = "Royal Flush";
            break;
        case 8:
            rankType = "Straight Flush";
            break;
        case 7:
            rankType = "Four of a Kind";
            break;
        case 6:
            rankType = "Full House";
            break;
        case 5:
            rankType = "Flush";
            break;
        case 4:
            rankType = "Straight";
            break;
        case 3:
            rankType = "Three of a Kind";
            break;
        case 2:
            rankType = "Two Pair";
            break;
        case 1:
            rankType = "Pair";
            break;
        case 0:
            rankType = "High Card";
            break;
    }
    cout << "[CHECK] Hand Rank detected type ID: " << rankType << "\n";

    // 3. Compute Base Score
    int score = scoringRule.convertRankToScore(rank);
    cout << "[SCORE] Base score calculated: " << score << "\n";

    // 4. Check Blind
    bool win = blindRule.checkBlind(score);
    if (win) {
        cout << "[BLIND] Blind cleared successfully!\n";
    } else {
        cout << "[BLIND] Failed to clear blind.\n";
    }

    // 5. Earn Money / Rewards
    int moneyEarned = rewardRule.earnMoney(win, score);
    cout << "[REWARD] Earned money: $" << moneyEarned << "\n";

    cout << "=== BALATRO RUN END ===\n";
}

string y(HandRank rank) {
    string rankType;
    switch (rank) {
        case 9:
            rankType = "Royal Flush";
            break;
        case 8:
            rankType = "Straight Flush";
            break;
        case 7:
            rankType = "Four of a Kind";
            break;
        case 6:
            rankType = "Full House";
            break;
        case 5:
            rankType = "Flush";
            break;
        case 4:
            rankType = "Straight";
            break;
        case 3:
            rankType = "Three of a Kind";
            break;
        case 2:
            rankType = "Two Pair";
            break;
        case 1:
            rankType = "Pair";
            break;
        case 0:
            rankType = "High Card";
            break;
    }
    return rankType;
}
