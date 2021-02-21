#include "random_gen.h"

int Random::getInt(int start, int end)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(start, end);

    return distrib(gen);
}

