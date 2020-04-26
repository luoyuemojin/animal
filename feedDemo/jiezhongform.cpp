#include "jiezhongform.h"
#include "ui_jiezhongform.h"
#include <QLabel>
#include <QCheckBox>

JieZhongForm::JieZhongForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JieZhongForm)
{
    ui->setupUi(this);
    sr=new SerialRfid;
    gbox=new QVBoxLayout;
    clear();
    ui->searchButton->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );

    ui->getUidButton->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->submitButton->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );

}

JieZhongForm::~JieZhongForm()
{
    delete ui;
}

void JieZhongForm::clear()
{
    ui->atype->setText("");
    ui->weight->setText("");
    ui->age->setText("");
    while(gbox->count()!=0){

        QLayoutItem *x=gbox->itemAt(0);

        gbox->removeItem(x);
        delete x->widget();
        delete x;
    }//删除groupbox所有内容

    ui->groupBox->setLayout(gbox);
    ui->submitButton->setEnabled(false);//设置提交为不可用
}

void JieZhongForm::setFeedSql(FeedSql *f)
{
    this->feedsql=f;
}

void JieZhongForm::on_searchButton_clicked()
{
    //重置内容
    clear();

    //1.获取uid
    QString uid=ui->uidEdit->toPlainText();
   // qDebug()<<uid;
    if(uid==NULL) return;
    AnimalInfo * ainfo=feedsql->getAnimalInfo(uid);
   // AnimalInfo * ainfo=feedsql->getAnimalInfo("001");//测试

    if(ainfo==NULL){
        QMessageBox::critical(0,QObject::tr("Cannot find out the uid"),"该卡号不存在！",QMessageBox::Cancel
                              );
        return;
    }

    ui->atype->setText(ainfo->name);
    ui->age->setText(QString("%1").arg(QDate::currentDate().toJulianDay()-ainfo->birth.toJulianDay()));
    ui->weight->setText(QString("%1").arg(ainfo->weight));

    //2.查询数据,并记录



    vlist=feedsql->getNeedVacInfos(uid);

    //3.添加多选框，并显示在groupBox里

    if(vlist==NULL || vlist->size()==0){
        gbox->addWidget(new QLabel("没有找到需要打的疫苗！！！"));
        ui->groupBox->setLayout(gbox);

    }
    else{
        for(int i=0;i<vlist->count();i++){

            gbox->addWidget(new QCheckBox(vlist->at(i).name));  //添加所有查到的疫苗复选框
        }
        ui->groupBox->setLayout(gbox);
        ui->submitButton->setEnabled(true); //此时可以提交。
    }
    //查询完毕
}

void JieZhongForm::on_getUidButton_clicked()
{
    //寻卡,记录在文本框里
    QString uid=sr->getOneUID();
   // qDebug()<<uid;
    if(uid==NULL||uid==""){

        return;
    }
    else{

        ui->uidEdit->setText(uid);

        on_searchButton_clicked();//查询

    }
}

void JieZhongForm::on_submitButton_clicked()
{
    int all=0;
    int ok=0;
    //轮询groubox里的复选按钮，结合文本框进行写入提交。
    for(int i=0;i<gbox->count();i++){
        QCheckBox *c=(QCheckBox *)(gbox->itemAt(i)->widget());
        if(c->isChecked()){
           all++;
           if(feedsql->jiezhong(ui->uidEdit->toPlainText(),vlist->at(i).vid))
                ok++;
        }
    }
    QMessageBox::critical(0,QObject::tr("finish"),QString("选中%1个，%2 个写入成功 %3个写入失败").arg(all)
                          .arg(ok).arg(all-ok),QMessageBox::Cancel);

    //更新
    on_searchButton_clicked();

}
