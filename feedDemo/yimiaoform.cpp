#include "yimiaoform.h"
#include "ui_yimiaoform.h"
#include <QMessageBox>

bool isNum(QString str){
    if(str=="")return false;
    const char* c=str.toLatin1().data();
    while(*c&&*c>='0'&&*c<='9')c++;
    if(*c)
        return true;
    else return false;
}

YiMiaoForm::YiMiaoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::YiMiaoForm)
{
    ui->setupUi(this);
    ui->clearButton->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->deleteButton->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->refreshButton->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->submitButton->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
}

YiMiaoForm::~YiMiaoForm()
{
    delete ui;
}

void YiMiaoForm::setFeedSql(FeedSql *f)
{
    this->feedSql=f;
}

void YiMiaoForm::on_clearButton_clicked()
{
    ui->vidEdit->setText("");
    ui->vnameEdit->setText("");
    ui->vtimeEdit->setText("");
    ui->vtextEdit->setText("");
    ui->relyEdit->setText("");
}

void YiMiaoForm::on_submitButton_clicked()
{
    VacInfo vac;
    if(isNum(ui->vtimeEdit->toPlainText())){
        QMessageBox::critical(0,QObject::tr("finish"),"接种时间未填或非整数！",QMessageBox::Cancel);
    }
    vac.vid=ui->vidEdit->toPlainText();//vid
    vac.name=ui->vnameEdit->toPlainText();//vname
    vac.relyon=ui->relyEdit->toPlainText();//relyon
    vac.text=ui->vtextEdit->toPlainText();//text
    vac.vtime=ui->vtimeEdit->toPlainText().toInt();//vtime
    if(feedSql->addVac(vac)){
        QMessageBox::critical(0,QObject::tr("finish"),"添加成功！",QMessageBox::Cancel);
        on_refreshButton_clicked();
    }
    else{
        QMessageBox::critical(0,QObject::tr("finish"),"添加失败！",QMessageBox::Cancel);
    }
}

void YiMiaoForm::on_refreshButton_clicked()
{
    //获取所有疫苗的列表
    this->allvList=feedSql->getAllVacInfos();
    //将listWidget清空
    ui->valistWidget->clear();

    //重新加载listView
    for(int i=0;i<allvList->size();i++)
        ui->valistWidget->addItem(QString("%1：%2").arg(allvList->at(i).vid)
                                  .arg(allvList->at(i).name));
    ui->vatTextBrowser->setText("");//清空信息
}

void YiMiaoForm::on_deleteButton_clicked()
{
    int index=ui->valistWidget->currentRow();
    if(index<0)return;

    if(feedSql->delVac(allvList->at(index).vid)){
         QMessageBox::critical(0,QObject::tr("finish"),"删除成功！",QMessageBox::Cancel);
         on_refreshButton_clicked();//刷新
    }
    else{
         QMessageBox::critical(0,QObject::tr("finish"),"删除失败！",QMessageBox::Cancel);
    }
}

void YiMiaoForm::on_valistWidget_clicked(const QModelIndex &index)
{
    int i=ui->valistWidget->currentRow();
    ui->vatTextBrowser->setText("");
    QString info="";
    info+= "疫苗编号："+allvList->at(i).vid+"\n";
    info+= "疫苗名称："+allvList->at(i).name+"\n";
    info+= "先行疫苗："+allvList->at(i).relyon+"\n";
    info+= QString("接种时间：%1").arg(allvList->at(i).vtime)+"\n";
    info+= "说   明："+allvList->at(i).text+"\n";
    ui->vatTextBrowser->append(info);
}
