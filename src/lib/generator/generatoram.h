#pragma once
#include <basegenerator.h>

namespace emulatorSignal {

class GeneratorAm : public BaseGenerator
{
public:
    GeneratorAm();
    ~GeneratorAm() override = default;

    void generate(CustomGeneratorParametrs &parameters) override;
    std::vector<double> &values() override;

private:
    std::vector<double> m_values;

};

}