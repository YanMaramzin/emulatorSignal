#pragma once

#include <QtQuick>
#include "qcustomplot.h"
class QCPAbstractPlottable;

class QmlQCustomPlot : public QQuickPaintedItem
{
    Q_OBJECT

public:
    explicit QmlQCustomPlot(QQuickItem *parent = nullptr);

    ~QmlQCustomPlot() override;

    void paint(QPainter *painter) override;

    Q_INVOKABLE void initCustomPlot();

    Q_INVOKABLE QCustomPlot *customPlot();
    Q_INVOKABLE void setCustomPlot(QCustomPlot *plot);

protected:
    void routeMouseEvents(QMouseEvent *event);
    void routeWheelEvents(QWheelEvent *event);

//    virtual void timerEvent(QTimerEvent *event) override;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent *event) override;

private:
    QCustomPlot *m_customPlot {nullptr};
    void graphClicked(QCPAbstractPlottable *plottable);
    void updateCustomPlotSize() const;
    void onCustomReplot();
};
