#ifndef BLIND_RULE_H
#define BLIND_RULE_H

class BlindRule {
public:
    bool checkBlind(int score) {
        int blindRequirement = 30; // Target score to beat
        return score >= blindRequirement;
    }
};

#endif
// minimal score harus didapat
