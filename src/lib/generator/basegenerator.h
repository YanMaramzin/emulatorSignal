#pragma once
#include "customgeneratorparametrs.h"

class BaseGenerator
{
public:
    BaseGenerator();
    virtual ~BaseGenerator() = default;
    virtual void generate(CustomGeneratorParametrs &parameters) = 0;
};