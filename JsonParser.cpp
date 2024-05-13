#include "JsonParser.h"
# include <QDate>
JsonParser::JsonParser(QObject *parent)
    : QObject{parent}, fJsonFile("Schedule.json")
{
    QFile Dynamic("NewSchedule.json");
    Dynamic.open(QIODevice::ReadWrite);
    fJsonFile.open(QIODevice::ReadWrite);
    Dynamic.close();
}

JsonParser::~JsonParser()
{
    fJsonFile.close();
}

QJsonArray JsonParser::getFJson() const
{
    return fJson;
}

void JsonParser::setFJson(const QJsonArray &newFJson)
{
    if (fJson == newFJson)
        return;
    fJson = newFJson;
    emit fJsonChanged();
}

void JsonParser::_GetReply(const QString& _pGroup)
{

    QString Url{"https://mirea.xyz/api/v1.3/groups/certain?name="};
    Url.append(_pGroup);
    qDebug() << "New URL" << Url;
    fRequest.setUrl(QUrl(Url)); // //https://mirea.xyz/api/v1.3/groups/certain?name=ИКБО-07-21
    fReply = fManager.get(fRequest);
    QEventLoop loop;
    QAbstractSocket::connect(fReply, SIGNAL(finished()), &loop, SLOT(quit()));

    loop.exec();
    emit fJsonChanged();

    QString FormattedString{QString::fromUtf8(fReply->readAll())};
    qDebug() << FormattedString;
    fJsonFile.write(FormattedString.toUtf8());

}

void JsonParser::_ReadJson()
{
    qDebug() << fJsonFile.readAll();
}

void JsonParser::_ReadValue()
{

    QString Buffer {fJsonFile.readAll()};

    fJsonDoc = QJsonDocument::fromJson(Buffer.toUtf8());
    fJsonObject = fJsonDoc.object(); //can pull values





    QJsonArray rootArray = fJsonDoc.array();



    //qDebug() << '\n' << "Object in rootArray:" << rootArray;
    QJsonValue ScheduleArray{rootArray[0]};

    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

    qDebug() << "Date:"+formattedTime;
    qDebug() << date.date().dayOfWeek();
    // switch (date.date().dayOfWeek()) {
    // case 1: //pull from json to datastructure to then show

    //     break;
    // case 2:

    //     break;
    // case 3:

    //     break;
    // case 4:

    //     break;
    // case 5:

    //     break;
    // case 6:

    //     break;
    // case 7:

    //     break;
    // default:
    //     break;
    // }
    qDebug() << "Test" << ScheduleArray["schedule"][0];
    QFile FileBuffer("Buffer.json");
    FileBuffer.open(QIODevice::ReadWrite);
    if (FileBuffer.isOpen())
    {

        QString FormattedString {ScheduleArray["schedule"][0].toObject()["day"].toString()}; //day
        //QObject
        QJsonArray Subjects{ScheduleArray["schedule"][0]["even"].toArray()};
        qDebug() << "\n день" << FormattedString;
        qDebug() << "\n предметы" << Subjects;

        QJsonValue Specific{Subjects[0][0]};
        qDebug() << "\n конкретный" << Specific;

        qDebug() << Specific.toArray()[0].toObject()["name"].toString();
        //FileBuffer.write(Subjects["name"].toString().toStdString().c_str());

        qDebug() << "successful writing";
    }

    qDebug() << FileBuffer.readAll();
    FileBuffer.close();
//    Iterate over the objects in the root array and print them
    //for (const QJsonValue &value : rootArray) {
        // Convert the value to a QJsonObject and print it


        // If the object contains a 'schedule' key, print the associated array
        // if (obj.contains("schedule")) {
        //     QJsonArray scheduleArray = obj["schedule"].toArray();
        //     qDebug() << '\n' << "Schedule array:" << scheduleArray;
        // }
    //}


    // for (const QJsonValue &value : rootArray) {
    //     // Each 'value' should be an object with a 'schedule' key

    //     QJsonObject obj = value.toObject();
    //     QJsonArray scheduleArray = obj["schedule"].toArray();

    //     // Iterate over the schedule array
    //     for (const QJsonValue &scheduleValue : scheduleArray) {
    //         if (scheduleValue.isObject()) {
    //             QJsonObject scheduleObj = scheduleValue.toObject();
    //             QString day = scheduleObj["day"].toString();
    //             QJsonArray oddArray = scheduleObj["odd"].toArray();
    //             QJsonArray evenArray = scheduleObj["even"].toArray();
    //             qDebug() << day;
    //         }


    //     }
    // }

}
