#include "Subject.h"



Subject::Subject(QObject *parent)
    : QObject{parent}
{

}

Subject::Subject(QString pTeacherName, QString pItemName, QString pPlace, QString pType)
{
    TeacherName = pTeacherName;
    ItemName = pItemName;
    Place = pPlace;
    Type = pType;
}

Subject::Subject()
{
    TeacherName = "";
    ItemName = "";
    Place = "";
    Type = "";
}

Subject::Subject(const Subject &Copy)
{
    TeacherName = Copy.TeacherName;
    ItemName = Copy.ItemName;
    Place = Copy.Place;
    Type = Copy.Type;
}

void Subject::operator=(const Subject &Right)
{
    TeacherName = Right.TeacherName;
    ItemName = Right.ItemName;
    Place = Right.Place;
    Type = Right.Type;
}

QString Subject::getType() const
{
    qDebug() << "GetType called";
    return Type;
}

QString Subject::getPlace() const
{
    qDebug() << "GetPlace called";
    return Place;
}

QString Subject::getItemName() const
{
    qDebug() << "GetItemName called";
    return ItemName;
}

QString Subject::getTeacherName() const
{
    qDebug() << "GetTeacherName called";
    return TeacherName;
}
