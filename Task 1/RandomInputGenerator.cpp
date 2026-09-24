#include "RandomInputGenerator.h"
#include <cstdlib>
#include <ctime>

RandomInputGenerator::RandomInputGenerator() {
    std::srand(std::time(0));
}

TurnInput RandomInputGenerator::generateInput() {
    return TurnInput{ (std::rand() % 5) + 1 };
}