#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ser = new SerialRfid;
    wines = new WineSql;

   // setFixedSize(1000,800);
    ui->date->setCalendarPopup(true);
    wines->createConnection();
    ui->zhucexinxitijaio->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->onecard->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->pushButton_3->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );

}

Register::~Register()
{
    delete ui;
}

void Register::setWineSql(WineSql *f)
{
    this->winesql=f;
}

void Register::on_zhucexinxitijaio_clicked()//注册信息
{
      Wine stru;

     stru.uid=ser->getOneUID();
     //stru.uid="110";

     stru.name=ui->zhonglei->currentText();
     stru.weight=ui->tizhong->text().toDouble();
     QDate date = ui->date->date();

    stru.birth=date;


    qDebug()<<stru.uid<<endl;
    qDebug()<<stru.name<<endl;
    qDebug()<<stru.weight<<endl;
    qDebug()<<stru.birth<<endl;
    qDebug()<<stru.sex<<endl;

    if(feedsql->addAnimal(stru)==true)
    {
        QMessageBox::information(this,"提示","插入成功");
    }
}

void zhuceForm::on_nan_clicked()//选择性别
{
     isdan=1;
}

void zhuceForm::on_nv_clicked()//选择性别
{
     isdan=2;
}

void zhuceForm::on_onecard_clicked()
{
    //BYTE sUID[8];//uid 为8位
    //DWORD tag=0;
   /*if(!Inventory(sUID,39,tag)){
        qDebug()<<"获取成功";
        qDebug()<<"it is"<<QByteArray((char *)sUID,8).toHex();//8位数据转为十六进制字符。
    }
    ui->uid->setText(QByteArray((char *)sUID,8).toHex());*/
    ui->uid->setText(ser->getOneUID());

}

void zhuceForm::on_pushButton_3_clicked()//重置按钮
{
       ui->tizhong->setText(" ");
       ui->uid->setText(" ");
}
