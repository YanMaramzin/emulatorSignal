#pragma once

#include <vector>
#include "basegenerator.h"

namespace emulatorSignal {

class GeneratorCos : public BaseGenerator
{
public:
    GeneratorCos();
    ~GeneratorCos() override = default;

    void generate(CustomGeneratorParametrs &parameters) override;
    std::vector<double> &values();
    CustomGeneratorParametrs &parametrs();

private:
    std::vector<double> m_values;
    CustomGeneratorParametrs m_parametrs;
};

}