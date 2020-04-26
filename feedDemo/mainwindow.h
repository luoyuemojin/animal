#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QWidget>
#include <jiezhongform.h>
#include <yimiaoform.h>
#include "chuankouform.h"
#include "register.h"
#include "chakanform.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    FeedSql * f;
    QList<QAction *> *actionList;
    QList<QWidget *> *widgetList;
private:
    Ui::MainWindow *ui;
private slots:
    void actionSlot();



};

#endif // MAINWINDOW_H
