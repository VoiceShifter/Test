#include <QGuiApplication>
#include <QQmlApplicationEngine>
# include "ServerCall.h"
# include "JsonParser.h"
# include <QObject>
# include "Subject.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // QNetworkAccessManager *manager = new QNetworkAccessManager();
    // QNetworkRequest request;
    // request.setUrl(QUrl("https://mirea.xyz/api/v1.3/groups/all"));
    // QNetworkReply *reply = manager->get(request);
    // QEventLoop loop;
    // QAbstractSocket::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    // loop.exec();
    // qDebug() << reply->readAll();


    // QTcpSocket MainSocket;
    // MainSocket.connectToHost("192.168.1.123", 32323);
    // qDebug() << MainSocket.state();
    // MainSocket.waitForConnected();
    // qDebug() << MainSocket.state();
    // MainSocket.write("GET_Login_Password");
    // MainSocket.read(1);
    // QEventLoop loop;
    // QAbstractSocket::connect(&MainSocket, SIGNAL(disconnected()), &loop, SLOT(quit()));
    // loop.exec();
    // qDebug() << MainSocket.read(1).toStdString();
    // if (MainSocket.read(1).toStdString().compare("1"))
    // {
    //     qDebug() << "Enter succ";
    // }
    // else
    // {
    //     qDebug() << "Not succ";
    // }
    qDebug() << "Тест русского языка";
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/PcTest/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    qmlRegisterType<ServerCall>("ServerCall", 1, 0, "ServerCall");
    qmlRegisterType<JsonParser>("JsonParser", 1, 0, "JsonParser");
    qmlRegisterType<Subject>("com.Subject", 1, 0, "Subject");
    engine.load(url);

    return app.exec();
}
