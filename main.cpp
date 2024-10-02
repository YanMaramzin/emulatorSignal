#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <generatorbackend.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/EmulQml/main.qml"_qs);

    qmlRegisterType<QmlQCustomPlot>("CustomPlot", 1, 0, "CustomPlot");
    qmlRegisterType<emulatorSignal::GeneratorBackend>("GeneratorBackend", 1, 0, "GeneratorBackend");


    engine.load(url);

    return app.exec();
}
