#ifndef ZHUCEFORM_H
#define ZHUCEFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>
#include <QObject>
#include "ReadDLL.h"
#include "serialrfid.h"
#include "winesql.h"
#include "datastruct.h"
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    WineSql *winesql;
    void setWineSql( WineSql *f);
    SerialRfid *ser;
    QSerialPort *serial;
    WineSql *wines;
    int isdan;
private slots:
    void on_zhucexinxitijaio_clicked();

    void on_onecard_clicked();

    void on_pushButton_3_clicked();

private:
    //Ui::register *ui;
};

#endif // ZHUCEFORM_H
