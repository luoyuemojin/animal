#ifndef YIMIAOFORM_H
#define YIMIAOFORM_H

#include <QWidget>
#include <QDebug>
#include "winesql.h"
#include <QList>
namespace Ui {
class YiMiaoForm;
}

class YiMiaoForm : public QWidget
{
    Q_OBJECT

public:
    explicit YiMiaoForm(QWidget *parent = 0);
    ~YiMiaoForm();

private:
    Ui::YiMiaoForm *ui;

    FeedSql * feedSql;
    QList<VacInfo> * allvList=NULL;
public :
    void setFeedSql(FeedSql *f);
private slots:
    void on_clearButton_clicked();
    void on_submitButton_clicked();
    void on_refreshButton_clicked();
    void on_deleteButton_clicked();
    void on_valistWidget_clicked(const QModelIndex &index);
};

#endif // YIMIAOFORM_H
