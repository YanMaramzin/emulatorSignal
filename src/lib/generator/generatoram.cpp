#include <typeinfo>
#include <valarray>
#include "generatoram.h"
#include "generatoramparametrs.h"

namespace emulatorSignal {

GeneratorAm::GeneratorAm() = default;

void GeneratorAm::generate(CustomGeneratorParametrs &parameters)
{
    try {
        const auto genParams = dynamic_cast<GeneratorAmParametrs &>(parameters);
        m_values.clear();
        m_values.reserve(genParams.message().size());
        for (size_t i = 0; i < genParams.message().size(); ++i) {
            m_values.push_back(genParams.amplitude() * genParams.message()[i] * cos(genParams.carrierFrequency() * i * genParams.step()));
        }

    } catch (std::bad_cast &e) {

    }
}
std::vector<double> &GeneratorAm::values()
{
    return m_values;
}

}
