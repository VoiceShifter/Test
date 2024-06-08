#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
# include <QtCore>
# pragma once

class Subject : public QObject
{
    Q_OBJECT
public:
    Subject(QObject *parent = nullptr);
    Subject(QString, QString, QString, QString);
    Subject();
    Subject(const Subject &Copy);
    QString TeacherName;
    QString ItemName;
    QString Place;
    QString Type;
    void operator=(const Subject& Right);

    QString getTeacherName() const ;

    QString getItemName() const ;

    QString getPlace() const ;

    QString getType() const ;

signals:
private:
    Q_PROPERTY(QString _TeacherName READ getTeacherName CONSTANT FINAL)
    Q_PROPERTY(QString itemName READ getItemName CONSTANT FINAL)
    Q_PROPERTY(QString _Place READ getPlace CONSTANT FINAL)
    Q_PROPERTY(QString _Type READ getType CONSTANT FINAL)
};

#endif // SUBJECT_H
