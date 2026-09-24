#ifndef FIXED_INPUT_GENERATOR_H
#define FIXED_INPUT_GENERATOR_H

#include "IInputGenerator.h"

class FixedInputGenerator : public IInputGenerator {
public:
    TurnInput generateInput() override {
        return TurnInput{ 3 };
    }
};

#endif