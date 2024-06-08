#include "JsonParser.h"
# include <QDate>
JsonParser::JsonParser(QObject *parent)
    : QObject{parent}, fJsonFile("Schedule.json")
{

    QFile Dynamic("NewSchedule.json");
    Dynamic.open(QIODevice::ReadWrite);
    fJsonFile.open(QIODevice::ReadWrite);
    Dynamic.close();
    QDateTime date = QDateTime::currentDateTime();
    QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
    _GetWeekReply();
    switch (date.date().dayOfWeek()) {
    case 1:
        CurrentDayString = "понедельник";
        CurrentDayInt = 0;
        break;
    case 2:
        CurrentDayString = "вторник";
        CurrentDayInt = 1;
        break;
    case 3:
        CurrentDayString = "среда";
        CurrentDayInt = 2;
        break;
    case 4:
        CurrentDayString = "четверг";
        CurrentDayInt = 3;
        break;
    case 5:
        CurrentDayString = "пятница";
        CurrentDayInt = 4;
        break;
    case 6:
        CurrentDayString = "суббота";
        CurrentDayInt = 5;
        break;
    case 7:
        CurrentDayString = "воскресенье";
        CurrentDayInt = 6;
        break;

    default:
        break;
    }

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
    fJsonFile.resize(0);

    fJsonFile.write(FormattedString.toUtf8());
    fJsonFile.close();
    fJsonFile.open(QIODevice::ReadWrite);

}

void JsonParser::_ReadJson()
{
    qDebug() << fJsonFile.readAll();
}

QStringList JsonParser::getCurrentDayItems() const
{
    return CurrentDayItems;
}

void JsonParser::setCurrentDayItems(const QStringList &newCurrentDayItems)
{
    if (CurrentDayItems == newCurrentDayItems)
        return;
    CurrentDayItems = newCurrentDayItems;
    emit CurrentDayItemsChanged();
}

int JsonParser::getCurrentDayInt() const
{
    return CurrentDayInt;
}

void JsonParser::setCurrentDayInt(int newCurrentDayInt)
{
    if (CurrentDayInt == newCurrentDayInt)
        return;
    CurrentDayInt = newCurrentDayInt;
    emit CurrentDayIntChanged();
}

QStringList JsonParser::getCurrentDayCabs() const
{
    return CurrentDayCabs;
}

void JsonParser::setCurrentDayCabs(const QStringList &newCurrentDayCabs)
{
    if (CurrentDayCabs == newCurrentDayCabs)
        return;
    CurrentDayCabs = newCurrentDayCabs;
    emit CurrentDayCabsChanged();
}

signed int JsonParser::getWeek() const
{
    return Week;
}

void JsonParser::_GetWeekReply()
{
    QString Url{"https://mirea.xyz/api/v1.3/time/week"};
    fRequest.setUrl(QUrl(Url)); // //https://mirea.xyz/api/v1.3/groups/certain?name=ИКБО-07-21
    fReply = fManager.get(fRequest);
    QEventLoop loop;
    QAbstractSocket::connect(fReply, SIGNAL(finished()), &loop, SLOT(quit()));

    loop.exec();
    QString FormattedString{QString::fromUtf8(fReply->readAll())};
    qDebug() << FormattedString;
    Week = FormattedString.toInt();
    qDebug() << Week;
}

void JsonParser::setWeek(signed int newWeek)
{
    if (Week == newWeek)
        return;
    Week = newWeek;
    emit WeekChanged();
}

QStringList JsonParser::getType() const
{
    return Type;
}

void JsonParser::setType(const QStringList &newType)
{
    if (Type == newType)
        return;
    Type = newType;
    emit TypeChanged();
}

QStringList JsonParser::getPlace() const
{
    return Place;
}

void JsonParser::setPlace(const QStringList &newPlace)
{
    if (Place == newPlace)
        return;
    Place = newPlace;
    emit PlaceChanged();
}

QStringList JsonParser::getItemName() const
{
    return ItemName;
}

void JsonParser::setItemName(const QStringList &newItemName)
{
    if (ItemName == newItemName)
        return;
    ItemName = newItemName;
    emit ItemNameChanged();
}

QStringList JsonParser::getTeacherName() const
{
    return TeacherName;
}

void JsonParser::setTeacherName(const QStringList &newTeacherName)
{
    if (TeacherName == newTeacherName)
        return;
    TeacherName = newTeacherName;
    emit TeacherNameChanged();
}

QVector<Subject> JsonParser::getSubjects() const
{
    return Subjects;
}




void JsonParser::_IncrementDay()
{
    switch (this->CurrentDayInt) {
    case 0:
        CurrentDayString = "вторник";
        CurrentDayInt = 1;
        break;
    case 1:
        CurrentDayString = "среда";
        CurrentDayInt = 2;
        break;
    case 2:
        CurrentDayString = "четверг";
        CurrentDayInt = 3;
        break;
    case 3:
        CurrentDayString = "пятница";
        CurrentDayInt = 4;
        break;
    case 4:
        CurrentDayString = "суббота";
        CurrentDayInt = 5;
        break;
    case 5:
        CurrentDayString = "воскресенье";
        CurrentDayInt = 6;
        break;
    case 6:
        CurrentDayString = "понедельник";
        CurrentDayInt = 0;
        Week++;
        break;

    default:
        break;
    }
    qDebug() << CurrentDayString.c_str();
    emit CurrentDayIntChanged();
}

void JsonParser::_DecrementDay()
{
    switch (this->CurrentDayInt) {
    case 0:
        CurrentDayString = "воскресенье";
        CurrentDayInt = 6;
        Week--;
        break;
    case 1:
        CurrentDayString = "понедельник";
        CurrentDayInt = 0;
        break;
    case 2:
        CurrentDayString = "вторник";
        CurrentDayInt = 1;
        break;
    case 3:
        CurrentDayString = "среда";
        CurrentDayInt = 2;
        break;
    case 4:
        CurrentDayString = "четверг";
        CurrentDayInt = 3;
        break;
    case 5:
        CurrentDayString = "пятница";
        CurrentDayInt = 4;
        break;
    case 6:
        CurrentDayString = "суббота";
        CurrentDayInt = 5;
        break;

    default:
        break;
    }
    qDebug() << CurrentDayString.c_str();
    emit CurrentDayIntChanged();
}


void JsonParser::_ReadValue(signed int pDay) //deprecated
{


    QString Buffer {fJsonFile.readAll()};
    QJsonParseError error;

    fJsonDoc = QJsonDocument::fromJson(Buffer.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError) {
        qDebug() << "JSON parsing error:" << error.errorString();
    } else {
        qDebug() << "JSON parsing successful!";
    }
    QJsonArray rootArray = fJsonDoc.array();
    QJsonValue ScheduleArray{rootArray[0]};

    QString FormattedString {ScheduleArray["schedule"][pDay].toObject()["day"].toString()}; //day
    //QObject
    QJsonArray Subjects{ScheduleArray["schedule"][pDay]["even"].toArray()};
    qDebug() << "\n день" << FormattedString;
    qDebug() << "\n предметы" << Subjects;
        //                     |*- массив массивов предметов   | массив из предметов | - объект предмета
    qDebug() << "\nКонкретный" << Subjects[0]                             [1]                   [0]["name"]  ;   //qDebug() << "\nКонкретный" << Subjects[0][3]; - сис админ


    fJsonFile.close();
    fJsonFile.open(QIODevice::ReadWrite);
    emit SubjectChanged();
}





void JsonParser::_FillCurrentDayS()
{
    QString Buffer {fJsonFile.readAll()};
    QJsonParseError error;
    fJsonDoc = QJsonDocument::fromJson(Buffer.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError) {
        qDebug() << "JSON parsing error:" << error.errorString();
        qDebug() << Buffer;
        return;
    } else {
        qDebug() << "JSON parsing successful!";
    }


    ItemName.clear();
    TeacherName.clear();
    Place.clear();
    Type.clear();
    Subjects.clear();        



    std::string OddEven{};
    if (Week % 2 == 0)
    {
        OddEven = "even";
    }
    else
    {
        OddEven = "odd";
    }


    QJsonArray rootArray = fJsonDoc.array();
    QJsonValue ScheduleArray{rootArray[0]};


    for (size_t Iterator{}; Iterator < 7; ++Iterator)
    {
        if (ScheduleArray["schedule"][CurrentDayInt][OddEven.c_str()][Iterator][0]["name"].toString() == "")
        {
            continue;
        }
        else
        {
            this->ItemName.push_back(ScheduleArray["schedule"][CurrentDayInt][OddEven.c_str()][Iterator][0]["name"].toString()); //todo put in one item and just "name" "tutor" etc
            this->TeacherName.push_back(ScheduleArray["schedule"][CurrentDayInt][OddEven.c_str()][Iterator][0]["tutor"].toString());
            this->Place.push_back(ScheduleArray["schedule"][CurrentDayInt][OddEven.c_str()][Iterator][0]["place"].toString());
            this->Type.push_back(ScheduleArray["schedule"][CurrentDayInt][OddEven.c_str()][Iterator][0]["type"].toString());
        }
        // qDebug() << ScheduleArray["schedule"][CurrentDayInt]["odd"][Iterator][0]["name"].toString();
        // qDebug() << ScheduleArray["schedule"][CurrentDayInt]["odd"][Iterator][0]["tutor"];
        // qDebug() << ScheduleArray["schedule"][CurrentDayInt]["odd"][Iterator][0]["place"];
        // qDebug() << ScheduleArray["schedule"][CurrentDayInt]["odd"][Iterator][0]["type"];
        // Subjects[Iterator].TeacherName = ScheduleArray["schedule"][CurrentDayInt]["odd"][Iterator][0]["tutor"].toString();
        // Subjects[Iterator].Place = ScheduleArray["schedule"][CurrentDayInt]["odd"][Iterator][0]["place"].toString();
        // Subjects[Iterator].Type = ScheduleArray["schedule"][CurrentDayInt]["odd"][Iterator][0]["type"].toString();

    }
    qDebug() << Week;
    // for (size_t Iterator{}; Iterator < Subjects.size(); ++Iterator)
    // {
    //     qDebug() << ItemName[Iterator] + " " << TeacherName[Iterator] + " " << Place[Iterator] + " " << Type[Iterator];
    // }
    emit ItemNameChanged();
    emit TeacherNameChanged();
    emit PlaceChanged();
    emit TypeChanged();
    fJsonFile.close();
    fJsonFile.open(QIODevice::ReadWrite);
}

void JsonParser::_PrintAmount()
{
    qDebug() << ItemName.size();
}
