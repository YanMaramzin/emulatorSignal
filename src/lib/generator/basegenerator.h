#pragma once
#include <vector>
#include "customgeneratorparametrs.h"

class BaseGenerator
{
public:
    BaseGenerator();
    virtual ~BaseGenerator() = default;
    virtual void generate(CustomGeneratorParametrs &parameters) = 0;
    virtual std::vector<double> &values() = 0;
};
