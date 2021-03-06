#include "winesql.h"
#include <QProcess>
FeedSql::FeedSql()
{   

}

bool FeedSql::createConnection()
{
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("feed");
    db.setUserName("root");
    db.setPassword("123456");
    if(!db.open()){
        QMessageBox::critical(0,QObject::tr("无法打开数据库"),"无法创建数据库链接！",QMessageBox::Cancel
                              );

        return false;//链接不成功
    }

    query=new QSqlQuery(db);
    if(query==NULL)return false;
    qDebug()<<"数据库链接成功";
    return true;
}

bool FeedSql::addAnimal(AnimalInfo ani)
{
    //INSERT INTO animal VALUE('004','羊','2019-05-30',1,14);
    //
    QString ss=QString("INSERT INTO animal VALUE('%1','%2','%3',%4,%5)").arg(ani.uid).arg(ani.name)
            .arg(ani.birth.toString("yyyy-MM-dd")).arg(ani.sex).arg(ani.weight);
    query->exec(ss);
    if(query->numRowsAffected()==1){
    // qDebug()<<"插入成功";
     return true;

    }
    else return false;
}

bool FeedSql::delAnimal(QString uid)
{
    //DELETE FROM animal WHERE aid='004';
    QString ss=QString("DELETE FROM animal WHERE aid='%1';").arg(uid);
    query->exec(ss);
    if(query->numRowsAffected()==1){
      //  qDebug()<<"删除成功";
        return true;
    }
    return false;
}

AnimalInfo *FeedSql::getAnimalInfo(QString uid)
{
    QString ss=QString("SELECT * from animal WHERE aid='%1';").arg(uid);
    query->exec(ss);
    if(query->numRowsAffected()==1){
       // qDebug()<<"animal查询成功";
        AnimalInfo *info=new AnimalInfo;
        query->next();
        info->uid=query->value(0).toString();
        info->name=query->value(1).toString();
        info->birth=query->value(2).toDate();
        info->sex=query->value(3).toInt();
        info->weight=query->value(4).toDouble();
      //  qDebug()<<info->uid<<info->name<<info->birth<<info->sex;
        return info;
    }
    return NULL;
}

bool FeedSql::setAnimalWeight(QString uid, double weight)
{
    QString ss=QString("UPDATE animal SET aweight=%1 WHERE aid= '%2';").arg(weight).arg(uid);
    query->exec(ss);
    if(query->numRowsAffected()==1){
       // qDebug()<<"设置重量成功！";
        return true;
    }
    return false;
}

//动物操作定义完毕
//以下是疫苗操作

bool FeedSql::addVac(VacInfo vac)
{
    if(vac.relyon==NULL)
        vac.relyon="NULL";
    else vac.relyon=QString("'%1'").arg(vac.relyon);
    //外键插入的一个bug 在往数据库里写入‘’时，并不会设为空，而是当成一个字符串‘’设置进去，所以在传入 null有特殊的数据是，
    //要像这样做一下处理。
    QString ss=QString("INSERT INTO vaccine VALUE('%1','%2',%3 ,%4,'%5');").arg(vac.vid).arg(vac.name)
            .arg(vac.relyon).arg(vac.vtime).arg(vac.text);
    query->exec(ss);
    if(query->numRowsAffected()==1){
    // qDebug()<<"插入成功";
     return true;

    }
    else return false;
}

QList<VacInfo> *FeedSql::getAllVacInfos()
{
    QString ss=QString("SELECT * from vaccine;");
    query->exec(ss);
    if(query->numRowsAffected()>0){
        //qDebug()<<"vaccine查询成功";
        QList<VacInfo> *vl=new QList<VacInfo>;
        while(query->next()){

            VacInfo info;
            info.vid=query->value(0).toString();
            info.name=query->value(1).toString();
            info.relyon=query->value(2).toString();
            info.vtime=query->value(3).toInt();
            info.text=query->value(4).toString();
            vl->append(info);
          }
        return vl;
    }
    return NULL;

}

QList<VacInfo> *FeedSql::getNeedVacInfos(QString uid)
{

    //获取打过的疫苗id列表
    //SELECT vid FROM vaccination WHERE aid='001';
    QString nothaveJz=""; //条件 没有打过
    QString haveJz="";  //条件 打过
    query->exec(QString("SELECT vid FROM vaccination WHERE aid='%1';").arg(uid));
    if(query->numRowsAffected()>=0){
        nothaveJz+="and vaccine.vid not in (";
        haveJz+="and vaccine.vid in (";
        query->next();
        haveJz=haveJz+"'"+query->value(0).toString()+"'";
        nothaveJz=nothaveJz+"'"+query->value(0).toString()+"'";
        while(query->next()){
            haveJz=haveJz+",'"+query->value(0).toString()+"'";
            nothaveJz=nothaveJz+",'"+query->value(0).toString()+"'";
        }
        haveJz+=") ";
        nothaveJz+=") ";
    }
    //获取该打的疫苗（没有依赖的部分）
    //select vid FROM vaccine,animal
    //WHERE aid='001' AND vid NOT IN ('v2','v3') and vrelyon is NULL and vtime <= DATEDIFF(NOW(),abirth);
    QList<VacInfo> *vlist=new QList<VacInfo>;
    QString ss=QString("select vaccine.* FROM vaccine,animal WHERE aid='%1' %2 and vrelyon is NULL and vtime <= DATEDIFF(NOW(),abirth);")
            .arg(uid).arg(nothaveJz);

    query->exec(ss);
    while(query->next()){
        VacInfo info;
        info.vid=query->value(0).toString();
        info.name=query->value(1).toString();
        info.relyon=query->value(2).toString();
        info.vtime=query->value(3).toInt();
        info.text=query->value(4).toString();
        vlist->append(info);
    }
    //获取该打的疫苗（有依赖的）
    //SELECT vaccine.* from vaccine,vaccination as va
    //WHERE va.aid='001' and vrelyon is not NULL and va.vid=vaccine.vrelyon
    //and vtime <=DATEDIFF(NOW(),va.time) and vaccine.vid not in ('v1');
    ss=QString("SELECT vaccine.* from vaccine,vaccination as va WHERE va.aid='%1' and vrelyon is not NULL and va.vid=vaccine.vrelyon and vtime <=DATEDIFF(NOW(),va.time) %2;")
            .arg(uid).arg(nothaveJz);
    query->exec(ss);
    while(query->next()){
        VacInfo info;
        info.vid=query->value(0).toString();
        info.name=query->value(1).toString();
        info.relyon=query->value(2).toString();
        info.vtime=query->value(3).toInt();
        info.text=query->value(4).toString();
        vlist->append(info);
    }
    return vlist;


}


VacInfo *FeedSql::getVacInfo(QString vid)
{
    QString ss=QString("SELECT * from vaccine WHERE aid='%1';").arg(vid);
    query->exec(ss);
    if(query->numRowsAffected()==1){
        //qDebug()<<"vaccine查询成功";
        VacInfo info;
        query->next();
        info.vid=query->value(0).toString();
        info.name=query->value(1).toString();
        info.relyon=query->value(2).toString();
        info.vtime=query->value(3).toInt();
        info.text=query->value(4).toString();
        return &info;
    }
    return NULL;
}

bool FeedSql::delVac(QString vid)
{
    qDebug()<<vid;
    //DELETE FROM animal WHERE aid='004';
    QString ss=QString("DELETE FROM vaccine WHERE vid='%1';").arg(vid);

    query->exec(ss);
    if(query->numRowsAffected()==1){
       // qDebug()<<"删除成功";
        return true;
    }
    return false;
}

//以下是接种过程
bool FeedSql::jiezhong(QString uid, QString vid)
{
   // INSERT INTO vaccination VALUE('001','v2','2019-5-30');
    QString ss=QString("INSERT INTO vaccination VALUE('%1','%2','%3');")
            .arg(uid).arg(vid).arg(QDate::currentDate().toString("yyyy-MM-dd"));
    query->exec(ss);
    if(query->numRowsAffected()==1){
       // qDebug()<<"添加接种信息成功！";
        return true;
    }
    return false;
}
