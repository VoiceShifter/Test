#include "ServerCall.h"

ServerCall::ServerCall(QObject *parent)
    : QObject{parent}
{}

QString ServerCall::getFStringReply() const
{
    return fStringReply;
}

void ServerCall::setFStringReply(const QString &newFStringReply)
{

    qDebug() << "setFString Function called";

    // fRequest.setUrl(QUrl("https://mirea.xyz/api/v1.3/groups/certain/?name=ИКБО-07-21"));
    // fReply = fManager.get(fRequest);
    // QEventLoop loop;
    // connect(fReply, SIGNAL(finished()), &loop, SLOT(quit()));
    // fStringReply = fReply->readAll();
    // qDebug() << fReply->readAll();
    // emit fStringReplyChanged();
}

QNetworkReply *ServerCall::getFReply() const
{
    return fReply;
}

void ServerCall::setFReply(QNetworkReply *newFReply)
{
    qDebug() << "Function called";
    QTcpSocket MainSocket;
    MainSocket.connectToHost("46.22.56.166", 32323);
    MainSocket.write("GET Login Password");

    // fRequest.setUrl(QUrl("https://api.open-notify.org/this-api-doesnt-exist"));
    // fReply = fManager.get(fRequest);
    //qDebug() << fReply->readAll();
    emit fReplyChanged();
}


