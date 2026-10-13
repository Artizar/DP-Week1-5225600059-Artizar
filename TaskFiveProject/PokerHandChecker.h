#ifndef POKER_HAND_CHECKER_H
#define POKER_HAND_CHECKER_H

#include "Hand.h"
#include <vector>
#include <map>         // <--- Added this for std::map
#include <algorithm>

class PokerHandChecker {
protected:
    PokerHandChecker* nextChecker;

public:
    PokerHandChecker() : nextChecker(nullptr) {}
    virtual ~PokerHandChecker() {}

    void setNext(PokerHandChecker* next) {
        nextChecker = next;
    }

    virtual HandRank check(const Hand& hand) = 0;

protected:
    // Helper untuk mengecek apakah hand adalah Flush
    bool isFlush(const Hand& hand) {
        if (hand.cards.empty()) return false;
        char firstSuit = hand.cards[0].suit;
        for (size_t i = 1; i < hand.cards.size(); ++i) {
            if (hand.cards[i].suit != firstSuit) return false;
        }
        return true;
    }

    // Helper untuk mengecek apakah hand adalah Straight
    bool isStraight(const Hand& hand) {
        if (hand.cards.size() < 5) return false;
        std::vector<int> vals;
        for (const auto& c : hand.cards) vals.push_back(c.value);
        std::sort(vals.begin(), vals.end());

        // Cek straight normal
        bool sequential = true;
        for (size_t i = 0; i < vals.size() - 1; ++i) {
            if (vals[i + 1] != vals[i] + 1) {
                sequential = false;
                break;
            }
        }
        if (sequential) return true;

        // Cek special case A-2-3-4-5 (Ace dianggap 1)
        if (vals == std::vector<int>{2, 3, 4, 5, 14}) return true;

        return false;
    }

    // Helper mendapatkan peta frekuensi nilai kartu
    std::map<int, int> getvalueCounts(const Hand& hand) {
        std::map<int, int> counts;
        for (const auto& c : hand.cards) {
            counts[c.value]++;
        }
        return counts;
    }
};

#endif
// base untk ngecheck kartu
