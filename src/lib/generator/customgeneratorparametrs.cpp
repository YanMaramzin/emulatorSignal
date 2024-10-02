#include "customgeneratorparametrs.h"

CustomGeneratorParametrs::CustomGeneratorParametrs() = default;

CustomGeneratorParametrs::~CustomGeneratorParametrs() = default;

double CustomGeneratorParametrs::frequency() const
{
    return m_frequency;
}

double CustomGeneratorParametrs::amplitude() const {
    return m_amplitude;
}

void CustomGeneratorParametrs::setFrequency(double frequency)
{
    m_frequency = frequency;
}

void CustomGeneratorParametrs::setAmplitude(double amplitude)
{
    m_amplitude = amplitude;
}

double CustomGeneratorParametrs::step() const
{
    return m_step;
}

double CustomGeneratorParametrs::phase() const
{
    return m_phase;
}
