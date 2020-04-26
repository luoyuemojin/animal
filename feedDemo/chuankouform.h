#ifndef CHUANKOUFORM_H
#define CHUANKOUFORM_H

#include <QWidget>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>
#include <QObject>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include "ReadDLL.h"
#include "serialrfid.h"
#include "feedsql.h"
#include "datastruct.h"
namespace Ui {
class chuankouForm;
}

class chuankouForm : public QWidget
{
    Q_OBJECT

public:
    explicit chuankouForm(QWidget *parent = 0);
    ~chuankouForm(); 
    SerialRfid *ser;
    QSerialPort *serial;
    FeedSql *feeds;
    int isdan;

private slots:
    void on_OpenSerialButton_clicked();

    void on_closeSerialButton_clicked();

private:
    Ui::chuankouForm *ui;
};

#endif // CHUANKOUFORM_H
