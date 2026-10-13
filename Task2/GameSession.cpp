#include "GameSession.h"
#include <iostream>

using namespace std;

GameSession::GameSession(IRivalStrategy* r, IEvaluationRule* e, int rounds)
    : playerScore(0), computerScore(0), currentRound(1), maxRounds(rounds), rival(r), rules(e) {}

string GameSession::moveToString(Move m) {
    if (m == ROCK) return "Rock";
    if (m == PAPER) return "Paper";
    if (m == SCISSORS) return "Scissors";
    return "Unknown";
}

void GameSession::startGame() {
    cout << "=== ROCK PAPER SCISSORS GAME START ===\n";

    while (currentRound <= maxRounds) {
        cout << "\n--- Round " << currentRound << " ---\n";

        // Phase 1: Player Choice (Skeleton Placeholder)
        Move playerMove = ROCK;
        cout << "[PLAYER] Chose: " << moveToString(playerMove) << "\n";

        // Phase 2: Computer Choice
        Move computerMove = rival->getComputerMove();
        cout << "[COMPUTER] Chose: " << moveToString(computerMove) << "\n";

        // Phase 3: System Resolves Outcome
        Outcome result = rules->evaluate(playerMove, computerMove);

        // Phase 4: State Update
        if (result == PLAYER_WIN) {
            playerScore++;
            cout << "[RESULT] Player wins round!\n";
        } else if (result == COMPUTER_WIN) {
            computerScore++;
            cout << "[RESULT] Computer wins round!\n";
        } else {
            cout << "[RESULT] Draw!\n";
        }

        cout << "[SCORE] Player: " << playerScore << " | Computer: " << computerScore << "\n";

        // Phase 5: Advance Round
        currentRound++;
    }

    cout << "\n=== GAME OVER ===\n";
    cout << "Final Score - Player: " << playerScore << " | Computer: " << computerScore << "\n";
}
