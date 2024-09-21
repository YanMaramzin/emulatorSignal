#include "generatorcos.h"
#include <cmath>

std::vector<double> GeneratorCos::gen(double frequency, double amplitude)
{
    std::vector<double> result;
    for (int i = 0; i < 1000; i++)
        result.push_back(amplitude * cos(2 * M_PI * frequency * i / 1000));
    return result;
}
