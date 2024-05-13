# ifndef JSONPARSER_H
# define JSONPARSER_H

# include <QObject>
# include <QtNetwork>
# include <QDateTime>
class JsonParser : public QObject
{
    Q_OBJECT
public:
    explicit JsonParser(QObject *parent = nullptr);
    ~JsonParser();
    QNetworkAccessManager fManager;
    QNetworkRequest fRequest;
    QNetworkReply *fReply;
    QString fStringReply;
    QJsonArray fJson;
    QFile fJsonFile;
    QJsonDocument fJsonDoc;
    QJsonObject fJsonObject;

    QJsonArray getFJson() const;
    void setFJson(const QJsonArray &newFJson);
    Q_INVOKABLE void _GetReply(const QString&);
    Q_INVOKABLE void _ReadJson();
    Q_INVOKABLE void _ReadValue();

signals:
    void fJsonChanged();
private:
    Q_PROPERTY(QJsonArray fJson READ getFJson WRITE setFJson NOTIFY fJsonChanged FINAL)
};


#endif // JSONPARSER_H
