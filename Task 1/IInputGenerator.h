#ifndef I_INPUT_GENERATOR_H
#define I_INPUT_GENERATOR_H

#include "TurnInput.h"

class IInputGenerator {
public:
    virtual ~IInputGenerator() {}
    virtual TurnInput generateInput() = 0;
};

#endif