#include "chakanform.h"
#include "ui_chakanform.h"

chakanForm::chakanForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chakanForm)
{
    ui->setupUi(this);
    ser = new SerialRfid;
    feeds = new FeedSql;
    feedsql = new FeedSql;
    ui->chakanxinxi->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );
    ui->deletexinxi->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

                                               "QPushButton:hover{background-color:white; color: #63B8FF;}"

                                              "QPushButton:pressed{background-color:red;border-style: inset; }"

                                               );

   ui->clear->setStyleSheet("QPushButton{background-color:#63B8FF;color: white;   border-radius: 10px;  border: 2px groove gray; border-style: outset;}"

    "QPushButton:hover{background-color:white; color: #63B8FF;}"

   "QPushButton:pressed{background-color:red;border-style: inset; }"

    );
  //  setFixedSize(1000,800);

}

chakanForm::~chakanForm()
{
    delete ui;
}

void chakanForm::setFeedSql(FeedSql *f)
{
    this->feedsql=f;
}

void chakanForm::on_chakanxinxi_clicked()
{
    AnimalInfo *lists=feedsql->getAnimalInfo(ser->getOneUID());
    //  AnimalInfo *lists=feedsql->getAnimalInfo("002");//检测

   AnimalInfo * ainfo=feedsql->getAnimalInfo(ser->getOneUID());
   if(ainfo==NULL){
         ui->xianshixinxi->insertPlainText("编号: ");
         ui->xianshixinxi->insertPlainText(ser->getOneUID());
         ui->xianshixinxi->insertPlainText(" 无此卡的任何信息,请先注册后再查询\n");
         QMessageBox::information(this,"提示","无此卡的信息");
    }else
   {
    ui->xianshixinxi->insertPlainText("第"+QString("%1").arg(i)+"次查询:\n");
    ui->xianshixinxi->insertPlainText("编号: ");
    ui->xianshixinxi->insertPlainText(lists->uid);
    ui->xianshixinxi->insertPlainText("\n");
    ui->xianshixinxi->insertPlainText("种类:");
    ui->xianshixinxi->insertPlainText(lists->name);
    ui->xianshixinxi->insertPlainText("\n");
    ui->xianshixinxi->insertPlainText("出生日期:");
    ui->xianshixinxi->insertPlainText(lists->birth.toString());
    ui->xianshixinxi->insertPlainText("\n");
    ui->xianshixinxi->insertPlainText("性别:");
    ui->xianshixinxi->insertPlainText(QString("%1").arg(lists->sex));
    ui->xianshixinxi->insertPlainText("\n");
    ui->xianshixinxi->insertPlainText("体重:");
    ui->xianshixinxi->insertPlainText(QString("%1").arg(lists->weight));
    ui->xianshixinxi->insertPlainText("\n");
    ui->xianshixinxi->insertPlainText("\n");
    i++;
   }
}

void chakanForm::on_deletexinxi_clicked()
{
    AnimalInfo * ainfo=feedsql->getAnimalInfo(ser->getOneUID());
    if(ainfo==NULL){
        ui->xianshixinxi->insertPlainText("编号: ");
        ui->xianshixinxi->insertPlainText(ser->getOneUID());
        ui->xianshixinxi->insertPlainText(" 无此卡的任何信息,无法删除\n");
        QMessageBox::information(this,"提示","无此卡的信息,无法删除");
    }
    else{
    ui->xianshixinxi->insertPlainText("编号: ");
    ui->xianshixinxi->insertPlainText(ser->getOneUID());
    ui->xianshixinxi->insertPlainText("  已被删除\n");
    feedsql->delAnimal(ser->getOneUID());
    QMessageBox::information(this,"提示","删除成功");
    }
}

void chakanForm::on_clear_clicked()
{
    ui->xianshixinxi->setText("");
    i=1;
}
