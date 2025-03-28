#pragma once
#include <vector>
#include <customgeneratorparametrs.h>

class GeneratorAmParametrs : public CustomGeneratorParametrs
{
public:
    GeneratorAmParametrs();
    ~GeneratorAmParametrs() override;

    double carrierFrequency() const;
    void setCarrierFrequency(double frequency);

    double modultionCoefficient() const;
    void setModultionCoefficient(double coefficient);

    const std::vector<double> &message() const;
    void setMessage(std::vector<double> &message);

private:
    double m_carrierFrequency;
    double m_modultionCoefficient;
    std::vector<double> m_message;

};
