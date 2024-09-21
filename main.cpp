#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <qmlqcustomplot.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/EmulQml/main.qml"_qs);

    qmlRegisterType<QmlQCustomPlot>("CustomPlot", 1, 0, "CustomPlot");

    // QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &app,
    //     []()
    //     {
    //         QCoreApplication::exit(-1);
    //     }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
