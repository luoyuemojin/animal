#ifndef CHAKANFORM_H
#define CHAKANFORM_H

#include <QWidget>
#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGroupBox>
#include <QMessageBox>
#include <QSqlQuery>
#include <QtSql>
#include <QObject>
#include "ReadDLL.h"
#include "serialrfid.h"
#include "winesql.h"
#include "datastruct.h"
namespace Ui {
class chakanForm;
}

class chakanForm : public QWidget
{
    Q_OBJECT

public:
    explicit chakanForm(QWidget *parent = 0);
    ~chakanForm();
   FeedSql *feedsql;
   void setFeedSql( FeedSql *f);
    SerialRfid *ser;
    QSerialPort *serial;
    FeedSql *feeds;
    int isdan;
    int i=1;
private slots:
    void on_chakanxinxi_clicked();

    void on_deletexinxi_clicked();

    void on_clear_clicked();

private:
    Ui::chakanForm *ui;
};

#endif // CHAKANFORM_H
