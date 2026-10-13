#include "RandomRivalStrategy.h"
#include <cstdlib>
#include <ctime>

RandomRivalStrategy::RandomRivalStrategy() {
    std::srand(std::time(0));
}

Move RandomRivalStrategy::getComputerMove() {
    return static_cast<Move>(std::rand() % 3);
}
