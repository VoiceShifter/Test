#ifndef SERVERCALL_H
#define SERVERCALL_H

#include <QObject>
# include <QtNetwork>
# include <QTcpSocket>
class ServerCall : public QObject
{
    Q_OBJECT
public:
    explicit ServerCall(QObject *parent = nullptr);
    QNetworkAccessManager fManager;
    QNetworkRequest fRequest;
    QNetworkReply *fReply;
    QString fStringReply;






    QNetworkReply *getFReply() const;
    Q_INVOKABLE void setFReply(QNetworkReply *newFReply = nullptr);

    QString getFStringReply() const;
    Q_INVOKABLE void setFStringReply(const QString &newFStringReply  = nullptr);

signals:
    void fReplyChanged();
    void fStringReplyChanged();

private:
    Q_PROPERTY(QNetworkReply *fReply READ getFReply WRITE setFReply NOTIFY fReplyChanged FINAL)
    Q_PROPERTY(QString fStringReply READ getFStringReply WRITE setFStringReply NOTIFY fStringReplyChanged FINAL)
};

#endif // SERVERCALL_H
