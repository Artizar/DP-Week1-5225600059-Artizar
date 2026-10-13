#ifndef HAND_PLAYER_H
#define HAND_PLAYER_H

#include "Hand.h"

class HandPlayer {
public:
    Hand playHand() {
        HandGenerator generator;
        return generator.generateHand();
    }
};

#endif
//kartu yang akan muncul di tangan player
