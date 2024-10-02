#include <generatorcos.h>
#include "generatorbackend.h"

namespace emulatorSignal {

GeneratorBackend::~GeneratorBackend() = default;

GeneratorBackend::GeneratorBackend(QObject *parent) : QObject(parent)
{
    m_customplot = new QmlQCustomPlot();
}

void GeneratorBackend::replot()
{
    m_customplot->customPlot()->clearGraphs();
    qDebug() << "REPLOT";
    CustomGeneratorParametrs parametrs;
    parametrs.setAmplitude(m_amplitude);
    parametrs.setFrequency(m_frequency);

    GeneratorCos cos;
    cos.generate(parametrs);
    m_customplot->customPlot()->addGraph();
    for (size_t i = 0; i < cos.values().size(); ++i) {
        auto key = (i * 1.0) /  cos.values().size();
        m_customplot->customPlot()->graph(0)->addData(key, cos.values()[i]);
    }
    m_customplot->customPlot()->graph(0)->rescaleAxes(true);
    m_customplot->customPlot()->replot();
}

 QCustomPlot *GeneratorBackend::initCustomPlot()
 {
     m_customplot->initCustomPlot();
     CustomGeneratorParametrs parametrs;
     parametrs.setAmplitude(m_amplitude);
     parametrs.setFrequency(m_frequency);

     GeneratorCos cos;
     cos.generate(parametrs);
     for(size_t i = 0; i < cos.values().size(); ++i) {
         auto key = (i * 1.0) /  cos.values().size();
         m_customplot->customPlot()->graph(0)->addData(key, cos.values()[i]);
     }
     m_customplot->customPlot()->graph(0)->rescaleAxes(true);
     return m_customplot->customPlot();
 }

double GeneratorBackend::amplitude() const
{
    return m_amplitude;
}

void GeneratorBackend::setAmplitude(double value)
{
    if (value == m_amplitude)
        return;

    m_amplitude = value;
    emit amplitudeChanged();
}

double GeneratorBackend::frequency() const
{
    return m_frequency;
}

void GeneratorBackend::setFrequency(double value)
{
    if (value == m_frequency)
        return;

    m_frequency = value;
    emit frequencyChanged();
}

QCustomPlot *GeneratorBackend::customPlot()
{
    return m_customplot->customPlot();
}

void GeneratorBackend::setQCustomPlot(QmlQCustomPlot *customplot)
{
    m_customplot = customplot;
}

}
