#include "qcustomplot.h"
#include "qmlqcustomplot.h"

QmlQCustomPlot::QmlQCustomPlot(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
}

QmlQCustomPlot::~QmlQCustomPlot() = default;

void QmlQCustomPlot::initCustomPlot()
{
    m_customPlot = std::make_unique<QCustomPlot>();

    updateCustomPlotSize();
    m_customPlot->addGraph();
    m_customPlot->graph( 0 )->setPen( QPen( Qt::red ) );
    m_customPlot->xAxis->setLabel( "t" );
    m_customPlot->yAxis->setLabel( "S" );
    m_customPlot->xAxis->setRange( 0, 10 );
    m_customPlot->yAxis->setRange( 0, 5 );
    m_customPlot ->setInteractions( QCP::iRangeDrag | QCP::iRangeZoom );

    connect(m_customPlot.get(), &QCustomPlot::afterReplot, this, &QmlQCustomPlot::onCustomReplot);

    m_customPlot->replot();
}

void QmlQCustomPlot::updateCustomPlotSize() const
{
    if (!m_customPlot)
        return;

    m_customPlot->setGeometry(0, 0, static_cast<int>(width()), static_cast<int>(height()));
    m_customPlot->setViewport(QRect(0, 0, static_cast<int>(width()), (int)height()));
}

void QmlQCustomPlot::onCustomReplot()
{
    update();
}

void QmlQCustomPlot::paint(QPainter *painter)
{
    Q_UNUSED(painter);
}
