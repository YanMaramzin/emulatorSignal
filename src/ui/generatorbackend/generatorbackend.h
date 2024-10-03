#pragma once
#include <QObject>
#include <qmlqcustomplot.h>

namespace emulatorSignal {

class GeneratorBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double amplitude READ amplitude WRITE setAmplitude NOTIFY amplitudeChanged)
    Q_PROPERTY(double frequency READ frequency WRITE setFrequency NOTIFY frequencyChanged)
    Q_PROPERTY(double duration READ duration WRITE setDuration NOTIFY durationChanged)

public:
    explicit GeneratorBackend(QObject *parent = nullptr);
    ~GeneratorBackend() override;
    Q_INVOKABLE void replot();
    Q_INVOKABLE QCustomPlot *initCustomPlot();
//    Q_INVOKABLE QmlQCustomPlot *customPlot();
    Q_INVOKABLE QCustomPlot *customPlot();
    Q_INVOKABLE void setQCustomPlot(QmlQCustomPlot *customplot);

    double amplitude() const;
    void setAmplitude(double value);

    double frequency() const;
    void setFrequency(double value);

    double duration() const;
    void setDuration(double duration);

signals:
    void amplitudeChanged();
    void frequencyChanged();
    void durationChanged();

private:
    QmlQCustomPlot *m_customplot;
    double m_amplitude {1.0};
    double m_frequency {100.0};
    double m_duration {10.0};
};

}
