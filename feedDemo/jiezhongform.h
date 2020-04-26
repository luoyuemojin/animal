#ifndef JIEZHONGFORM_H
#define JIEZHONGFORM_H

#include <QWidget>
#include "feedsql.h"
#include "serialrfid.h"
#include <QVBoxLayout>
namespace Ui {
class JieZhongForm;
}

class JieZhongForm : public QWidget
{
    Q_OBJECT

public:
    explicit JieZhongForm(QWidget *parent = 0);
    ~JieZhongForm();

private:
    Ui::JieZhongForm *ui;
    SerialRfid * sr;
    FeedSql *feedsql;


    QList<VacInfo> * vlist=NULL;//存储该打的疫苗
    QVBoxLayout * gbox;
private:
    void clear();
public :
    void setFeedSql( FeedSql *f);
private slots:
    void on_searchButton_clicked();
    void on_getUidButton_clicked();
    void on_submitButton_clicked();
};

#endif // JIEZHONGFORM_H
