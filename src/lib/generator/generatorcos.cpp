#include "generatorcos.h"
#include <cmath>

namespace emulatorSignal {

GeneratorCos::GeneratorCos() = default;

void GeneratorCos::generate(CustomGeneratorParametrs &parameters)
{
    m_parametrs = parameters;
    const auto size = parameters.duration() / parameters.step();
    const auto w = 2 * M_PI * parameters.frequency();
    for (size_t i = 0; i < size; ++i)
        m_values.push_back(parameters.amplitude() * std::cos(w * i * parameters.step()));
}

std::vector<double> &GeneratorCos::values()
{
    return m_values;
}

CustomGeneratorParametrs &GeneratorCos::parametrs()
{
    return m_parametrs;
}

}