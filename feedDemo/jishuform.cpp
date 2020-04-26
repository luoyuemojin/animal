#include "jishuform.h"
#include "ui_jishuform.h"

JishuForm::JishuForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JishuForm)
{
    ui->setupUi(this);
    sf= new SerialRfid;
    ui->inCount->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->outCount->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->finishCount->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
}

JishuForm::~JishuForm()
{
    delete ui;
}

void JishuForm::on_outCount_clicked()
{
    isout=true;
    ui->inCount->setDisabled(true);
    ui->finishCount->setEnabled(true);
    ui->outCount->setText("统计中");
    sf->startSelfMotion();
}

void JishuForm::on_inCount_clicked()
{
    ui->outCount->setDisabled(true);
    ui->finishCount->setEnabled(true);
    isout=false;
    ui->inCount->setText("统计中");
    sf->startSelfMotion();
}

void JishuForm::on_finishCount_clicked()
{
    ui->finishCount->setDisabled(true);
    ui->inCount->setEnabled(true);
    ui->outCount->setEnabled(true);
     ui->inCount->setText("入圈计数");
      ui->outCount->setText("出圈计数");
    sf->closeSelfMotion();

    QString uidstring="";

    QList<QString> *uidList=sf->getUidList();
    for(int i=0;i<uidList->size();i++){
        uidstring+=uidList->at(i)+"\n";
    }
    ui->showUid->setText(uidstring);
    if(isout){
        ui->outnum->setText(QString("%1").arg(uidList->size()));
    }
    else{
        ui->innum->setText(QString("%1").arg(uidList->size()));
    }

    sf->clear();
}
