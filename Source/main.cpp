#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>

#include "startupcontroller.h"
#include "connector.h"

void processStartupResult(const StartupResult *res);

int main(int argc, char *argv[])
{
//#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//#endif
    QCoreApplication::setApplicationName(QString("Freedom Messenger"));
    QCoreApplication::setApplicationVersion(QString("Alpha 1.0"));
    QCoreApplication::setOrganizationName(QString("SenDu"));

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Settings settings;

    const StartupResult *startupRes = StartupController::launch(&engine, &settings);
    processStartupResult(startupRes);
    delete startupRes;

    Connector connector;

    engine.rootContext()->setContextProperty("connectorHandler", &connector);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    connector.sendRequest("I'm new used!");
    if (connector.connectToServer(QString("127.0.0.1")))
        ;
    else
        qDebug() << "Socket error: " << connector.getError();

    return app.exec();
}

void processStartupResult(const StartupResult *res)
{
    if (res->errors != 0) {
        qDebug() << "There is (are) error(s) in startup result: " << res->errors;
        throw std::runtime_error("ERROR STARTUPING APP! READ MESSAGE!");
    } else {
        qDebug().noquote() << QString("There are %1 successful, %2 warning(s), 0 error.")
                    .arg(res->successful).arg(res->warnings).arg(res->errors);
    }
}
