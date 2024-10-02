#include <random>
#include "generatorgaussnoise.h"

namespace emulatorSignal {

GeneratorGaussNoise::GeneratorGaussNoise()
{
    std::random_device rd;
    m_gen.seed(rd());
}
void GeneratorGaussNoise::generate(CustomGeneratorParametrs &)
{
    std::normal_distribution<double> distribution(0.0, 5.0);
    m_noise.clear();
    for (int i = 0; i < 100; ++i) {
        const auto number = distribution(m_gen);
        m_noise.push_back(number);
    }
}

std::vector<double> &GeneratorGaussNoise::values()
{
    return m_noise;
}

}
