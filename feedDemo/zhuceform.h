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
#include "feedsql.h"
#include "datastruct.h"
namespace Ui {
class zhuceForm;
}

class zhuceForm : public QWidget
{
    Q_OBJECT

public:
    explicit zhuceForm(QWidget *parent = 0);
    ~zhuceForm();
    FeedSql *feedsql;
    void setFeedSql( FeedSql *f);
    SerialRfid *ser;
    QSerialPort *serial;
    FeedSql *feeds;
    int isdan;
private slots:
    void on_zhucexinxitijaio_clicked();

    void on_nan_clicked();

    void on_nv_clicked();

    void on_onecard_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::zhuceForm *ui;
};

#endif // ZHUCEFORM_H
