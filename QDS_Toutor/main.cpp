#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Connector.h"
#include <QQmlContext>
int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN) && QT_VERSION_CHECK(5, 6, 0) <= QT_VERSION && QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/qt/qml/qds_toutor/main.qml")));
	Connector* connector = new Connector(nullptr);
	engine.rootContext()->setContextProperty("connector", connector);
    engine.load(QUrl(QStringLiteral("qrc:/content/App.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
