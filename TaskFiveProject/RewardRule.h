#ifndef REWARD_RULE_H
#define REWARD_RULE_H

class RewardRule{
public:
    int earnMoney(bool win, int score){
    if (win){
        return 5 + (score/10);
    }
    return 0;
    }
};

#endif // REWARD_RULE_H
//hitung total uang dari score
