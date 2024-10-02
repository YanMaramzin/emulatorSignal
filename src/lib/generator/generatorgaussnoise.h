#pragma once
#include "basegenerator.h"
#include <random>

namespace emulatorSignal {

class GeneratorGaussNoise : public BaseGenerator
{
public:
    GeneratorGaussNoise();
    ~GeneratorGaussNoise() override = default;

    void generate(CustomGeneratorParametrs &parameters) override;
    std::vector<double> &values() override;

private:
    std::vector<double> m_noise;
    std::mt19937 m_gen;
};

}
