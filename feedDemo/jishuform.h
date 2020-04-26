#ifndef JISHUFORM_H
#define JISHUFORM_H

#include <QWidget>
#include "serialrfid.h"
#include "winesql.h"
namespace Ui {
class JishuForm;
}

class JishuForm : public QWidget
{
    Q_OBJECT

public:
    explicit JishuForm(QWidget *parent = 0);
    ~JishuForm();

private slots:
    void on_outCount_clicked();

    void on_inCount_clicked();

    void on_finishCount_clicked();

private:
    Ui::JishuForm *ui;
    SerialRfid *sf;

    bool isout;
};

#endif // JISHUFORM_H
