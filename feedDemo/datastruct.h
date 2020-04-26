#ifndef DATASTRUCT
#define DATASTRUCT
#include<QString>
#include<QDate>

class AnimalInfo{
public:
    QString uid;
    QString name;
    QDate birth;
    int sex;
    double weight;
};
class VacInfo{
public:
    QString vid;
    QString name;
    QString relyon;
    int vtime;
    QString text;
};

#endif // DATASTRUCT

