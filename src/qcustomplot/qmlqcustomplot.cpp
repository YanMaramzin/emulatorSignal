#include "qcustomplot.h"
#include "qmlqcustomplot.h"

QmlQCustomPlot::QmlQCustomPlot(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    connect(this, &QQuickPaintedItem::widthChanged, this, &QmlQCustomPlot::updateCustomPlotSize);
    connect(this, &QQuickPaintedItem::heightChanged, this, &QmlQCustomPlot::updateCustomPlotSize);
}

QmlQCustomPlot::~QmlQCustomPlot()
{
    if (m_timerId != 0)
        killTimer(m_timerId);
}

void QmlQCustomPlot::initCustomPlot()
{
    m_customPlot = std::make_unique<QCustomPlot>();
    qDebug() << "initCustomPlot";
    updateCustomPlotSize();
    m_customPlot->addGraph();
    m_customPlot->graph(0)->setPen(QPen(Qt::red));
    m_customPlot->xAxis->setLabel("t");
    m_customPlot->yAxis->setLabel("S");
    m_customPlot->xAxis->setRange(0, 10);
    m_customPlot->yAxis->setRange(0, 5);
    m_customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    startTimer(500);

    connect(m_customPlot.get(), &QCustomPlot::afterReplot, this, &QmlQCustomPlot::onCustomReplot);

    m_customPlot->replot();
}

void QmlQCustomPlot::timerEvent(QTimerEvent *event)
{
    static double t, U;
    U = ((double)rand() / RAND_MAX) * 5;
    m_customPlot->graph(0)->addData(t, U);
    qDebug() << Q_FUNC_INFO << QString("Adding dot t = %1, S = %2").arg(t).arg(U);
    t++;
    m_customPlot->replot();
}

void QmlQCustomPlot::updateCustomPlotSize() const
{
    if (!m_customPlot)
        return;

    m_customPlot->setGeometry(0, 0, static_cast<int>(width()), static_cast<int>(height()));
    m_customPlot->setViewport(QRect(0, 0, static_cast<int>(width()), (int) height()));
}

void QmlQCustomPlot::onCustomReplot()
{
    update();
}

void QmlQCustomPlot::paint(QPainter *painter)
{
    if (!m_customPlot)
        return;

    QPixmap picture(boundingRect().size().toSize());
    QCPPainter qcpPainter(&picture);

    m_customPlot->toPainter(&qcpPainter);

    painter->drawPixmap(QPoint(), picture);
}
