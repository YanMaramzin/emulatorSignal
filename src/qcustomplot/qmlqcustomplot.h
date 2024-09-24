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

    void paint(QPainter *painter) override;

    Q_INVOKABLE void initCustomPlot();
protected:
    void routeMouseEvents(QMouseEvent *event);
    void routeWheelEvents(QWheelEvent *event);

    virtual void timerEvent(QTimerEvent *event) override;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent *event) override;

private:
    std::unique_ptr<QCustomPlot> m_customPlot {nullptr};
    int m_timerId {0};
    void graphClicked(QCPAbstractPlottable *plottable);
    void updateCustomPlotSize() const;
    void onCustomReplot();
};
