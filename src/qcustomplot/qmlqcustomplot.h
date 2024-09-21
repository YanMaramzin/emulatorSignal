#pragma once

#include <QtQuick>

class QCustomPlot;
class QCPAbstractPlottable;

class QmlQCustomPlot : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit QmlQCustomPlot(QQuickItem *parent = nullptr);

    ~QmlQCustomPlot() override;

    void paint(QPainter *painter);

    Q_INVOKABLE void initCustomPlot();
protected:
    virtual void timerEvent(QTimerEvent *event) override;
private:
    std::unique_ptr<QCustomPlot> m_customPlot {nullptr};
    int m_timerId {0};
    void updateCustomPlotSize() const;
    void onCustomReplot();
};
