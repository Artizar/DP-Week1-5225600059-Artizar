#ifndef HAND_GENERATOR_H
#define HAND_GENERATOR_H

#include "Hand.h"

class HandGenerator{
public:
    Hand generateHand(){
    //dummy hand generation
    Hand h;
    h.cards.push_back({10,'S'});
    h.cards.push_back({11, 'S'});
    h.cards.push_back({12, 'S'});
    h.cards.push_back({13, 'S'});
    h.cards.push_back({14, 'S'});
    return h;
    }
};

#endif
