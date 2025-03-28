#include "generatoramparametrs.h"

GeneratorAmParametrs::GeneratorAmParametrs()
{
}

GeneratorAmParametrs::~GeneratorAmParametrs() = default;

double GeneratorAmParametrs::carrierFrequency() const
{
    return m_carrierFrequency;
}

void GeneratorAmParametrs::setCarrierFrequency(double frequency)
{
    m_carrierFrequency = frequency;
}

double GeneratorAmParametrs::modultionCoefficient() const
{
    return m_modultionCoefficient;
}

void GeneratorAmParametrs::setModultionCoefficient(double coefficient)
{
    m_modultionCoefficient = coefficient;
}

const std::vector<double> &GeneratorAmParametrs::message() const
{
    return m_message;
}

void GeneratorAmParametrs::setMessage(std::vector<double> &message)
{
    m_message = message;
}
