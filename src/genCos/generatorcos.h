#pragma once

#include <vector>

class GeneratorCos
{
public:
    GeneratorCos();
    ~GeneratorCos() = default;

    std::vector<double> gen(double frequency, double amplitude);

};
