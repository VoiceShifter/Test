# ifndef JSONPARSER_H
# define JSONPARSER_H

# include <QObject>
# include <QtNetwork>
# include <QDateTime>
# include "Subject.h"

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
    Q_INVOKABLE void _ReadValue(signed int pDay = -1);
    Q_INVOKABLE void _IncrementDay();
    Q_INVOKABLE void _DecrementDay();
    Q_INVOKABLE void _FillCurrentDayS();
    Q_INVOKABLE void _PrintAmount();




    QStringList getCurrentDayItems() const;
    void setCurrentDayItems(const QStringList &newCurrentDayItems);
    int getCurrentDayInt() const;
    void setCurrentDayInt(int newCurrentDayInt);


    QStringList getCurrentDayCabs() const;
    void setCurrentDayCabs(const QStringList &newCurrentDayCabs);
    QStringList TeacherName;
    QStringList ItemName;
    QStringList Place;
    QStringList Type;

    signed int Week;




    QVector<Subject> getSubjects() const;

    QStringList getTeacherName() const;
    void setTeacherName(const QStringList &newTeacherName);

    QStringList getItemName() const;
    void setItemName(const QStringList &newItemName);

    QStringList getPlace() const;
    void setPlace(const QStringList &newPlace);

    QStringList getType() const;
    void setType(const QStringList &newType);


    signed int getWeek() const;
    Q_INVOKABLE void _GetWeekReply();
    void setWeek(signed int newWeek);

signals:
    void fJsonChanged();
    void CurrentDayItemsChanged();
    void CurrentDayIntChanged();
    void CurrentDayCabsChanged();
    void SubjectChanged();


    void TeacherNameChanged();

    void ItemNameChanged();

    void PlaceChanged();

    void TypeChanged();

    void WeekChanged();

private:
    Q_PROPERTY(QJsonArray fJson READ getFJson WRITE setFJson NOTIFY fJsonChanged FINAL)
    Q_PROPERTY(QStringList CurrentDayItems READ getCurrentDayItems WRITE setCurrentDayItems NOTIFY CurrentDayItemsChanged FINAL)
    Q_PROPERTY(int CurrentDayInt READ getCurrentDayInt WRITE setCurrentDayInt NOTIFY CurrentDayIntChanged FINAL)
    Q_PROPERTY(QStringList CurrentDayCabs READ getCurrentDayCabs WRITE setCurrentDayCabs NOTIFY CurrentDayCabsChanged FINAL)
    Q_PROPERTY(QVector<Subject> _Subjects READ getSubjects NOTIFY SubjectChanged FINAL)


    QVector<Subject> Subjects{};
    int CurrentDayInt{};
    std::string CurrentDayString{};
    QStringList CurrentDayItems{};
    QStringList CurrentDayCabs{};







    Q_PROPERTY(QStringList _TeacherName READ getTeacherName WRITE setTeacherName NOTIFY TeacherNameChanged FINAL)
    Q_PROPERTY(QStringList _ItemName READ getItemName WRITE setItemName NOTIFY ItemNameChanged FINAL)
    Q_PROPERTY(QStringList _Place READ getPlace WRITE setPlace NOTIFY PlaceChanged FINAL)
    Q_PROPERTY(QStringList _Type READ getType WRITE setType NOTIFY TypeChanged FINAL)

    Q_PROPERTY(signed int Week READ getWeek WRITE setWeek NOTIFY WeekChanged FINAL)
};


#endif // JSONPARSER_H
