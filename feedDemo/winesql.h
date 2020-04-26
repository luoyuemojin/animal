#ifndef FEEDSQL_H
#define FEEDSQL_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QList>
#include "datastruct.h"
class WineSql
{
public:
    WineSql();
private:
    QSqlDatabase db;
    QSqlQuery *query;
public:
     //链接操作
     bool createConnection();
     //动物操作
     bool addWine(Wine ani);//添加酒
     bool delWine(QString uid);   //删除酒
     Wine *getWine(QString uid); //查看酒
     bool setAnimalWeight(QString uid,double weight);   //需实现
     /*
     //疫苗操作
     bool addVac(VacInfo vac);
     VacInfo *getVacInfo(QString vid);
     bool delVac(QString vid);
     QList<VacInfo> *getAllVacInfos();  //需实现
     QList<VacInfo> *getNeedVacInfos(QString uid);  //需实现 获取某动物该接种的疫苗
     //接种操作
     bool jiezhong(QString uid,QString vid);    //需实现
    */
};

#endif // FEEDSQL_H
