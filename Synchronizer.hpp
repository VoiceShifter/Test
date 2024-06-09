#ifndef SYNCHRONIZER_HPP
#define SYNCHRONIZER_HPP
# pragma once
# include <QObject>
# include <QtCore>

class Synchronizer : public QObject
{
    Q_OBJECT
public:
    explicit Synchronizer(QObject *parent = nullptr);

signals:
};

#endif // SYNCHRONIZER_HPP
